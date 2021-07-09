/*
 * Filter.c
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
#include"Filter.h"

extern Audio_Gobal_Config Filter_Global;

extern Filter Filter_LowShelf;
extern Filter Filter_Peaking;
extern Filter Filter_HighShelf;

static Filter_Run_Config Run_Config;
static Filter_Init_Config Init_Config;

static Biqud_Init_Config Biquad_Para;

static void ShelfVar_Func(Filter_Vari* ShelfVar,Filter_Init_Config* Init_Config);
static void PeakVar_Func(Filter_Vari* PeakVar,Filter_Init_Config* Init_Config);

static void LowShelf_Func(Filter_Run_Config * LowShelf_Run_Config, Filter_Init_Config *LowShelf_Init_Conf);
static void HigShelf_Func(Filter_Run_Config * HigShelf_Run_Config, Filter_Init_Config *HigShelf_Init_Conf);
static void Peaking_Func(Filter_Run_Config * Peaking_Run_Config, Filter_Init_Config *Peaking_Init_Conf);

//void State_Init_Func(void);
static void Coeff_Init_Func(Filter_Run_Config *Biquad_Run);

Audio_Gobal_Config Filter_Global =
{
	.Block_Size = 24,
	.Sample_Rate = 48000,
	.Input_ChNum = 2,
	.Output_ChNum = 2
};

static Filter_Init_Config Fiter_Set_Con;

static void LowShelf_Func(Filter_Run_Config* LowShelf_Run_Config, Filter_Init_Config* LowShelf_Init_Conf)
{
	Filter_Vari LowShelfVar;
	ShelfVar_Func(&LowShelfVar, LowShelf_Init_Conf);

	LowShelf_Run_Config->Coeff = 4 + LowShelfVar.ShelfVar5 + LowShelfVar.ShelfVar6;

	LowShelf_Run_Config->Den[0] = 1;
	LowShelf_Run_Config->Den[1] = (2 * LowShelfVar.ShelfVar6 - 8)/ LowShelf_Run_Config->Coeff;
	LowShelf_Run_Config->Den[2] = (4 + LowShelfVar.ShelfVar6 - LowShelfVar.ShelfVar5)/ LowShelf_Run_Config->Coeff;

	LowShelf_Run_Config->Num[0] = (4 + LowShelfVar.ShelfVar3 + LowShelfVar.ShelfVar4)/LowShelf_Run_Config->Coeff;
	LowShelf_Run_Config->Num[1] = (2 * LowShelfVar.ShelfVar4 - 8)/ LowShelf_Run_Config->Coeff;
	LowShelf_Run_Config->Num[2] = (4 + LowShelfVar.ShelfVar4 - LowShelfVar.ShelfVar3)/ LowShelf_Run_Config->Coeff;

}

static void HigShelf_Func(Filter_Run_Config * HigShelf_Run_Config, Filter_Init_Config *HigShelf_Init_Conf)
{
	Filter_Vari HigShelfVar;

	float G;
	HigShelf_Init_Conf->Gain = -HigShelf_Init_Conf->Gain;
    ShelfVar_Func(&HigShelfVar, HigShelf_Init_Conf);

    G = powf(10, HigShelf_Init_Conf->Gain/20);

    HigShelf_Run_Config->Coeff = G * (4 + HigShelfVar.ShelfVar5 + HigShelfVar.ShelfVar6);

    HigShelf_Run_Config->Den[0] = 1;
    HigShelf_Run_Config->Den[1] = (G * (2 * HigShelfVar.ShelfVar6 - 8))/ HigShelf_Run_Config->Coeff;
    HigShelf_Run_Config->Den[2] = (G * (4 + HigShelfVar.ShelfVar6 - HigShelfVar.ShelfVar5)) / HigShelf_Run_Config->Coeff;

    HigShelf_Run_Config->Num[0] = (4 + HigShelfVar.ShelfVar3 + HigShelfVar.ShelfVar4)/HigShelf_Run_Config->Coeff;
    HigShelf_Run_Config->Num[1] = (2 * HigShelfVar.ShelfVar4 - 8)/ HigShelf_Run_Config->Coeff;
    HigShelf_Run_Config->Num[2] = (4 + HigShelfVar.ShelfVar4 - HigShelfVar.ShelfVar3)/ HigShelf_Run_Config->Coeff;

}

static void Peaking_Func(Filter_Run_Config * Peaking_Run_Config, Filter_Init_Config *Peaking_Init_Conf)
{
	Filter_Vari PeakingVar;
	PeakVar_Func(&PeakingVar, Peaking_Init_Conf);

	Peaking_Run_Config->Coeff = 4 + PeakingVar.PeakVar4 + PeakingVar.PeakVar5;

	Peaking_Run_Config->Den[0] = 1;
	Peaking_Run_Config->Den[1] = (2 * PeakingVar.PeakVar5 - 8)/Peaking_Run_Config->Coeff;
	Peaking_Run_Config->Den[2] = (4 + PeakingVar.PeakVar5 - PeakingVar.PeakVar4)/Peaking_Run_Config->Coeff;

	Peaking_Run_Config->Num[0] = (4 + PeakingVar.PeakVar3 + PeakingVar.PeakVar5)/Peaking_Run_Config->Coeff;
	Peaking_Run_Config->Num[1] = Peaking_Run_Config->Den[1];
	Peaking_Run_Config->Num[2] = (4 + PeakingVar.PeakVar5 - PeakingVar.PeakVar3)/Peaking_Run_Config->Coeff;
}


Filter Filter_LowShelf = {
	   .Filter_Name = "Bass Shelving",
	   .Filter_Config = &Fiter_Set_Con,
	   .Func = LowShelf_Func
};

Filter Filter_Peaking = {
	   .Filter_Name = "peak,Dip",
	   .Filter_Config = &Fiter_Set_Con,
	   .Func = Peaking_Func
};

Filter Filter_HighShelf = {
	   .Filter_Name = "Treble Shelving",
	   .Filter_Config = &Fiter_Set_Con,
	   .Func = HigShelf_Func
};

void State_Init_Func(void)
{
	for(uint32_t State_Loop = 0; State_Loop < 2 * FILTERSECTION; State_Loop++)
	{
		Biquad_Para.Filter_State[State_Loop] = 0;
	}
}

static void Coeff_Init_Func(Filter_Run_Config *Biquad_Run)
{
	for(uint32_t Coeff_Loop = 0; Coeff_Loop < 5 * FILTERSECTION; Coeff_Loop ++)
	{
		Biquad_Para.Filter_Coeff[0] = -Biquad_Run->Den[2];
		Biquad_Para.Filter_Coeff[1] = -Biquad_Run->Den[1];

		Biquad_Para.Filter_Coeff[2] = Biquad_Run->Num[2];
		Biquad_Para.Filter_Coeff[3] = Biquad_Run->Num[1];
		Biquad_Para.Filter_Coeff[4] = Biquad_Run->Num[0];
	}
}

void Biquad_Func(float Output[], float Input[], Filter_Run_Config *Filter_Run_Data)
{

	State_Init_Func();
	Coeff_Init_Func(Filter_Run_Data);

	biquad(Input,
		   Output,
		   Biquad_Para.Filter_Coeff,
		   Biquad_Para.Filter_State,
		   Filter_Global.Block_Size,
		   FILTERSECTION);
}

static void ShelfVar_Func(Filter_Vari* ShelfVar,Filter_Init_Config* Init_Config)
{
	ShelfVar->Omega = 2 * PI * Init_Config->Freq;
	ShelfVar->Sample_Time = (float)1 / (float)Filter_Global.Sample_Rate;

	ShelfVar->ShelfVar1 = ShelfVar->Omega * powf(10, Init_Config->Gain/80);            //Omega1
	ShelfVar->ShelfVar2 = ShelfVar->Omega / (powf(10, Init_Config->Gain/80));          //Omega2

	ShelfVar->ShelfVar3 = 2 * ShelfVar->ShelfVar1 * ShelfVar->Sample_Time / Init_Config->q;
	ShelfVar->ShelfVar4 = powf(ShelfVar->ShelfVar1, 2) * powf(ShelfVar->Sample_Time, 2);

	ShelfVar->ShelfVar5 = 2 * ShelfVar->ShelfVar2 * ShelfVar->Sample_Time / Init_Config->q;
	ShelfVar->ShelfVar6 = powf(ShelfVar->ShelfVar2, 2) * powf(ShelfVar->Sample_Time, 2);

}


static void PeakVar_Func(Filter_Vari* PeakVar,Filter_Init_Config* Init_Config)
{
	PeakVar->Omega = 2 * PI * Init_Config->Freq;
	PeakVar->Sample_Time = (float)1 / (float)Filter_Global.Sample_Rate;

	PeakVar->PeakVar1 = Init_Config->q / powf(10, Init_Config->Gain/40);
	PeakVar->PeakVar2 = Init_Config->q * powf(10, Init_Config->Gain/40);

	PeakVar->PeakVar3 = 2 * PeakVar->Omega * PeakVar->Sample_Time / PeakVar->PeakVar1;
	PeakVar->PeakVar4 = 2 * PeakVar->Omega * PeakVar->Sample_Time / PeakVar->PeakVar2;

	PeakVar->PeakVar5 = powf(PeakVar->Omega, 2) * powf(PeakVar->Sample_Time, 2);
}



