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

void GetPasVarFunc(BasicAudio_FilterVariable *GetVariable, BasicAudio_FilterPara *FilterPara);
void GetSheVarFunc(BasicAudio_FilterVariable *GetVariable, BasicAudio_FilterPara *FilterPara);
void GetPeaVarFunc(BasicAudio_FilterVariable *GetVariable, BasicAudio_FilterPara *FilterPara);

void GetFilterCoeffFunc( BasicAudio_BiquadPara *GetCoeff, BasicAudio_FilterPara *Coeff);
void GetFilterStateFunc(BasicAudio_BiquadPara *GetState);

/*First Order Low Pass Filter*/
void FirOrdLowPasFunc(BasicAudio_FilterPara *FirOrdLowPasPara)
{
	BasicAudio_FilterVariable PrVariable;
	GetPasVarFunc(&PrVariable, FirOrdLowPasPara);

	FirOrdLowPasPara->Coeff = PrVariable.Variable1 + 2;

	FirOrdLowPasPara->Den[0] = 1;
	FirOrdLowPasPara->Den[1] = (PrVariable.Variable1 - 2)/FirOrdLowPasPara->Coeff;
	FirOrdLowPasPara->Den[2] = 0;

	FirOrdLowPasPara->Num[0] = PrVariable.Variable1/FirOrdLowPasPara->Coeff;
	FirOrdLowPasPara->Num[1] = FirOrdLowPasPara->Num[0];
	FirOrdLowPasPara->Num[2] = 0;
}


 /*Second Order Low Pass Filter*/
void SecOrdLowPasFunc(BasicAudio_FilterPara *SecOrdLowPasPara)
{
	BasicAudio_FilterVariable PrVariable;
	GetPasVarFunc(&PrVariable, SecOrdLowPasPara);

	SecOrdLowPasPara->Coeff = 4 * SecOrdLowPasPara->DampRate + 2 * PrVariable.Variable1 + PrVariable.variable3;


	SecOrdLowPasPara->Den[0] = 1;
	SecOrdLowPasPara->Den[1] = (2 * PrVariable.variable3 - 8 * SecOrdLowPasPara->DampRate) / SecOrdLowPasPara->Coeff;
	SecOrdLowPasPara->Den[2] = (4 * SecOrdLowPasPara->DampRate - 2 * PrVariable.Variable1 + PrVariable.variable3) / SecOrdLowPasPara->Coeff;

	SecOrdLowPasPara->Num[0] = PrVariable.variable3 / SecOrdLowPasPara->Coeff;
	SecOrdLowPasPara->Num[1] = 2 * SecOrdLowPasPara->Num[0];
	SecOrdLowPasPara->Num[2] = SecOrdLowPasPara->Num[0];
}

 /*First Order High Pass Filter*/
void FirOrdHigPasFunc(BasicAudio_FilterPara *FirOrdHigPasPara)
{
	BasicAudio_FilterVariable PrVariable;
	GetPasVarFunc(&PrVariable, FirOrdHigPasPara);

	FirOrdHigPasPara->Coeff = PrVariable.Variable1 + 2;

	FirOrdHigPasPara->Den[0] = 1;
	FirOrdHigPasPara->Den[1] = (PrVariable.Variable1 - 2)/FirOrdHigPasPara->Coeff;
	FirOrdHigPasPara->Den[2] = 0;

	FirOrdHigPasPara->Num[0] = 2 / FirOrdHigPasPara->Coeff;
	FirOrdHigPasPara->Num[1] = -FirOrdHigPasPara->Num[0];
	FirOrdHigPasPara->Num[2] = 0;
}

 /*Second Order High Pass Filter*/
void SecOrdHigPasFunc(BasicAudio_FilterPara *SecOrdHigPasPara)
{
	BasicAudio_FilterVariable PrVariable;
	GetPasVarFunc(&PrVariable, SecOrdHigPasPara);

	SecOrdHigPasPara->Coeff = 4 +  2 * PrVariable.Variable1/ SecOrdHigPasPara->DampRate + PrVariable.Variable2;

	SecOrdHigPasPara->Den[0] = 1;
	SecOrdHigPasPara->Den[1] = (2 * PrVariable.Variable2 - 8) / SecOrdHigPasPara->Coeff;
	SecOrdHigPasPara->Den[2] = (4 + PrVariable.Variable2 - 2 * PrVariable.Variable1 / SecOrdHigPasPara->DampRate) / SecOrdHigPasPara->Coeff;

	SecOrdHigPasPara->Num[0] =(4 / SecOrdHigPasPara->Coeff);
	SecOrdHigPasPara->Num[1] = (-8 / SecOrdHigPasPara->Coeff);
	SecOrdHigPasPara->Num[2] = SecOrdHigPasPara->Num[0];

}

 /*Second Order High Pass Filter*/
void SecOrdAllPasFunc(BasicAudio_FilterPara *SecOrdAllPasPara)
{
	BasicAudio_FilterVariable PrVariable;
	GetPasVarFunc(&PrVariable, SecOrdAllPasPara);


	SecOrdAllPasPara->Coeff = 4 * SecOrdAllPasPara->DampRate + 2 * PrVariable.Variable1 + PrVariable.variable3;

	SecOrdAllPasPara->Den[0] = 1;
	SecOrdAllPasPara->Den[1] = (2 * PrVariable.variable3 - 8 * SecOrdAllPasPara->DampRate)/SecOrdAllPasPara->Coeff;
	SecOrdAllPasPara->Den[2] = (4 * SecOrdAllPasPara->DampRate - 2 * PrVariable.Variable1 + PrVariable.variable3)/SecOrdAllPasPara->Coeff;

	SecOrdAllPasPara->Num[0] = SecOrdAllPasPara->Den[2];
	SecOrdAllPasPara->Num[1] = SecOrdAllPasPara->Den[1];
	SecOrdAllPasPara->Num[2] = 1;
}

/*Second order low shelf filter*/
void SecOrdLowSheFunc(BasicAudio_FilterPara *SecOrdLowShePara)
{
	BasicAudio_FilterVariable PrVariable;
	GetSheVarFunc(&PrVariable, SecOrdLowShePara);

	SecOrdLowShePara->Coeff = 4 + PrVariable.variable8 + PrVariable.variable9;

	SecOrdLowShePara->Den[0] = 1;
	SecOrdLowShePara->Den[1] = (2 * PrVariable.variable9 - 8) / SecOrdLowShePara->Coeff;
	SecOrdLowShePara->Den[2] = (4 + PrVariable.variable9 - PrVariable.variable8) / SecOrdLowShePara->Coeff;

	SecOrdLowShePara->Num[0] = (4 + PrVariable.variable6 + PrVariable.variable7) / SecOrdLowShePara->Coeff;
	SecOrdLowShePara->Num[1] = (2 * PrVariable.variable7 - 8) / SecOrdLowShePara->Coeff;
	SecOrdLowShePara->Num[2] = (4 + PrVariable.variable7 - PrVariable.variable6) / SecOrdLowShePara->Coeff;
}

/*Second Order High Shelf Filter*/
void SecOrdHigSheFunc(BasicAudio_FilterPara *SecOrdHigShePara)
{
	float G;
	BasicAudio_FilterVariable PrVariable;

	SecOrdHigShePara->Gain = -SecOrdHigShePara->Gain;
	GetSheVarFunc(&PrVariable, SecOrdHigShePara);

	G = pow(10, SecOrdHigShePara->Gain / 20);

	SecOrdHigShePara->Coeff = G * (4 + PrVariable.variable8 + PrVariable.variable9);

	SecOrdHigShePara->Den[0] = 1;
	SecOrdHigShePara->Den[1] =(G * (2 * PrVariable.variable9 - 8))/ SecOrdHigShePara->Coeff;
	SecOrdHigShePara->Den[2] = (G * (4 + PrVariable.variable9 - PrVariable.variable8)) / SecOrdHigShePara->Coeff;


	SecOrdHigShePara->Num[0] = (4 + PrVariable.variable6 + PrVariable.variable7) / SecOrdHigShePara->Coeff;
	SecOrdHigShePara->Num[1] = (2 * PrVariable.variable7 - 8) / SecOrdHigShePara->Coeff;
	SecOrdHigShePara->Num[2] = (4 + PrVariable.variable7 - PrVariable.variable6) / SecOrdHigShePara->Coeff;

}

void PeakingFunc(BasicAudio_FilterPara *PeakingPara)
{
	BasicAudio_FilterVariable PrVariable;
	GetPeaVarFunc(&PrVariable, PeakingPara);

	PeakingPara->Coeff = 4 + PrVariable.variable13 + PrVariable.variable14;

	PeakingPara->Den[0] = 1;
	PeakingPara->Den[1] = (2 * PrVariable.variable14 - 8) / PeakingPara->Coeff;
	PeakingPara->Den[2] = (4 + PrVariable.variable14 - PrVariable.variable13) / PeakingPara->Coeff;

	PeakingPara->Num[0] = (4 + PrVariable.variable12 + PrVariable.variable14) / PeakingPara->Coeff;
	PeakingPara->Num[1] = PeakingPara->Den[1];
	PeakingPara->Num[2] = (4 + PrVariable.variable14 - PrVariable.variable12) / PeakingPara->Coeff;
}


/*Biquad function modularization*/
void BiquadFunc(BasicAudio_BiquadPara *FilterPara,BasicAudio_FilterPara *GetCoeff)
{
	GetFilterCoeffFunc(FilterPara, GetCoeff);

	//GetFilterStateFunc(FilterPara);

	for(int32_t ii =0; ii < 2*FILTERSECTION; ii ++)
		{
		FilterPara->FilterState[ii] = 0;
		}

	biquad(FilterPara->FilterInput,
		   FilterPara->FilterOutput,
		   FilterPara->FilterCoeff,
		   FilterPara->FilterState,
		   BLOCK_SIZE,
		   FILTERSECTION);
}

/*Get the intermediate variable of the pass filter:Omega, Omega * T, Omega^2 * T^2 , q * Omega^2 * T^2 */
void GetPasVarFunc(BasicAudio_FilterVariable *GetVariable, BasicAudio_FilterPara *FilterPara)
{
    float SampleTime;
    SampleTime = ((float)1/(float)SAMPLE_FREQUENCY);

	FilterPara->Omega = 2 * PI * FilterPara->Freq;

	GetVariable->Variable1 = FilterPara->Omega * SampleTime;
	GetVariable->Variable2 = powf(GetVariable->Variable1, 2.0);
	GetVariable->variable3 = FilterPara->DampRate * GetVariable->Variable2;
}

/* Get the intermediate variable of the shelf filter:omega1, omega2, 2*omega1*T/q, omega1^2 * T^2,
   2 * omega2 * T/q , omega2^2 * T^2 */
void GetSheVarFunc(BasicAudio_FilterVariable *GetVariable, BasicAudio_FilterPara *FilterPara)
{
    float SampleTime;
    SampleTime = ((float)1/(float)SAMPLE_FREQUENCY);

    FilterPara->Omega = 2 * PI * FilterPara->Freq;

	GetVariable->variable4 = FilterPara->Omega * powf(10, FilterPara->Gain/80);
	GetVariable->variable5 = FilterPara->Omega / powf(10, FilterPara->Gain/80);

	GetVariable->variable6 = 2 * GetVariable->variable4 * SampleTime/FilterPara->DampRate;
	GetVariable->variable7 = powf(GetVariable->variable4, 2.0) * powf(SampleTime, 2.0);

	GetVariable->variable8 = 2 * GetVariable->variable5 * SampleTime/FilterPara->DampRate;
	GetVariable->variable9 = powf(GetVariable->variable5, 2.0) * powf(SampleTime, 2.0);
}

/* Get the intermediate variable of the peaking filter:q1, q2, omega * T / q1, omega * T / q2,
   omega2^2 * T^2 */
void GetPeaVarFunc(BasicAudio_FilterVariable *GetVariable, BasicAudio_FilterPara *FilterPara)
{
	 float SampleTime;
	 SampleTime = ((float)1/(float)SAMPLE_FREQUENCY);

	 FilterPara->Omega = 2 * PI * FilterPara->Freq;

	 GetVariable->variable10 = FilterPara->DampRate / powf(10.0, FilterPara->Gain/40);
	 GetVariable->variable11 = FilterPara->DampRate * powf(10.0, FilterPara->Gain/40);

	 GetVariable->variable12 = 2 * FilterPara->Omega * SampleTime / GetVariable->variable10;
	 GetVariable->variable13 = 2 * FilterPara->Omega * SampleTime / GetVariable->variable11;

	 GetVariable->variable14 = powf(FilterPara->Omega, 2.0) * powf(SampleTime, 2.0);
}


//Assign values to the coefficients of the function
void GetFilterCoeffFunc( BasicAudio_BiquadPara *GetCoeff, BasicAudio_FilterPara *Coeff)
{
	GetCoeff->FilterCoeff[0] = -Coeff->Den[2];
	GetCoeff->FilterCoeff[1] = -Coeff->Den[1];

	GetCoeff->FilterCoeff[2] = Coeff->Num[2];
	GetCoeff->FilterCoeff[3] = Coeff->Num[1];
	GetCoeff->FilterCoeff[4] = Coeff->Num[0];
}

void GetFilterStateFunc(BasicAudio_BiquadPara *GetState)
{
	for(int32_t ii =0; ii < 2*FILTERSECTION; ii ++)
	{
		GetState->FilterState[ii] = 0;
	}
}

