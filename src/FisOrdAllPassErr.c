/*
 * FisOrdAllPassErr.c
 *
 *  Created on: 2021Äê5ÔÂ22ÈÕ
 *      Author: Brisonus-DELL
 */


/*
#include<stdint.h>
#include<stdio.h>
#include<math.h>
#include <filter.h>

#include"RecoPara.h"
#include"TransFunc.h"
#include"BasicAudioTest.h"
#include"Filter.h"
#include"WhiteNoise.h"

static int32_t RandomSeed[SEEDSNUM] = {
	#include "RandSeed.txt"
	};

static BasicAudio_FilterPara PrFisOrderAllPassPara;

static float FisOrdAllPassInput[BLOCK_SIZE];
static float FisOrdAllPassOutput[BLOCK_SIZE];

static float FisOrdAllPassFreq;
//static float FisOrdLowPassFreq0[FREQNUM];
//static float FisOrdLowPassErr[FREQNUM];

static float PrFisOrdAllPassAmp[SAMPLES_FFT/2] = {0} ;
static float PrFisOrdAllPassPhase[SAMPLES_FFT/2] = {0} ;

Get the parameter error of the first-order low-pass filter
void GetFisOrdAllPassErr(float *FisOrdAllPassFreq0, float *FisOrdAllPassErr)
{
	for(int ii = 1; ii < FREQNUM + 1; ii ++ )
	{

		float fNumeratorR[SAMPLES_FFT/2] = {0} ;
		float fNumeratorI[SAMPLES_FFT/2] = {0} ;
		float fDenominator[SAMPLES_FFT/2] = {0} ;


		PrFisOrderAllPassPara.Freq = FISFREQ + (ii - 1) * (float)DisFREQ;

		FisOrdAllPassFunc(&PrFisOrderAllPassPara);


		for(int i=0; i<AVERAGE_NUM; i++)
		{
			for(int j = 0; j < BLOCK_SIZE; j++)
			{
				FisOrdAllPassInput[j] = RandomFunc(RandomSeed, SEEDSNUM, MAXSEED);  //Check
			}

			FilterFunc(FisOrdAllPassOutput, FisOrdAllPassInput, &PrFisOrderAllPassPara);

			pWetchSingleLoop(fNumeratorR, fNumeratorI, fDenominator, FisOrdAllPassInput, FisOrdAllPassOutput);
		}


		GetTransfunc(PrFisOrdAllPassAmp, PrFisOrdAllPassPhase, fNumeratorR, fNumeratorI, fDenominator);

		PrFisOrdAllPassFunc(&FisOrdAllPassFreq, PrFisOrdAllPassAmp, PrFisOrdAllPassPhase);

		FisOrdAllPassFreq0[ii - 1] = FisOrdAllPassFreq;
		FisOrdAllPassErr[ii - 1] = FreqErrFunc(&PrFisOrderAllPassPara, FisOrdAllPassFreq);
	}
}



*/
