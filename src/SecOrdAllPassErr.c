/*
 * SecOrdAllPassErr.c
 *
 *  Created on: 2021��5��22��
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

static BasicAudio_FilterPara SecOrdAllPasPara;
static BasicAudio_BiquadPara SecOrdAllPasBiquadPara;
static BasicAudio_TransPara SecOrdAllPasTransComp;
static BasicAudio_RecoPara SecOrdAllPasPrRecoPara;

static float Freq0, Q;

void GetSecOrdAllPassErr(BasicAudio_GetSecOrdAllPasPara *PrSecOrdAllPasPara)
{

	for(int FreqLoop = 0; FreqLoop < FREQNUM; FreqLoop ++ )
		{
			SecOrdAllPasPara.Freq = FISFREQ * powf(FREQRATIO, FreqLoop);
			//SecOrdAllPasPara.Freq=1000.0f;

			for(int DampRateLoop = 0; DampRateLoop < QNUM; DampRateLoop++)
			{
				SecOrdAllPasPara.DampRate = FISQ * powf(QRATIO, DampRateLoop);
				//SecOrdAllPasPara.DampRate = 1.5f;

				if(SecOrdAllPasPara.Freq == FISFREQ * powf(FREQRATIO, 56) && SecOrdAllPasPara.DampRate == FISQ * powf(QRATIO, 15))
				{
					SecOrdAllPasFunc(&SecOrdAllPasPara);

					memset(SecOrdAllPasTransComp.fNumeratorR, 0, sizeof(float)*SAMPLES_FFT/2);
					memset(SecOrdAllPasTransComp.fNumeratorI, 0, sizeof(float)*SAMPLES_FFT/2);
					memset(SecOrdAllPasTransComp.fDenominator, 0, sizeof(float)*SAMPLES_FFT/2);

					for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
					{
						WhiteNoiseFunc(SecOrdAllPasBiquadPara.FilterInput);
						BiquadFunc(&SecOrdAllPasBiquadPara, &SecOrdAllPasPara);
						pWetchSingleLoop(&SecOrdAllPasTransComp, &SecOrdAllPasBiquadPara);
					}

					GetTransfunc(&SecOrdAllPasTransComp);
					PrSecOrdAllPasFunc(&SecOrdAllPasPrRecoPara, &SecOrdAllPasPara, &SecOrdAllPasTransComp);

					PrSecOrdAllPasPara->Freq[FreqLoop][DampRateLoop] = SecOrdAllPasPrRecoPara.PrFreq;
					PrSecOrdAllPasPara->DampRate[FreqLoop][DampRateLoop]= SecOrdAllPasPrRecoPara.PrDampRate;


					PrSecOrdAllPasPara->FreqErr[FreqLoop][DampRateLoop] = SecOrdAllPasPrRecoPara.FreqErr;
					PrSecOrdAllPasPara->DampRateErr[FreqLoop][DampRateLoop] = SecOrdAllPasPrRecoPara.DampRateErr;

				}

				SecOrdAllPasFunc(&SecOrdAllPasPara);

				memset(SecOrdAllPasTransComp.fNumeratorR, 0, sizeof(float)*SAMPLES_FFT/2);
				memset(SecOrdAllPasTransComp.fNumeratorI, 0, sizeof(float)*SAMPLES_FFT/2);
				memset(SecOrdAllPasTransComp.fDenominator, 0, sizeof(float)*SAMPLES_FFT/2);

				for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
				{
					WhiteNoiseFunc(SecOrdAllPasBiquadPara.FilterInput);
					BiquadFunc(&SecOrdAllPasBiquadPara, &SecOrdAllPasPara);
					pWetchSingleLoop(&SecOrdAllPasTransComp, &SecOrdAllPasBiquadPara);
				}

				GetTransfunc(&SecOrdAllPasTransComp);
				PrSecOrdAllPasFunc(&SecOrdAllPasPrRecoPara, &SecOrdAllPasPara, &SecOrdAllPasTransComp);

				PrSecOrdAllPasPara->Freq[FreqLoop][DampRateLoop] = SecOrdAllPasPrRecoPara.PrFreq;
				PrSecOrdAllPasPara->DampRate[FreqLoop][DampRateLoop]= SecOrdAllPasPrRecoPara.PrDampRate;


				PrSecOrdAllPasPara->FreqErr[FreqLoop][DampRateLoop] = SecOrdAllPasPrRecoPara.FreqErr;
				PrSecOrdAllPasPara->DampRateErr[FreqLoop][DampRateLoop] = SecOrdAllPasPrRecoPara.DampRateErr;

			}
		}
}
*/



