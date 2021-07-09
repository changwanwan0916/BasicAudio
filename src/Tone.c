/*
 * Tone.c
 *
 *  Created on: 2021Äê7ÔÂ8ÈÕ
 *      Author: Brisonus-DELL
 */


#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include <string.h>
#include<math.h>
#include<filter.h>

#include"BasicAudioTest.h"
#include"Tone.h"
#include"Filter.h"

extern Audio_Block ab_Tone;

extern Audio_Gobal_Config Filter_Global;

extern Filter Filter_LowShelf;
extern Filter Filter_Peaking;
extern Filter Filter_HighShelf;

static Filter_Init_Config **Bass_Con_Inter;
static Filter_Init_Config **Mid_Con_Inter;
static Filter_Init_Config **Tre_Con_Inter;

static Filter_Run_Config  Tone_Run_Config;

static uint32_t Bass_Init_Func(void)
{
	Filter_Init_Config **Bass_Con_Temp = (Filter_Init_Config**)malloc(Filter_Global.Input_ChNum*sizeof(Filter_Init_Config*));

	for(uint32_t Bass_Loop = 0; Bass_Loop < Filter_Global.Input_ChNum; Bass_Loop++)
	{
		Bass_Con_Temp[Bass_Loop] = (Filter_Init_Config*)malloc(sizeof(Filter_Init_Config));

		Bass_Con_Temp[Bass_Loop]->Freq = 300;
		Bass_Con_Temp[Bass_Loop]->Gain = 12;
		Bass_Con_Temp[Bass_Loop]->q = 0.707;
	}

	Bass_Con_Inter = Bass_Con_Temp;
	return 0;
}

static uint32_t Mid_Init_Func(void)
{
	Filter_Init_Config **Mid_Con_Temp = (Filter_Init_Config**)malloc(Filter_Global.Input_ChNum*sizeof(Filter_Init_Config*));

	for(uint32_t Mid_Loop = 0; Mid_Loop < Filter_Global.Input_ChNum; Mid_Loop ++)
	{

		Mid_Con_Temp[Mid_Loop] = (Filter_Init_Config*)malloc(sizeof(Filter_Init_Config));

		Mid_Con_Temp[Mid_Loop]->Freq = 1000;
		Mid_Con_Temp[Mid_Loop]->Gain = 12;
		Mid_Con_Temp[Mid_Loop]->q = 0.707;
	}

	Mid_Con_Inter = Mid_Con_Temp;
	return 0;
}

static void Tre_Init_Func(void)
{

	Filter_Init_Config **Tre_Con_Temp = (Filter_Init_Config**)malloc(Filter_Global.Input_ChNum*sizeof(Filter_Init_Config*));

	for(uint32_t Tre_Loop = 0; Tre_Loop < Filter_Global.Input_ChNum; Tre_Loop ++)
	{
		Tre_Con_Temp[Tre_Loop] = (Filter_Init_Config*)malloc(sizeof(Filter_Init_Config));

		Tre_Con_Temp[Tre_Loop]->Freq = 5000;
		Tre_Con_Temp[Tre_Loop]->Gain = 12;
		Tre_Con_Temp[Tre_Loop]->q = 0.707;
	}

	Tre_Con_Inter = Tre_Con_Temp;

}

static void Tone_Init_Func()
{
	Bass_Init_Func();
	Mid_Init_Func();
	Tre_Init_Func();
}

static void Tone_Set_Func(void *Tone_Con_Setting, void *Tone_Control1)
{
	Audio_Config* cf = (Audio_Config*) Tone_Con_Setting;

	switch(cf->which)
	{
		case GLOBAL:
		{
			Audio_Gobal_Config *Glo_Temp = (Audio_Gobal_Config *)cf->Config;
			Set_Audio_Global(Glo_Temp->Block_Size,
							 Glo_Temp->Sample_Rate,
							 Glo_Temp->Input_ChNum,
							 &Filter_Global);

			for(uint32_t Global_Loop = 0; Global_Loop < Filter_Global.Input_ChNum; Global_Loop)
			{
				Filter_LowShelf.Func(&Tone_Run_Config, Bass_Con_Inter[Global_Loop]);
				Filter_Peaking.Func(&Tone_Run_Config, Mid_Con_Inter[Global_Loop]);
				Filter_HighShelf.Func(&Tone_Run_Config, Tre_Con_Inter[Global_Loop]);
				void State_Init_Func();
			}
			break;
		}

		case ALGORITHM:
		{

			Tone_Control_Type* Tone_Control = (Tone_Control_Type*)Tone_Control1;
			Filter_Init_Config *Algo_Tone_Temp = (Filter_Init_Config *)cf->Config;

			for(uint32_t ChNum_Loop = 0; ChNum_Loop < Filter_Global.Input_ChNum; ChNum_Loop++)
			{
				switch(Tone_Control->Control)
				{
					case BASS:
					{
						Set_Filter_ConfigFunc(Algo_Tone_Temp->Freq,
								              Algo_Tone_Temp->Gain,
											  Algo_Tone_Temp->q,
											  Filter_LowShelf.Filter_Config);
						Filter_LowShelf.Func(&Tone_Run_Config, Bass_Con_Inter[ChNum_Loop]);
						State_Init_Func();
						break;
					}
					case MIDDLE:
					{
						Set_Filter_ConfigFunc(Algo_Tone_Temp->Freq,
											  Algo_Tone_Temp->Gain,
											  Algo_Tone_Temp->q,
											  Filter_Peaking.Filter_Config);
						Filter_Peaking.Func(&Tone_Run_Config, Mid_Con_Inter[ChNum_Loop]);
						State_Init_Func();
						break;
					}
					case TREBLE:
					{
						Set_Filter_ConfigFunc(Algo_Tone_Temp->Freq,
										      Algo_Tone_Temp->Gain,
											  Algo_Tone_Temp->q,
											  Filter_HighShelf.Filter_Config);
						Filter_HighShelf.Func(&Tone_Run_Config, Tre_Con_Inter[ChNum_Loop]);
						State_Init_Func();
						break;
					}
					default:break;
				}
			}
		}

	}
}


static void Tone_Func(float *Output[Filter_Global.Input_ChNum], float *Input[Filter_Global.Input_ChNum])
{
	float Bass_Output[Filter_Global.Input_ChNum][Filter_Global.Block_Size];
	float Mid_Output[Filter_Global.Input_ChNum][Filter_Global.Block_Size];
	float Tre_Output[Filter_Global.Input_ChNum][Filter_Global.Block_Size];

	for(uint32_t ChNum_Loop = 0; ChNum_Loop < Filter_Global.Input_ChNum; ChNum_Loop ++)
	{
		Filter_LowShelf.Func(&Tone_Run_Config, Bass_Con_Inter[ChNum_Loop]);
		Biquad_Func(Bass_Output[ChNum_Loop],Input[ChNum_Loop],&Tone_Run_Config);

		Filter_Peaking.Func(&Tone_Run_Config, Mid_Con_Inter[ChNum_Loop]);
		Biquad_Func(Mid_Output[ChNum_Loop],Input[ChNum_Loop],&Tone_Run_Config);

		Filter_HighShelf.Func(&Tone_Run_Config, Tre_Con_Inter[ChNum_Loop]);
		Biquad_Func(Tre_Output[ChNum_Loop],Input[ChNum_Loop],&Tone_Run_Config);

		for(uint32_t Block_Loop = 0; Block_Loop < Filter_Global.Block_Size; Block_Loop ++)
		{
			Output[ChNum_Loop][Block_Loop] =  (Bass_Output[ChNum_Loop][Block_Loop] +
					                           Mid_Output[ChNum_Loop][Block_Loop] +
											   Tre_Output[ChNum_Loop][Block_Loop])/3;
		}
	}
}

Audio_Block ab_Tone =
{
		.Config = "Tone",

		.Config = &Tone_Init_Func,
		.Init = Tone_Init_Func,
		.Set = Tone_Set_Func,
		.Func = Tone_Func
};
