/*
 * FisOrdHigPassErr.c
 *
 *  Created on: 2021Äê5ÔÂ22ÈÕ
 *      Author: Brisonus-DELL
 */



/*#include<stdint.h>
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

static BasicAudio_FilterPara PrFisOrderHigPassPara;

static float FisOrdHigPassInput[BLOCK_SIZE];
static float FisOrdHigPassOutput[BLOCK_SIZE];

static float FisOrdHigPassFreq;
//static float FisOrdLowPassFreq0[FREQNUM];
//static float FisOrdLowPassErr[FREQNUM];

static float PrFisOrdHigPassAmp[SAMPLES_FFT/2] = {0} ;
static float PrFisOrdHigPassPhase[SAMPLES_FFT/2] = {0} ;

//Get the parameter error of the first-order low-pass filter
//void GetFisOrdHigPassErr(float *FisOrdHigPassFreq0, float *FisOrdHigPassErr)
void GetFisOrdHigPassErr()
{
	//for(int ii = 1; ii < FREQNUM + 1; ii ++ )
	//{

		static float fNumeratorR[SAMPLES_FFT/2] = {0} ;
		static float fNumeratorI[SAMPLES_FFT/2] = {0} ;
		static float fDenominator[SAMPLES_FFT/2] = {0} ;


		PrFisOrderHigPassPara.Freq = 1000;

		FisOrdHigPassFunc(&PrFisOrderHigPassPara);


		for(int i=0; i<AVERAGE_NUM; i++)
		{
			for(int j = 0; j < BLOCK_SIZE; j++)
			{
				FisOrdHigPassInput[j] = RandomFunc(RandomSeed, SEEDSNUM, MAXSEED);  //Check
			}

			FilterFunc(FisOrdHigPassOutput, FisOrdHigPassInput, &PrFisOrderHigPassPara);

			pWetchSingleLoop(fNumeratorR, fNumeratorI, fDenominator, FisOrdHigPassInput, FisOrdHigPassOutput);
		}


		GetTransfunc(PrFisOrdHigPassAmp, PrFisOrdHigPassPhase, fNumeratorR, fNumeratorI, fDenominator);

		//PrFisOrdLowPassFunc(&FisOrdHigPassFreq, PrFisOrdHigPassAmp, PrFisOrdHigPassPhase);

		//FisOrdLowPassFreq0[ii - 1] = FisOrdLowPassFreq;
		//FisOrdLowPassErr[ii - 1] = FreqErrFunc(&PrFisOrderLowPassPara, FisOrdLowPassFreq);
}*/
