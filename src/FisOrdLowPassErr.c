/*
 * FisOrdLowPassErr.c
 *
 *  Created on: 2021��5��20��
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


static BasicAudio_FilterPara FisOrdLowPasPara;
static BasicAudio_BiquadPara FisOrdLowPasBiquadPara;
static BasicAudio_TransPara FisOrdLowPasTransComp;
static BasicAudio_RecoPara FisOrdLowPasPrRecoPara;


//Get the parameter error of the first-order low-pass filter
void GetFisOrdLowPassErr(BasicAudio_GetFirOrdLowPasPara *PrFirOrdLowPasPara)
{
	for(int32_t FreqLoop = 0; FreqLoop < FREQNUM; FreqLoop ++)
	{
		FisOrdLowPasPara.Freq = FISFREQ * powf(FREQRATIO, FreqLoop);
		FirOrdLowPasFunc(&FisOrdLowPasPara);

		memset(FisOrdLowPasTransComp.fNumeratorR, 0, sizeof(float)*SAMPLES_FFT/2);
		memset(FisOrdLowPasTransComp.fNumeratorI, 0, sizeof(float)*SAMPLES_FFT/2);
		memset(FisOrdLowPasTransComp.fDenominator, 0, sizeof(float)*SAMPLES_FFT/2);

		for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
		{

			WhiteNoiseFunc(FisOrdLowPasBiquadPara.FilterInput);
			BiquadFunc(&FisOrdLowPasBiquadPara, &FisOrdLowPasPara);
			pWetchSingleLoop(&FisOrdLowPasTransComp, &FisOrdLowPasBiquadPara);
		}

		GetTransfunc(&FisOrdLowPasTransComp);
		PrFirOrdLowPasFunc(&FisOrdLowPasPrRecoPara, &FisOrdLowPasPara, &FisOrdLowPasTransComp);

		PrFirOrdLowPasPara->PrFreq[FreqLoop] = FisOrdLowPasPrRecoPara.PrFreq;
		PrFirOrdLowPasPara->PrFreqErr[FreqLoop] = FisOrdLowPasPrRecoPara.FreqErr;
	}
}

*/
