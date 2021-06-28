/*
 * SecOrdLowPassErr.c
 *
 *  Created on: 2021��5��20��
 *      Author: Brisonus-DELL
 */



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

static BasicAudio_FilterPara SecOrdLowPasPara;
static BasicAudio_RecoPara SecOrdLowPasErr;


void GetSecOrdLowPasFreqErr(BasicAudio_RecoPara *FreqErr, BasicAudio_FilterPara *SecOrdLowPas_Freq);


void GetSecOrdLowPassErr(BasicAudio_GetSecOrdLowPasPara *PrSecOrdLowPasPara)
{
	/*for(int FreqLoop = 0; FreqLoop < FREQNUM; FreqLoop ++ )
		{
			PrSecOrdLowPasPara->Freq = FISFREQ * powf(FREQRATIO, FreqLoop);

			for(int DampRateLoop = 0; DampRateLoop < QNUM; DampRateLoop++)
			{
				PrSecOrdLowPasPara->DampRate = FISQ * powf(QRATIO, DampRateLoop);

				SecOrdLowPasFunc(PrSecOrdLowPasPara);
			}
		}*/

	SecOrdLowPasPara.Freq =1000.0;
	SecOrdLowPasPara.DampRate = 10.0f;

	SecOrdLowPasFunc(&SecOrdLowPasPara);

	GetSecOrdLowPasFreqErr(&SecOrdLowPasErr, &SecOrdLowPasPara);

	/*InitMatrix(&TransPara);
	for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
	{
		WhiteNoiseFunc(BiquadPara.FilterInput);
		BiquadFunc(&BiquadPara, &SecOrdLowPasPara);
		pWetchSingleLoop(&TransPara, &BiquadPara);
	}

	GetTransfunc(&TransPara);
	PrSecOrdLowPasFunc(&GetFreqErr, &SecOrdLowPasPara, &TransPara);

	memset(TransPara.fNumeratorR, 0, sizeof(float)*SAMPLES_FFT/2);
	memset(TransPara.fNumeratorI, 0, sizeof(float)*SAMPLES_FFT/2);
	memset(TransPara.fDenominator, 0, sizeof(float)*SAMPLES_FFT/2);

	if (SecOrdLowPasPara.Freq < 2000)
	{
		for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
		{
			SinFunc(BiquadPara.FilterInput, SecOrdLowPasPara.Freq);

			BiquadFunc(&BiquadPara, &SecOrdLowPasPara);
			pWetchSingleLoop(&TransPara, &BiquadPara);
		}
		GetTransfunc(&TransPara);
	}
	else
	{
		for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
		{
			SinFunc(BiquadPara.FilterInput, SecOrdLowPasPara.Freq);

			BiquadFunc(&BiquadPara, &SecOrdLowPasPara);
			pWetchSingleLoop(&TransPara, &BiquadPara);
		}
		GetTransfunc(&TransPara);
	}


	PrSecOrdLowPasFunc(&GetFreqErr, &SecOrdLowPasPara, &TransPara);


	//B = GetFreqErr.PrDampRate;*/
}


void GetSecOrdLowPasFreqErr(BasicAudio_RecoPara *FreqErr, BasicAudio_FilterPara *SecOrdLowPas_Freq)
{
	BasicAudio_BiquadPara BiquadPara_Freq;
	BasicAudio_TransPara  TransPara_Freq;

	GetTransfunc(&TransPara_Freq);

	for(int AverageLoop = 0; AverageLoop < AVERAGE_NUM; AverageLoop ++)
	{
		WhiteNoiseFunc(BiquadPara_Freq.FilterInput);
		BiquadFunc(&BiquadPara_Freq, &SecOrdLowPasPara);
		pWetchSingleLoop(&TransPara_Freq, &BiquadPara_Freq);
	}

	GetTransfunc(&TransPara_Freq);

	SecOrdLowPasFreqErr(FreqErr, SecOrdLowPas_Freq, &TransPara_Freq);
}
