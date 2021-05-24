/*
 * Filter.c
 *
 *  Created on: 2021��5��18��
 *      Author: Brisonus-DELL
 */

#include<stdint.h>
#include<stdio.h>
#include<math.h>
#include<filter.h>

#include"Filter.h"
#include"BasicAudioTest.h"



/*First Order Low Pass Filter*/
void FisOrdLowPassFunc(BasicAudio_FilterPara *FisOrdLowPassPara)
{
	float Omega, Coeff;

	Omega = 2 * PI * FisOrdLowPassPara->Freq;
	Coeff = Omega * SAMPLE_TIME + 2;

	FisOrdLowPassPara->Den[0] = 1;
	FisOrdLowPassPara->Den[1] = (Omega * SAMPLE_TIME - 2)/Coeff;
	FisOrdLowPassPara->Den[2] = 0;

	FisOrdLowPassPara->Num[0] = (Omega * SAMPLE_TIME)/Coeff;
	FisOrdLowPassPara->Num[1] = FisOrdLowPassPara->Num[0];
	FisOrdLowPassPara->Num[2] = 0;
}

/* Second Order Low Pass Filter */
void SecOrdLowPassFunc(BasicAudio_FilterPara *SecOrdLowPassPara)
{
	float Omega, Coeff;;

	Omega = 2 * PI * SecOrdLowPassPara->Freq;
	Coeff = 4 * SecOrdLowPassPara->DampRate + 2 * Omega * SAMPLE_TIME + SecOrdLowPassPara->DampRate * pow(Omega, 2) * pow(SAMPLE_TIME, 2);


	SecOrdLowPassPara->Den[0] = 1;
	SecOrdLowPassPara->Den[1] = (2 * SecOrdLowPassPara->DampRate * pow(Omega, 2) * pow(SAMPLE_TIME, 2) - 8 * SecOrdLowPassPara->DampRate) / Coeff;
	SecOrdLowPassPara->Den[2] = (4 * SecOrdLowPassPara->DampRate - 2 * Omega * SAMPLE_TIME + SecOrdLowPassPara->DampRate * pow(Omega, 2) * pow(SAMPLE_TIME, 2)) / Coeff;

	SecOrdLowPassPara->Num[0] = (SecOrdLowPassPara->DampRate * pow(Omega, 2) * pow(SAMPLE_TIME, 2)) / Coeff;
	SecOrdLowPassPara->Num[1] = 2 * SecOrdLowPassPara->Num[0];
	SecOrdLowPassPara->Num[2] = SecOrdLowPassPara->Num[0];
}


void FisOrdHigPassFunc(BasicAudio_FilterPara *FisOrdHigPassPara)
{
	float Omega, Coeff;

	Omega = 2 * PI * FisOrdHigPassPara->Freq;
	Coeff = Omega * SAMPLE_TIME + 2;

	FisOrdHigPassPara->Den[0] = 1;
	FisOrdHigPassPara->Den[1] = (Omega * SAMPLE_TIME - 2)/Coeff;
	FisOrdHigPassPara->Den[2] = 0;

	FisOrdHigPassPara->Num[0] = 2/Coeff;
	FisOrdHigPassPara->Num[1] = -FisOrdHigPassPara->Num[0];
	FisOrdHigPassPara->Num[2] = 0;
}

void SecOrdHigPassFunc(BasicAudio_FilterPara *FisOrdHigPassPara)
{
	float Omega, Coeff;

	Omega = 2 * PI * FisOrdHigPassPara->Freq;
	Coeff = 4 + 2 * Omega * SAMPLE_TIME / FisOrdHigPassPara->DampRate + pow(Omega, 2) * pow(SAMPLE_TIME, 2);

	FisOrdHigPassPara->Den[0] = 1;
	FisOrdHigPassPara->Den[1] = (2 * pow(Omega, 2) * pow(SAMPLE_TIME, 2) - 8) / Coeff;
	FisOrdHigPassPara->Den[2] = (4 + pow(Omega, 2) * pow(SAMPLE_TIME, 2) - 2 * Omega * SAMPLE_TIME / FisOrdHigPassPara->DampRate) / Coeff;

	FisOrdHigPassPara->Num[0] =(4 / Coeff);
	FisOrdHigPassPara->Num[1] = (-8 / Coeff);
	FisOrdHigPassPara->Num[2] = FisOrdHigPassPara->Num[0];

}


void FisOrdAllPassFunc(BasicAudio_FilterPara *FisOrdAllPassPara)
{
	float Omega, Coeff;

	Omega = 2 * PI * FisOrdAllPassPara->Freq;
	Coeff = Omega * SAMPLE_TIME + 2;

	FisOrdAllPassPara->Den[0] = 1;
	FisOrdAllPassPara->Den[1] = (Omega * SAMPLE_TIME - 2)/Coeff;
	FisOrdAllPassPara->Den[2] = 0;

	FisOrdAllPassPara->Num[0] = (2 - Omega * SAMPLE_TIME)/Coeff;
	FisOrdAllPassPara->Num[1] = -(2 + Omega * SAMPLE_TIME)/Coeff;
	FisOrdAllPassPara->Num[2] = 0;
}

void SecOrdAllPassFunc(BasicAudio_FilterPara *SecOrdAllPassPara)
{
	float Omega, Coeff;

	Omega = 2 * PI * SecOrdAllPassPara->Freq;
	Coeff = 4 * SecOrdAllPassPara->DampRate + 2 * Omega * SAMPLE_TIME + SecOrdAllPassPara->DampRate * pow(Omega, 2) * pow(SAMPLE_TIME, 2);

	SecOrdAllPassPara->Den[0] = 1;
	SecOrdAllPassPara->Den[1] = (2 * SecOrdAllPassPara->DampRate * pow(Omega, 2) * pow(SAMPLE_TIME, 2) - 8 * SecOrdAllPassPara->DampRate)/Coeff;
	SecOrdAllPassPara->Den[2] = (4 * SecOrdAllPassPara->DampRate - 2 * Omega * SAMPLE_TIME + SecOrdAllPassPara->DampRate * pow(Omega, 2) * pow(SAMPLE_TIME, 2))/Coeff;

	SecOrdAllPassPara->Num[0] = SecOrdAllPassPara->Den[2];
	SecOrdAllPassPara->Num[1] = SecOrdAllPassPara->Den[1];
	SecOrdAllPassPara->Num[2] = 1;
}



/*Assign values to the coefficients of the function */
void GetFilterCoeffFunc( BasicAudio_Filter *GetCoeff, BasicAudio_FilterPara *Coeff)
{
	GetCoeff->FilterCoeff[0] = -Coeff->Den[2];
	GetCoeff->FilterCoeff[1] = -Coeff->Den[1];

	GetCoeff->FilterCoeff[2] = Coeff->Num[2];
	GetCoeff->FilterCoeff[3] = Coeff->Num[1];
	GetCoeff->FilterCoeff[4] = Coeff->Num[0];
}

void GetFilterStateFunc(BasicAudio_Filter *GetState)
{
	for(int32_t ii =0; ii < 2*FILTERSECTION; ii ++)
	{
		GetState->FilterState[ii] = 0;
	}
}

/*Biquad function modularization */
void FilterFunc(float Filter_Output[], float Filter_Input[],BasicAudio_FilterPara *GetCoeff)
{
	BasicAudio_Filter FilterPara;
	GetFilterCoeffFunc(&FilterPara, GetCoeff);

	GetFilterStateFunc(&FilterPara);

	biquad(Filter_Input,
		   Filter_Output,
		   FilterPara.FilterCoeff,
		   FilterPara.FilterState,
		   BLOCK_SIZE,
		   FILTERSECTION);
}
