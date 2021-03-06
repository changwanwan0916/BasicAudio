/*
 * Limiter.c
 *
 *  Created on: 2021年7月4日
 *      Author: Brisonus-DELL
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include <string.h>
#include<math.h>

#include"BasicAudioTest.h"
#include"Limiter.h"

extern Audio_Block ab_Limiter;


static Audio_Gobal_Config Limiter_Global =
{
	.Block_Size = 24,
	.Sample_Rate = 48000,
	.Input_ChNum = 2,  //程序启动后不能修改
	.Output_ChNum = 2
};

//static Limiter_Config Con_Init[Limiter_Global.Block_Size];
//static Limiter_RunTime Run_Init;


static Algo_Limiter Algo_Lim_Con;  // Memory apl

static float *gS; // Temp data


static int32_t Lim_Con_Init(Algo_Limiter* Limiter)
{
	Limiter_Config **Lim_Con_Temp = (Limiter_Config**)malloc(Limiter_Global.Input_ChNum*sizeof(Limiter_Config*));

	for(uint32_t Init_Loop = 0; Init_Loop < Limiter_Global.Input_ChNum; Init_Loop++)
	{

		Lim_Con_Temp[Init_Loop] = (Limiter_Config*)malloc(sizeof(Limiter_Config));

		Lim_Con_Temp[Init_Loop]->Attack_Time = 0.005;
		Lim_Con_Temp[Init_Loop]->Release_Time = 0.1;
		Lim_Con_Temp[Init_Loop]->Treshold = -10;
	}

	Limiter->Lim_Config = Lim_Con_Temp;

	return 0;

}

static int32_t Lim_Run_Init(Algo_Limiter* Limiter)
{
	Limiter_RunTime** Run_Init_Temp =  (Limiter_RunTime**)malloc(Limiter_Global.Input_ChNum*sizeof(Limiter_RunTime*));

	float expNum = -logf(9);

	for(uint32_t Run_Loop = 0; Run_Loop < Limiter_Global.Input_ChNum; Run_Loop++)
	{
		Run_Init_Temp[Run_Loop] = (Limiter_RunTime*)malloc(sizeof(Limiter_RunTime)) ;

		Run_Init_Temp[Run_Loop]->aA = expf(expNum / (Limiter_Global.Sample_Rate * Algo_Lim_Con.Lim_Config[Run_Loop]->Attack_Time));
		Run_Init_Temp[Run_Loop]->aR = expf(expNum / (Limiter_Global.Sample_Rate * Algo_Lim_Con.Lim_Config[Run_Loop]->Release_Time));

	}

	Limiter->Lim_RunTime = Run_Init_Temp;

	gS = (float*)malloc(Limiter_Global.Input_ChNum * sizeof(float));

	memset(gS, 0, Limiter_Global.Input_ChNum*sizeof(float));

	return 0;

}


static void Lim_Init_Func()
{
	Lim_Con_Init(&Algo_Lim_Con);
	Lim_Run_Init(&Algo_Lim_Con);

}

static int32_t Lim_Run_Reset(Algo_Limiter *Limiter)
{
	float expNum = -logf(9);

	for(uint32_t Run_Loop = 0; Run_Loop < Limiter_Global.Input_ChNum; Run_Loop++)
	{

		Limiter->Lim_RunTime[Run_Loop]->aA = expf(expNum / (Limiter_Global.Sample_Rate * Algo_Lim_Con.Lim_Config[Run_Loop]->Attack_Time));
		Limiter->Lim_RunTime[Run_Loop]->aR = expf(expNum / (Limiter_Global.Sample_Rate * Algo_Lim_Con.Lim_Config[Run_Loop]->Release_Time));

	}

	memset(gS, 0, Limiter_Global.Input_ChNum*sizeof(float));

	return 0;

}


static void Lim_Set_Func(void* ConData, void* rr)
{
	Audio_Config* cf = (Audio_Config*) ConData;

	switch(cf->which)
	{
		case GLOBAL:
		{
			Audio_Gobal_Config *Glo_Temp = (Audio_Gobal_Config *)cf->Config;
			Set_Audio_Global(Glo_Temp->Block_Size,
					         Glo_Temp->Sample_Rate,
							 Glo_Temp->Input_ChNum,
							 &Limiter_Global);

			Lim_Run_Reset(&Algo_Lim_Con);

			break;
		}
		case ALGORITHM:
		{

			Algo_Limiter *Algo_Limiter_Temp = (Algo_Limiter *)cf->Config;

			for(uint32_t Con_Set_Loop = 0; Con_Set_Loop < Limiter_Global.Input_ChNum; Con_Set_Loop++)
			{
				Set_Limiter_Config(Algo_Limiter_Temp->Lim_Config[Con_Set_Loop]->Attack_Time,
									Algo_Limiter_Temp->Lim_Config[Con_Set_Loop]->Release_Time,
									Algo_Limiter_Temp->Lim_Config[Con_Set_Loop]->Treshold,
									Algo_Lim_Con.Lim_Config[Con_Set_Loop]);
			}


			Lim_Run_Reset(&Algo_Lim_Con);


			break;
		}

		default:
		{
			break;
		}

	}
}


static void Lim_Func(float *Output[Limiter_Global.Output_ChNum], float *Input[Limiter_Global.Input_ChNum], MODE rr)
{

	float xdB,xSc,gC,gLin;

	for(uint32_t ChNum_Loop = 0; ChNum_Loop < Limiter_Global.Input_ChNum; ChNum_Loop++)
	{
		for(uint32_t Block_Loop = 0; Block_Loop < Limiter_Global.Block_Size; Block_Loop ++)
		{

			xdB = 20 * log10f(fabs(Input[ChNum_Loop][Block_Loop]));


			if(xdB > Algo_Lim_Con.Lim_Config[ChNum_Loop]->Treshold)
			{
				xSc = Algo_Lim_Con.Lim_Config[ChNum_Loop]->Treshold;
			}
			else
			{
				xSc = xdB;
			}

			gC = xSc - xdB;


			if(gS[ChNum_Loop] > gC)
			{
				gS[ChNum_Loop] = Algo_Lim_Con.Lim_RunTime[ChNum_Loop]->aA * gS[ChNum_Loop]
										+ (1 - Algo_Lim_Con.Lim_RunTime[ChNum_Loop]->aA) * gC;
			}
			else
			{
				gS[ChNum_Loop] = Algo_Lim_Con.Lim_RunTime[ChNum_Loop]->aR * gS[ChNum_Loop]
										+ (1 - Algo_Lim_Con.Lim_RunTime[ChNum_Loop]->aR) * gC;
			}

			gLin = powf(10, gS[ChNum_Loop]/20);

			Output[ChNum_Loop][Block_Loop] = gLin * Input[ChNum_Loop][Block_Loop];
		}
	}

}


Audio_Block ab_Limiter =
{
	.Name = "Limiter",
	.Config = &Algo_Lim_Con,

	.Init = Lim_Init_Func,
	.Set = Lim_Set_Func,
	.Func = Lim_Func
};


/*static FreeMemory(){


//	free();

}*/


