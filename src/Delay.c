/*
 * Delay.c
 *
 *  Created on: 
 *      Author: Brisonus-DELL
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include <string.h>
#include<math.h>

#include"BasicAudioTest.h"
#include"Delay.h"

static Audio_Gobal_Config Delay_Global =
{
	.Block_Size = 24,
	.Sample_Rate = 48000,
	.Input_ChNum = 2,  
	.Output_ChNum = 2
};

static Algo_Delay Algo_Con;  // Memory apl

static int32_t Del_Con_Init(Algo_Delay* Delay)
{
	Delay_Config **Del_Con_Temp = (Delay_Config**)malloc(Delay_Global.Input_ChNum*sizeof(Delay_Config*));

	for(uint32_t Init_Loop = 0; Init_Loop < Delay_Global.Input_ChNum; Init_Loop++)
	{
		Del_Con_Temp[Init_Loop] = (Delay_Config*)malloc(sizeof(Delay_Config));
//		Del_Con_Temp[Init_Loop]->delayTime = 20;
	}
	Del_Con_Temp[0]->delayTime = 10;
	Del_Con_Temp[1]->delayTime = 20;

	Delay->Del_Config = Del_Con_Temp;

	return 0;
}

static int32_t Del_Run_Init(Algo_Delay* Delay)
{
	Delay_RunTime** Del_Run_Temp =  (Delay_RunTime**)malloc(Delay_Global.Input_ChNum*sizeof(Delay_RunTime*));
	float **rbuffer_add = (float**)malloc(Delay_Global.Input_ChNum*sizeof(float*));

	for(uint32_t Run_Loop = 0; Run_Loop < Delay_Global.Input_ChNum; Run_Loop++)
	{
		Del_Run_Temp[Run_Loop] = (Delay_RunTime*)malloc(sizeof(Delay_RunTime));

		Del_Run_Temp[Run_Loop]->delaySize = Delay->Del_Config[Run_Loop]->delayTime/1000*(float)Delay_Global.Sample_Rate;

		if(Del_Run_Temp[Run_Loop]->delaySize!=0){
			rbuffer_add[Run_Loop] = (float*)malloc(Del_Run_Temp[Run_Loop]->delaySize * sizeof(float));
			memset(rbuffer_add[Run_Loop], 0, Del_Run_Temp[Run_Loop]->delaySize*sizeof(float));
		}

		Del_Run_Temp[Run_Loop]->RbufferAdd = rbuffer_add;
		Del_Run_Temp[Run_Loop]->WriteNum = 0;
	}

	Delay->Del_RunTime = Del_Run_Temp;

	return 0;
}

static void Del_InitFunc()
{
	Del_Con_Init(&Algo_Con);
	Del_Run_Init(&Algo_Con);
}

static int32_t Del_Run_Reset(Algo_Delay *Delay)
{
	for(uint32_t Run_Loop = 0; Run_Loop < Delay_Global.Input_ChNum; Run_Loop++)
	{
		free(Delay->Del_RunTime[Run_Loop]->RbufferAdd[Run_Loop]);

		Delay->Del_RunTime[Run_Loop]->delaySize = Delay->Del_Config[Run_Loop]->delayTime/1000*(float)Delay_Global.Sample_Rate;

		if(Delay->Del_RunTime[Run_Loop]->delaySize!=0){
			Delay->Del_RunTime[Run_Loop]->RbufferAdd[Run_Loop] = (float*)malloc(Delay->Del_RunTime[Run_Loop]->delaySize * sizeof(float));
			memset(Delay->Del_RunTime[Run_Loop]->RbufferAdd[Run_Loop], 0, Delay->Del_RunTime[Run_Loop]->delaySize*sizeof(float));
		}
	}

	return 0;
}

static void Del_SetFunc(void* ConData, void* rr)
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
							 &Delay_Global);
			Del_Run_Reset(&Algo_Con);
			break;
		}
		case ALGORITHM:
		{
			Algo_Delay *Algo_Delay_Temp = (Algo_Delay *)cf->Config;

			for(uint32_t Con_Set_Loop = 0; Con_Set_Loop < Delay_Global.Input_ChNum; Con_Set_Loop++)
			{
				Set_Delay_Config(Algo_Delay_Temp->Del_Config[Con_Set_Loop]->delayTime,
								Algo_Con.Del_Config[Con_Set_Loop]);
			}
			Del_Run_Reset(&Algo_Con);	
			break;
		}

		default:
		{
			break;
		}
	}
}

static void Del_Func(float *Output[Delay_Global.Input_ChNum], float *Input[Delay_Global.Input_ChNum], MODE rr)
{
	for(uint32_t Del_ChNun = 0; Del_ChNun < Delay_Global.Input_ChNum; Del_ChNun++){

		for(int32_t DelayLoop = 0; DelayLoop < Delay_Global.Block_Size; DelayLoop++)
		{
			if(Algo_Con.Del_RunTime[Del_ChNun]->delaySize!=0){
				Output[Del_ChNun][DelayLoop] = *(*(Algo_Con.Del_RunTime[Del_ChNun]->RbufferAdd +  Del_ChNun)+ Algo_Con.Del_RunTime[Del_ChNun]->WriteNum);
				*(*(Algo_Con.Del_RunTime[Del_ChNun]->RbufferAdd +  Del_ChNun)+ Algo_Con.Del_RunTime[Del_ChNun]->WriteNum) = Input[Del_ChNun][DelayLoop];

				Algo_Con.Del_RunTime[Del_ChNun]->WriteNum++;

				if(Algo_Con.Del_RunTime[Del_ChNun]->WriteNum >= Algo_Con.Del_RunTime[Del_ChNun]->delaySize){
					Algo_Con.Del_RunTime[Del_ChNun]->WriteNum = 0;
				}
			}else{
				Output[Del_ChNun][DelayLoop] = Input[Del_ChNun][DelayLoop];
			}
		}
	}
}

Audio_Block ab_delay =
{
	.Name = "Delay",
	.Config = &Algo_Con,

	.Init = Del_InitFunc,
	.Set = Del_SetFunc,
	.Func = Del_Func
};

/*
static FreeMemory(){


//	free();

}
*/
