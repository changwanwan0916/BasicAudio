/*
 * peakingErr.c
 *
 *  Created on: 2021��5��24��
 *      Author: Brisonus-DELL
 */


/*
#include<stdint.h>
#include <string.h>
#include<stdio.h>
#include<math.h>
#include <filter.h>

#include"RecoPara.h"
#include"TransFunc.h"
#include"BasicAudioTest.h"
#include"Filter.h"
#include"WhiteNoise.h"

static BasicAudio_FilterPara PeakingPara;
static BasicAudio_BiquadPara PeakingBiquadPara;
static BasicAudio_TransPara PeakingTransComp;
static BasicAudio_RecoPara PeakingPrRecoPara;

static float Freq0, Q0, Gain0;


void GetPeakingErr(BasicAudio_GetPeakingPara *PrPeakingPara)
{

	for(int FreqLoop = 0; FreqLoop < FREQNUM; FreqLoop ++ )
	{

		PeakingPara.Freq = FISFREQ * powf(FREQRATIO, FreqLoop);

		for(int DampRateLoop = 0; DampRateLoop < QNUM; DampRateLoop++)
		{
			PeakingPara.DampRate = FISQ * powf(QRATIO, DampRateLoop);

			for(int32_t GainLoop = 0; GainLoop < GAINNUM ; GainLoop++)
			{
				PeakingPara.Gain = FISGAIN + GainLoop * (float)DISGAIN;

				PeakingFunc(&PeakingPara);

				memset(PeakingTransComp.fNumeratorR, 0, sizeof(float)*SAMPLES_FFT/2);
				memset(PeakingTransComp.fNumeratorI, 0, sizeof(float)*SAMPLES_FFT/2);
				memset(PeakingTransComp.fDenominator, 0, sizeof(float)*SAMPLES_FFT/2);

				for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
				{

					WhiteNoiseFunc(PeakingBiquadPara.FilterInput);
					BiquadFunc(&PeakingBiquadPara, &PeakingPara);
					pWetchSingleLoop(&PeakingTransComp, &PeakingBiquadPara);
				}

					GetTransfunc(&PeakingTransComp);
					PrPeakingFunc(&PeakingPrRecoPara, &PeakingPara, &PeakingTransComp);

					PrPeakingPara->Freq[FreqLoop][DampRateLoop][GainLoop] = PeakingPrRecoPara.PrFreq;
					PrPeakingPara->DampRate[FreqLoop][DampRateLoop][GainLoop] = PeakingPrRecoPara.PrDampRate;
					PrPeakingPara->Gain[FreqLoop][DampRateLoop][GainLoop] = PeakingPrRecoPara.PrGain;
			}
		}

	}
}

*/
