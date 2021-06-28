/*
 * FisOrdHigPassErr.c
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

static BasicAudio_FilterPara FisOrdHigPasPara;
static BasicAudio_BiquadPara FisOrdHigPasBiquadPara;
static BasicAudio_TransPara FisOrdHigPasTransComp;
static BasicAudio_RecoPara FisOrdHigPasPrRecoPara;

void GetFisOrdHigPassErr(BasicAudio_GetFisOrdHigPasPara *PrFirOrdHigPasPara)
{
	for(int32_t FreqLoop = 0; FreqLoop < FREQNUM; FreqLoop ++)
		{
			FisOrdHigPasPara.Freq = FISFREQ * powf(FREQRATIO, FreqLoop);
			FirOrdHigPasFunc(&FisOrdHigPasPara);

			memset(FisOrdHigPasTransComp.fNumeratorR, 0, sizeof(float)*SAMPLES_FFT/2);
			memset(FisOrdHigPasTransComp.fNumeratorI, 0, sizeof(float)*SAMPLES_FFT/2);
			memset(FisOrdHigPasTransComp.fDenominator, 0, sizeof(float)*SAMPLES_FFT/2);

			for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
			{

				WhiteNoiseFunc(FisOrdHigPasBiquadPara.FilterInput);
				BiquadFunc(&FisOrdHigPasBiquadPara, &FisOrdHigPasPara);
				pWetchSingleLoop(&FisOrdHigPasTransComp, &FisOrdHigPasBiquadPara);
			}

			GetTransfunc(&FisOrdHigPasTransComp);
			PrFisOrdHigPasFunc(&FisOrdHigPasPrRecoPara, &FisOrdHigPasPara, &FisOrdHigPasTransComp);

			PrFirOrdHigPasPara->PrFreq[FreqLoop] = FisOrdHigPasPrRecoPara.PrFreq;
			PrFirOrdHigPasPara->PrFreqErr[FreqLoop] = FisOrdHigPasPrRecoPara.FreqErr;
		}
}


*/
