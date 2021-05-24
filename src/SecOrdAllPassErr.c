/*
 * SecOrdAllPassErr.c
 *
 *  Created on: 2021Äê5ÔÂ22ÈÕ
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
#include"WhiteNoise.h"

static int32_t RandomSeed[SEEDSNUM] = {
	#include "RandSeed.txt"
	};

static BasicAudio_FilterPara PrSecOrderAllPassPara;

static float SecAllPassInput[BLOCK_SIZE];
static float SecAllPassOutput[BLOCK_SIZE];

static float SecOrdAllPassFreq;
//static float SecOrdLowPassFreq0[FREQNUM];
//static float FisOrdLowPassErr[FREQNUM];

static float SecOrdAllPassFreq, SecOrdAllPassQ;
static float SecOrdAllPassFreq0[FREQNUM][QNUM], SecOrdAllPassQ0[FREQNUM][QNUM];
//static float SecOrdLowPassFreqErr[FREQNUM][QNUM], SecOrdLowPassQErr[FREQNUM][QNUM];

static float PrSecOrdAllPassAmp[SAMPLES_FFT/2] = {0} ;
static float PrSecOrdAllPassPhase[SAMPLES_FFT/2] = {0} ;

void GetSecOrdAllPassErr()
//void GetSecOrdAllPassErr(float SecOrdAllPassFreqErr[][QNUM],float SecOrdAllPassQErr[][QNUM])
{

	/*for(int FreqLoop = 1; FreqLoop < FREQNUM + 1; FreqLoop ++ )
	{
		PrSecOrderAllPassPara.Freq = FISFREQ + (FreqLoop - 1) * (float)DisFREQ;

		for(int DampRateLoop = 1; DampRateLoop < QNUM + 1; DampRateLoop++)
		{
			PrSecOrderAllPassPara.DampRate = FISQ + (DampRateLoop - 1) * (float)DisQ;*/

			PrSecOrderAllPassPara.Freq = 1000.0f;
			PrSecOrderAllPassPara.DampRate = 0.707f;
			SecOrdAllPassFunc(&PrSecOrderAllPassPara);

			 float fNumeratorR[SAMPLES_FFT/2] = {0} ;
			 float fNumeratorI[SAMPLES_FFT/2] = {0} ;
			 float fDenominator[SAMPLES_FFT/2] = {0} ;

			for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
			{
				for(int RandomLoop = 0; RandomLoop < BLOCK_SIZE; RandomLoop ++)
				{
					SecAllPassInput[RandomLoop] = RandomFunc(RandomSeed, SEEDSNUM, MAXSEED);  //Check
				}

				FilterFunc(SecAllPassOutput,SecAllPassInput, &PrSecOrderAllPassPara);
				pWetchSingleLoop(fNumeratorR, fNumeratorI, fDenominator, SecAllPassInput, SecAllPassOutput);
			}

			GetTransfunc(PrSecOrdAllPassAmp, PrSecOrdAllPassPhase, fNumeratorR, fNumeratorI, fDenominator);
			PrSecOrdAllPassFunc(&SecOrdAllPassFreq, &SecOrdAllPassQ,PrSecOrdAllPassAmp, PrSecOrdAllPassPhase);

			/*SecOrdAllPassFreq0[FreqLoop - 1][DampRateLoop - 1] = SecOrdAllPassFreq;
			SecOrdAllPassQ0[FreqLoop - 1][DampRateLoop - 1] = SecOrdAllPassQ;

			SecOrdAllPassFreqErr[FreqLoop - 1][DampRateLoop - 1] = FreqErrFunc(&PrSecOrderAllPassPara, SecOrdAllPassFreq);
			SecOrdAllPassQErr[FreqLoop - 1][DampRateLoop - 1] = QErrFuc(&PrSecOrderAllPassPara, SecOrdAllPassQ);
*/
			//printf("%f\n",SecOrdLowPassQErr[FreqLoop - 1][DampRateLoop - 1]);

		//}
	//}

}



