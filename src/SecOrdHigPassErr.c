/*
 * SecOrdHigPassErr.c
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

static BasicAudio_FilterPara SecOrdHigPasPara;
static BasicAudio_BiquadPara SecOrdHigPasBiquadPara;
static BasicAudio_TransPara SecOrdHigPasTransComp;
static BasicAudio_RecoPara SecOrdHigPasPrRecoPara;

void GetSecOrdHigPassErr(BasicAudio_GetSecOrdHigPasPara *PrSecOrdHigPasPara)
{

	for(int32_t FreqLoop = 0; FreqLoop < FREQNUM; FreqLoop ++ )
	{
		SecOrdHigPasPara.Freq = FISFREQ * powf(FREQRATIO, FreqLoop);
		//SecOrdHigPasPara.Freq =22.8980f;

		for(int32_t DampRateLoop = 0; DampRateLoop < QNUM; DampRateLoop++)
		{
			SecOrdHigPasPara.DampRate = FISQ * powf(QRATIO, DampRateLoop);
			//SecOrdHigPasPara.DampRate = 19.5391f;

			if(SecOrdHigPasPara.Freq == FISFREQ * powf(FREQRATIO, 0) && SecOrdHigPasPara.DampRate == FISQ * powf(QRATIO, 0))
			{
				SecOrdHigPasFunc(&SecOrdHigPasPara);

				memset(SecOrdHigPasTransComp.fNumeratorR, 0, sizeof(float)*SAMPLES_FFT/2);
				memset(SecOrdHigPasTransComp.fNumeratorI, 0, sizeof(float)*SAMPLES_FFT/2);
				memset(SecOrdHigPasTransComp.fDenominator, 0, sizeof(float)*SAMPLES_FFT/2);

				for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
				{
					WhiteNoiseFunc(SecOrdHigPasBiquadPara.FilterInput);
					BiquadFunc(&SecOrdHigPasBiquadPara, &SecOrdHigPasPara);
					pWetchSingleLoop(&SecOrdHigPasTransComp, &SecOrdHigPasBiquadPara);
				}

				GetTransfunc(&SecOrdHigPasTransComp);
				PrSecOrdHigPasFunc(&SecOrdHigPasPrRecoPara, &SecOrdHigPasPara, &SecOrdHigPasTransComp);

				PrSecOrdHigPasPara->Freq[FreqLoop][DampRateLoop] = SecOrdHigPasPrRecoPara.PrFreq;
				PrSecOrdHigPasPara->DampRate[FreqLoop][DampRateLoop] = SecOrdHigPasPrRecoPara.PrDampRate;

				PrSecOrdHigPasPara->FreqErr[FreqLoop][DampRateLoop] = SecOrdHigPasPrRecoPara.FreqErr;
				PrSecOrdHigPasPara->DampRateErr[FreqLoop][DampRateLoop] = SecOrdHigPasPrRecoPara.DampRateErr;
			}
			SecOrdHigPasFunc(&SecOrdHigPasPara);

			memset(SecOrdHigPasTransComp.fNumeratorR, 0, sizeof(float)*SAMPLES_FFT/2);
			memset(SecOrdHigPasTransComp.fNumeratorI, 0, sizeof(float)*SAMPLES_FFT/2);
			memset(SecOrdHigPasTransComp.fDenominator, 0, sizeof(float)*SAMPLES_FFT/2);

			for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
			{
				WhiteNoiseFunc(SecOrdHigPasBiquadPara.FilterInput);
				BiquadFunc(&SecOrdHigPasBiquadPara, &SecOrdHigPasPara);
				pWetchSingleLoop(&SecOrdHigPasTransComp, &SecOrdHigPasBiquadPara);
			}

			GetTransfunc(&SecOrdHigPasTransComp);
			PrSecOrdHigPasFunc(&SecOrdHigPasPrRecoPara, &SecOrdHigPasPara, &SecOrdHigPasTransComp);

			PrSecOrdHigPasPara->Freq[FreqLoop][DampRateLoop] = SecOrdHigPasPrRecoPara.PrFreq;
			PrSecOrdHigPasPara->DampRate[FreqLoop][DampRateLoop] = SecOrdHigPasPrRecoPara.PrDampRate;

			PrSecOrdHigPasPara->FreqErr[FreqLoop][DampRateLoop] = SecOrdHigPasPrRecoPara.FreqErr;
			PrSecOrdHigPasPara->DampRateErr[FreqLoop][DampRateLoop] = SecOrdHigPasPrRecoPara.DampRateErr;
		}
	}
}

void GetSecOrdHigPassErr(BasicAudio_GetSecOrdHigPasPara *PrSecOrdHigPasPara)
{

}
*/





