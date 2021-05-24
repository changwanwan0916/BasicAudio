/*
 * FisOrdLowPassErr.c
 *
 *  Created on: 2021Äê5ÔÂ20ÈÕ
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

static BasicAudio_FilterPara PrFisOrderLowPassPara;

static float FisOrdLowPassInput[BLOCK_SIZE];
static float FisOrdLowPassOutput[BLOCK_SIZE];

static float FisOrdLowPassFreq;
//static float FisOrdLowPassFreq0[FREQNUM];
//static float FisOrdLowPassErr[FREQNUM];

static float PrFisOrdLowPassAmp[SAMPLES_FFT/2] = {0} ;
static float PrFisOrdLowPassPhase[SAMPLES_FFT/2] = {0} ;

Get the parameter error of the first-order low-pass filter
void GetFisOrdLowPassErr(float *FisOrdLowPassFreq0, float *FisOrdLowPassErr)
{
	for(int ii = 1; ii < FREQNUM + 1; ii ++ )
	{

		float fNumeratorR[SAMPLES_FFT/2] = {0} ;
		float fNumeratorI[SAMPLES_FFT/2] = {0} ;
		float fDenominator[SAMPLES_FFT/2] = {0} ;


		PrFisOrderLowPassPara.Freq = FISFREQ + (ii - 1) * (float)DisFREQ;

		FisOrdLowPassFunc(&PrFisOrderLowPassPara);


		for(int i=0; i<AVERAGE_NUM; i++)
		{
			for(int j = 0; j < BLOCK_SIZE; j++)
			{
				FisOrdLowPassInput[j] = RandomFunc(RandomSeed, SEEDSNUM, MAXSEED);  //Check
			}

			FilterFunc(FisOrdLowPassOutput, FisOrdLowPassInput, &PrFisOrderLowPassPara);

			pWetchSingleLoop(fNumeratorR, fNumeratorI, fDenominator, FisOrdLowPassInput, FisOrdLowPassOutput);
		}


		GetTransfunc(PrFisOrdLowPassAmp, PrFisOrdLowPassPhase, fNumeratorR, fNumeratorI, fDenominator);

		PrFisOrdLowPassFunc(&FisOrdLowPassFreq, PrFisOrdLowPassAmp, PrFisOrdLowPassPhase);

		FisOrdLowPassFreq0[ii - 1] = FisOrdLowPassFreq;
		FisOrdLowPassErr[ii - 1] = FreqErrFunc(&PrFisOrderLowPassPara, FisOrdLowPassFreq);

	}

}
*/
