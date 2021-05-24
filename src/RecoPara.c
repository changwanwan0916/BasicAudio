/*
 * RecoPara.c
 *
 *  Created on: 2021��5��18��
 *      Author: Brisonus-DELL
 */


#include<stdint.h>
#include<stdio.h>
#include<math.h>
#include <filter.h>

#include"RecoPara.h"
#include"TransFunc.h"
#include"BasicAudioTest.h"
#include"Filter.h"

static uint32_t FisOrdLowPassFreqNum;

static uint32_t SecOrdLowPassFreqNum, SecOrdLowPassQNum;
static float SecOrdLowPassFreqCorr;

static float SecOrdLowPassQ;
static float SecOrdLowPassAmpR, SecOrdLowPassAmpL;

static uint32_t FisOrdHigPassFreqNum;

static uint32_t FisOrdAllPassFreqNum;

static uint32_t SecOrdAllPassFreqNum,SecOrdAllPassQNum;
static float SecOrdAllPassPhaseR,SecOrdAllPassPhaseL;
static float SecOrdAllPassFreqCorr, Degree;
static float GetTransFuncPhase1[2048];
static uint32_t Num;

static float ResoFreq, FreqR;
static float FreqErr, QErr;

float FreqErrFunc(BasicAudio_FilterPara *InputFreq, float PrFreqPara);
float QErrFuc(BasicAudio_FilterPara *InputQ, float PrQPara);

/*Calculate the parameters of the first-order low-pass filter */
void PrFisOrdLowPassFunc(float *FisOrdLowPassFreq, float GetTransFuncAmp[], float GetTransFuncPhase[])
{
	for (int PhaseLoop = 0; PhaseLoop < SAMPLES_FFT/2; PhaseLoop++)
		{
			if(GetTransFuncPhase[PhaseLoop]  <= -45)
			{
				FisOrdLowPassFreqNum = PhaseLoop;
				break;
			}

		}

	ResoFreq = ((float)SAMPLE_FREQUENCY/(float)BLOCK_SIZE);
	FreqR = FisOrdLowPassFreqNum * ResoFreq;

	*FisOrdLowPassFreq = FreqR - (-45 - GetTransFuncPhase[FisOrdLowPassFreqNum])/(GetTransFuncPhase[FisOrdLowPassFreqNum-1]-GetTransFuncPhase[FisOrdLowPassFreqNum])*ResoFreq;
}

void PrSecOrdLowPassFunc(float *FisOrdLowPassFreq, float *SecOrdLowPassQ,float GetTransFuncAmp[], float GetTransFuncPhase[])
{
	float FreqVolue;

	for (int PhaseLoop = 0; PhaseLoop < SAMPLES_FFT/2; PhaseLoop++)
	{
		if(GetTransFuncPhase[PhaseLoop]  <= -90)
		{
			SecOrdLowPassFreqNum = PhaseLoop;
			break;
		}

	}

	ResoFreq = ((float)SAMPLE_FREQUENCY/(float)BLOCK_SIZE);

	FreqR = SecOrdLowPassFreqNum * ResoFreq;
	*FisOrdLowPassFreq = FreqR - (-90 - GetTransFuncPhase[SecOrdLowPassFreqNum])/(GetTransFuncPhase[SecOrdLowPassFreqNum-1]
						 -GetTransFuncPhase[SecOrdLowPassFreqNum])*ResoFreq;

	for(int FreqLoop =0; FreqLoop < SAMPLES_FFT/2; FreqLoop++)
	{
		SecOrdLowPassFreqCorr = ResoFreq * (float)FreqLoop;

		if(SecOrdLowPassFreqCorr >= *FisOrdLowPassFreq)
		{
			SecOrdLowPassQNum  = FreqLoop;
			break;
		}
	}

	SecOrdLowPassAmpL = GetTransFuncAmp[SecOrdLowPassQNum - 1];
	SecOrdLowPassAmpR = GetTransFuncAmp[SecOrdLowPassQNum];


	*SecOrdLowPassQ = SecOrdLowPassAmpL+ ((*FisOrdLowPassFreq - SecOrdLowPassQNum * ResoFreq)/ResoFreq) * (SecOrdLowPassAmpR - SecOrdLowPassAmpL);


}

void PrFisOrdHigPassFunc(float *FisOrdHigPassFreq, float GetTransFuncAmp[], float GetTransFuncPhase[])
{
	for (int PhaseLoop = 0; PhaseLoop < SAMPLES_FFT/2; PhaseLoop++)
		{
			if(GetTransFuncPhase[PhaseLoop]  <= 45)
			{
				FisOrdHigPassFreqNum = PhaseLoop;
				break;
			}

		}

	ResoFreq = ((float)SAMPLE_FREQUENCY/(float)BLOCK_SIZE);
	FreqR = FisOrdHigPassFreqNum * ResoFreq;

	*FisOrdHigPassFreq = FreqR - (45 - GetTransFuncPhase[FisOrdHigPassFreqNum])/(GetTransFuncPhase[FisOrdHigPassFreqNum-1]-GetTransFuncPhase[FisOrdHigPassFreqNum])*ResoFreq;
}

void PrFisOrdAllPassFunc(float *FisOrdHigPassFreq, float GetTransFuncAmp1[], float GetTransFuncPhase[])
{
	for (int PhaseLoop = 0; PhaseLoop < SAMPLES_FFT/2; PhaseLoop++)
		{
			if(GetTransFuncPhase[PhaseLoop]  <= 90)
			{
				FisOrdAllPassFreqNum = PhaseLoop;
				break;
			}

		}

	ResoFreq = ((float)SAMPLE_FREQUENCY/(float)BLOCK_SIZE);
	FreqR = FisOrdAllPassFreqNum * ResoFreq;

	*FisOrdHigPassFreq = FreqR - (90 - GetTransFuncPhase[FisOrdAllPassFreqNum])/(GetTransFuncPhase[FisOrdAllPassFreqNum-1]-GetTransFuncPhase[FisOrdAllPassFreqNum])*ResoFreq;
}


void PrSecOrdAllPassFunc(float *FisOrdAllPassFreq, float *SecOrdAllPassQ,float GetTransFuncAmp[], float GetTransFuncPhase[])
{
	float FreqVolue;

	for(int NumLoop1 = 0; NumLoop1 < SAMPLES_FFT/2; NumLoop1++)
	{
		if(GetTransFuncPhase[NumLoop1]  > 0)
			{
				Num = NumLoop1;
				break;
			}
	}

	for (int PhaseLoop = 0; PhaseLoop < SAMPLES_FFT/2; PhaseLoop++)
	{
		if(GetTransFuncPhase[PhaseLoop]  > 0)
		{

			GetTransFuncPhase1[PhaseLoop] = GetTransFuncPhase[PhaseLoop] - 360;
		}
		else
		{
			GetTransFuncPhase1[PhaseLoop] = GetTransFuncPhase[PhaseLoop];
		}
	}

	for(int ii = 0; ii < SAMPLES_FFT/2; ii ++)
	{

		if(GetTransFuncPhase1[ii]  <= -180)
			{
				SecOrdAllPassFreqNum = ii;
				break;
			}

	}

	ResoFreq = ((float)SAMPLE_FREQUENCY/(float)BLOCK_SIZE);

	FreqR = SecOrdAllPassFreqNum * ResoFreq;
	*FisOrdAllPassFreq = FreqR - (-180 - GetTransFuncPhase1[SecOrdAllPassFreqNum])/(GetTransFuncPhase1[SecOrdAllPassFreqNum - 1]
						 -GetTransFuncPhase1[SecOrdAllPassFreqNum])*ResoFreq;

	for(int FreqLoop =0; FreqLoop < SAMPLES_FFT/2; FreqLoop++)
	{
		SecOrdAllPassFreqCorr = ResoFreq * (float)FreqLoop;

		if(SecOrdAllPassFreqCorr >= (*FisOrdAllPassFreq)/2)
		{
			SecOrdAllPassQNum  = FreqLoop;
			break;
		}
	}

	SecOrdAllPassPhaseL = GetTransFuncPhase1[SecOrdAllPassQNum - 1];
	SecOrdAllPassPhaseR = GetTransFuncPhase1[SecOrdAllPassQNum];


	Degree = SecOrdAllPassPhaseR - (((*FisOrdAllPassFreq)/2 - SecOrdAllPassQNum * ResoFreq)/ResoFreq) * (SecOrdAllPassPhaseL - SecOrdAllPassPhaseR);
	*SecOrdAllPassQ = 2/(3 * tanf(-Degree * PI / 180 /2));

}


/*frequency error*/
float FreqErrFunc(BasicAudio_FilterPara *InputFreq, float PrFreqPara)
{

	FreqErr = (fabs((InputFreq->Freq - PrFreqPara)))/InputFreq->Freq;
	return FreqErr;
}

/*Q error*/
float QErrFuc(BasicAudio_FilterPara *InputQ, float PrQPara)
{
	QErr = fabs(InputQ->DampRate - PrQPara);
	return QErr;
}
