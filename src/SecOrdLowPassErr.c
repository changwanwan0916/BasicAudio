/*
 * SecOrdLowPassErr.c
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

static BasicAudio_FilterPara PrSecOrderLowPassPara;

static float SecLowPassInput[BLOCK_SIZE];
static float SecLowPassOutput[BLOCK_SIZE];

static float SecOrdLowPassFreq;
//static float SecOrdLowPassFreq0[FREQNUM];
//static float FisOrdLowPassErr[FREQNUM];

static float SecOrdLowPassFreq, SecOrdLowPassQ;
static float SecOrdLowPassFreq0[FREQNUM][QNUM], SecOrdLowPassQ0[FREQNUM][QNUM];
//static float SecOrdLowPassFreqErr[FREQNUM][QNUM], SecOrdLowPassQErr[FREQNUM][QNUM];

static float PrSecOrdLowPassAmp[SAMPLES_FFT/2] = {0} ;
static float PrSecOrdLowPassPhase[SAMPLES_FFT/2] = {0} ;


void GetSecOrdLowPassErr(float SecOrdLowPassFreqErr[][QNUM],float SecOrdLowPassQErr[][QNUM])
{

	//for(int FreqLoop = 1; FreqLoop < FREQNUM + 1; FreqLoop ++ )
	//{
		//PrSecOrderLowPassPara.Freq = FISFREQ + (FreqLoop - 1) * (float)DisFREQ;

		//for(int DampRateLoop = 1; DampRateLoop < QNUM + 1; DampRateLoop++)
		//{
			//PrSecOrderLowPassPara.DampRate = FISQ + (DampRateLoop - 1) * (float)DisQ;

			PrSecOrderLowPassPara.Freq = 1000.0f;
			PrSecOrderLowPassPara.DampRate = 18.0f;

			SecOrdLowPassFunc(&PrSecOrderLowPassPara);

			 float fNumeratorR[SAMPLES_FFT/2] = {0} ;
			 float fNumeratorI[SAMPLES_FFT/2] = {0} ;
			 float fDenominator[SAMPLES_FFT/2] = {0} ;

			for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
			{
				for(int RandomLoop = 0; RandomLoop < BLOCK_SIZE; RandomLoop ++)
				{
					SecLowPassInput[RandomLoop] = RandomFunc(RandomSeed, SEEDSNUM, MAXSEED);  //Check
				}

				FilterFunc(SecLowPassOutput,SecLowPassInput, &PrSecOrderLowPassPara);
				pWetchSingleLoop(fNumeratorR, fNumeratorI, fDenominator, SecLowPassInput, SecLowPassOutput);
			}

			GetTransfunc(PrSecOrdLowPassAmp, PrSecOrdLowPassPhase, fNumeratorR, fNumeratorI, fDenominator);
			PrSecOrdLowPassFunc(&SecOrdLowPassFreq, &SecOrdLowPassQ,PrSecOrdLowPassAmp, PrSecOrdLowPassPhase);

//			SecOrdLowPassFreq0[FreqLoop - 1][DampRateLoop - 1] = SecOrdLowPassFreq;
//			SecOrdLowPassQ0[FreqLoop - 1][DampRateLoop - 1] = SecOrdLowPassQ;
//
//			SecOrdLowPassFreqErr[FreqLoop - 1][DampRateLoop - 1] = FreqErrFunc(&PrSecOrderLowPassPara, SecOrdLowPassFreq);
//			SecOrdLowPassQErr[FreqLoop - 1][DampRateLoop - 1] = QErrFuc(&PrSecOrderLowPassPara, SecOrdLowPassQ);

			//printf("%f\n",SecOrdLowPassQErr[FreqLoop - 1][DampRateLoop - 1]);

		//}
	//}

}



*/
