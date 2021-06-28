/*
 * SecOrdLowShelfErr.c
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

static BasicAudio_FilterPara SecOrdLowShePara;
static BasicAudio_BiquadPara SecOrdLowSheBiquadPara;
static BasicAudio_TransPara SecOrdLowSheTransComp;
static BasicAudio_RecoPara SecOrdLowShePrRecoPara;

static float Freq0, Q0, Gain0;


void GetSecOrdLowSheErr(BasicAudio_GetSecOrdLowShePara *PrSecOrdLowShePara)
{
	for(int32_t FreqLoop = 0; FreqLoop < FREQNUM; FreqLoop ++ )
	{
		SecOrdLowShePara.Freq = FISFREQ * powf(FREQRATIO, FreqLoop);

		for(int32_t DampRateLoop = 0; DampRateLoop < QNUM ; DampRateLoop++)
		{
			SecOrdLowShePara.DampRate = FISQ * powf(QRATIO, DampRateLoop);

			for(int32_t GainLoop = 0; GainLoop < GAINNUM; GainLoop++)
			{
				SecOrdLowShePara.Gain = FISGAIN + GainLoop * (float)DISGAIN;

				SecOrdLowSheFunc(&SecOrdLowShePara);
				memset(SecOrdLowSheTransComp.fNumeratorR, 0, sizeof(float)*SAMPLES_FFT/2);
				memset(SecOrdLowSheTransComp.fNumeratorI, 0, sizeof(float)*SAMPLES_FFT/2);
				memset(SecOrdLowSheTransComp.fDenominator, 0, sizeof(float)*SAMPLES_FFT/2);

				for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
				{
					WhiteNoiseFunc(SecOrdLowSheBiquadPara.FilterInput);
					BiquadFunc(&SecOrdLowSheBiquadPara, &SecOrdLowShePara);
					pWetchSingleLoop(&SecOrdLowSheTransComp, &SecOrdLowSheBiquadPara);
				}

				GetTransfunc(&SecOrdLowSheTransComp);
				PrSecOrdLowSheFunc(&SecOrdLowShePrRecoPara, &SecOrdLowShePara, &SecOrdLowSheTransComp);

				PrSecOrdLowShePara->Freq[FreqLoop][DampRateLoop][GainLoop] = SecOrdLowShePrRecoPara.PrFreq;
				PrSecOrdLowShePara->DampRate[FreqLoop][DampRateLoop][GainLoop] = SecOrdLowShePrRecoPara.PrDampRate;
				PrSecOrdLowShePara->Gain[FreqLoop][DampRateLoop][GainLoop] = SecOrdLowShePrRecoPara.PrGain;

				PrSecOrdLowShePara->FreqErr[FreqLoop][DampRateLoop][GainLoop] = SecOrdLowShePrRecoPara.FreqErr;
				PrSecOrdLowShePara->DampRateErr[FreqLoop][DampRateLoop][GainLoop] = SecOrdLowShePrRecoPara.DampRateErr;
				PrSecOrdLowShePara->GainErr[FreqLoop][DampRateLoop][GainLoop] = SecOrdLowShePrRecoPara.GainErr;

			}
		}
	}

}

*/
