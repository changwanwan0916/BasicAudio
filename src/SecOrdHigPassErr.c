/*
 * SecOrdHigPassErr.c
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

static BasicAudio_FilterPara PrSecOrderHigPassPara;

static float SecHigPassInput[BLOCK_SIZE];
static float SecHigPassOutput[BLOCK_SIZE];

static float SecOrdHigPassFreq;
//static float SecOrdLowPassFreq0[FREQNUM];
//static float FisOrdLowPassErr[FREQNUM];

static float SecOrdHigPassFreq, SecOrdLowPassQ;
static float SecOrdHigPassFreq0[FREQNUM][QNUM], SecOrdHigPassQ0[FREQNUM][QNUM];
//static float SecOrdLowPassFreqErr[FREQNUM][QNUM], SecOrdLowPassQErr[FREQNUM][QNUM];

static float PrSecOrdHigPassAmp[SAMPLES_FFT/2] = {0} ;
static float PrSecOrdHigPassPhase[SAMPLES_FFT/2] = {0} ;


void GetSecOrdHigPassErr()
{

	//for(int FreqLoop = 1; FreqLoop < FREQNUM + 1; FreqLoop ++ )
	//{
		PrSecOrderHigPassPara.Freq = 1000.0f;

		//for(int DampRateLoop = 1; DampRateLoop < QNUM + 1; DampRateLoop++)
		//{
			PrSecOrderHigPassPara.DampRate =0.707f;

			FisOrdHigPassFunc(&PrSecOrderHigPassPara);

			 float fNumeratorR[SAMPLES_FFT/2] = {0} ;
			 float fNumeratorI[SAMPLES_FFT/2] = {0} ;
			 float fDenominator[SAMPLES_FFT/2] = {0} ;

			for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
			{
				for(int RandomLoop = 0; RandomLoop < BLOCK_SIZE; RandomLoop ++)
				{
					SecHigPassInput[RandomLoop] = RandomFunc(RandomSeed, SEEDSNUM, MAXSEED);  //Check
				}

				FilterFunc(SecHigPassOutput,SecHigPassInput, &PrSecOrderHigPassPara);
				pWetchSingleLoop(fNumeratorR, fNumeratorI, fDenominator, SecHigPassInput, SecHigPassOutput);
			}

			FILE *pTff1 = fopen("InputData.txt","w");
					FILE *pTff2 = fopen("OutPut.txt","w");

					for(int32_t ii = 0; ii < BLOCK_SIZE; ii++)
					{
							fprintf(pTff1, "%f\n",SecHigPassInput[ii]);
							fprintf(pTff2, "%f\n",SecHigPassOutput[ii]);
					 }

					fclose(pTff1);
					fclose(pTff2);

			GetTransfunc(PrSecOrdHigPassAmp, PrSecOrdHigPassPhase, fNumeratorR, fNumeratorI, fDenominator);
			PrSecOrdLowPassFunc(&SecOrdLowPassFreq, &SecOrdLowPassQ,PrSecOrdLowPassAmp, PrSecOrdLowPassPhase);

			SecOrdLowPassFreq0[FreqLoop - 1][DampRateLoop - 1] = SecOrdLowPassFreq;
			SecOrdLowPassQ0[FreqLoop - 1][DampRateLoop - 1] = SecOrdLowPassQ;

			SecOrdLowPassFreqErr[FreqLoop - 1][DampRateLoop - 1] = FreqErrFunc(&PrSecOrderLowPassPara, SecOrdLowPassFreq);
			SecOrdLowPassQErr[FreqLoop - 1][DampRateLoop - 1] = QErrFuc(&PrSecOrderLowPassPara, SecOrdLowPassQ);

			//printf("%f\n",SecOrdLowPassQErr[FreqLoop - 1][DampRateLoop - 1]);

		//}
	//}
}




*/
