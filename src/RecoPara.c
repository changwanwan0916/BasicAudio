/*
 * RecoPara.c
 *
 *  Created on: 2021��5��18��
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


static int SecOrdHigPasNum,Num;
static int Num1;

void InterpFunc1(BasicAudio_InterpPara *GetIntPara, BasicAudio_TransPara *GetTransData);
void InterpFunc2(BasicAudio_InterpPara *GetIntPara, BasicAudio_TransPara *GetTransData);
void InterpFunc3(BasicAudio_InterpPara *GetIntPara, BasicAudio_TransPara *GetTransData);
void InterpFunc4(BasicAudio_InterpPara *GetIntPara, BasicAudio_TransPara *GetTransData);
void InterpFunc5(BasicAudio_InterpPara *GetIntPara, BasicAudio_TransPara *GetTransData);
void InterpFunc6(BasicAudio_InterpPara *GetIntPara, BasicAudio_TransPara *GetTransData);
void FreqDatafunc(BasicAudio_FreqData *GetFreqData);

void FilterErrFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara);


/*Calculate the parameters of the first-order low-pass filter */
void PrFirOrdLowPasFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData)
{
	BasicAudio_InterpPara GetIntPara;
	GetIntPara.BouVal = -45;

	InterpFunc1(&GetIntPara, GetTransData);

	GetRecoPara->PrFreq = GetIntPara.BouValPara;

	FilterErrFunc(GetRecoPara, GetFilterPara);
}

/*Calculate the parameters of the second order low pass filter */
void SecOrdLowPasFreqErr(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData)
{
	BasicAudio_InterpPara GetIntPara;

    GetIntPara.BouVal = -90;

    InterpFunc1(&GetIntPara, GetTransData);

    GetRecoPara->PrFreq = GetIntPara.BouValPara;

    GetRecoPara->FreqErr = fabs(GetRecoPara->PrFreq - GetFilterPara->Freq)/GetFilterPara->Freq;

    //FilterErrFunc(GetRecoPara, GetFilterPara);
}

void SecOrdLowPasQErr(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData)
{
	BasicAudio_InterpPara GetIntPara;

	if(GetFilterPara->Freq <2000)
	{
		GetIntPara.BouVal = GetFilterPara->Freq;
	}
	else
	{
		GetIntPara.BouVal = GetRecoPara->PrFreq;
	}
	InterpFunc2(&GetIntPara, GetTransData);

	GetRecoPara->PrDampRate = powf(10.0,GetIntPara.BouValPara/20);

	GetRecoPara->DampRateErr = fabs(GetRecoPara->PrDampRate - GetFilterPara->DampRate);
}



/*Calculate the parameters of the first order high pass filter */
void PrFisOrdHigPasFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData)
{
	BasicAudio_InterpPara GetIntPara;
	GetIntPara.BouVal = 20 * log10f(1/sqrtf(2));

	InterpFunc4(&GetIntPara, GetTransData);

	GetRecoPara->PrFreq = GetIntPara.BouValPara;

    GetIntPara.BouVal = GetFilterPara->Freq;
    InterpFunc2(&GetIntPara, GetTransData);

    GetRecoPara->PrDampRate = powf(10.0,GetIntPara.BouValPara/20);

	FilterErrFunc(GetRecoPara, GetFilterPara);
}

/*Calculate the parameters of the second order high pass filter */
void PrSecOrdHigPasFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData)
{
	BasicAudio_InterpPara GetIntPara;
	BasicAudio_FreqData PrFreqData;

	FreqDatafunc(&PrFreqData);
	for(int32_t FreqLoop1 = 0; FreqLoop1 < SAMPLES_FFT/2; FreqLoop1 ++)
	{
		if(PrFreqData.TransFuncFreq[FreqLoop1] > (0.6 * GetFilterPara->Freq))
		{

			Num = FreqLoop1;
			break;
		}

	}

	for(int32_t PhaseLoop = Num; PhaseLoop < SAMPLES_FFT/2; PhaseLoop++)
	{
		if(GetTransData->TransFuncPhase[PhaseLoop] < 90)
		{
			GetIntPara.BouValNum = PhaseLoop;
			break;
		}
	}

	GetIntPara.BouValR = GetTransData->TransFuncPhase[GetIntPara.BouValNum];
	GetIntPara.BouValL = GetTransData->TransFuncPhase[GetIntPara.BouValNum - 1];

	GetIntPara.CorBouValR = PrFreqData.TransFuncFreq[GetIntPara.BouValNum];

	GetRecoPara->PrFreq = GetIntPara.CorBouValR - (90 - GetIntPara.BouValR)/(GetIntPara.BouValL - GetIntPara.BouValR) * PrFreqData.ResoFreq;

	GetIntPara.BouVal = GetRecoPara->PrFreq;

	InterpFunc2(&GetIntPara, GetTransData);

	GetRecoPara->PrDampRate = powf(10, GetIntPara.BouValPara/20);

	FilterErrFunc(GetRecoPara, GetFilterPara);
}

/*Calculate the parameters of the second order All pass filter */
void PrSecOrdAllPasFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData)
{
	BasicAudio_FreqData PrFreqData;
	FreqDatafunc(&PrFreqData);

	for (int PhaseLoop = 0; PhaseLoop < SAMPLES_FFT/2; PhaseLoop++)
	{
		if(GetTransData->TransFuncPhase[PhaseLoop]  > 0 && PrFreqData.TransFuncFreq[PhaseLoop] > 0.5 * GetFilterPara->Freq)
		{

			GetTransData->TransFuncPhase[PhaseLoop] = GetTransData->TransFuncPhase[PhaseLoop] - 360;
		}
	}


	BasicAudio_InterpPara GetIntPara;
	GetIntPara.BouVal = -180;

	InterpFunc1(&GetIntPara, GetTransData);

	GetRecoPara->PrFreq = GetIntPara.BouValPara;

	GetIntPara.BouVal = GetRecoPara->PrFreq/2;
	InterpFunc3(&GetIntPara, GetTransData);

	GetRecoPara->PrDampRate = 2/(3 * tanf(-GetIntPara.BouValPara * PI / 180 /2));

	FilterErrFunc(GetRecoPara, GetFilterPara);
}

/*Calculate the parameters of the second order Low shelf filter */
void PrSecOrdLowSheFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData)
{
	float a;

	GetRecoPara->PrGain = GetTransData->TransFuncAmp[0];

	BasicAudio_InterpPara GetIntPara;

	GetIntPara.BouVal = GetRecoPara->PrGain/2;
	if(GetFilterPara->Gain > 0)
	{
		InterpFunc5(&GetIntPara, GetTransData);
	}
	else
	{
		InterpFunc4(&GetIntPara, GetTransData);
	}

	GetRecoPara->PrFreq = GetIntPara.BouValPara;

	GetIntPara.BouVal = GetRecoPara->PrFreq;
	InterpFunc3(&GetIntPara, GetTransData);

	a = powf(10, GetRecoPara->PrGain/80);
	GetRecoPara->PrDampRate = (tanf((-GetIntPara.BouValPara * PI / 180/2 )) *a)/(powf(a, 2) - 1);

	FilterErrFunc(GetRecoPara, GetFilterPara);
}

/*Calculate the parameters of the second order peaking filter */
void PrPeakingFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData)
{
	static float m,n,b,q1,q2;

	BasicAudio_InterpPara GetIntPara;
    GetIntPara.BouVal = 0;

	if (GetFilterPara->Gain > 0)
	{
		InterpFunc1(&GetIntPara, GetTransData);
	}
	else
	{
		InterpFunc6(&GetIntPara, GetTransData);
	}

	GetRecoPara->PrFreq = GetIntPara.BouValPara;

	GetIntPara.BouVal = GetRecoPara->PrFreq;
	InterpFunc2(&GetIntPara, GetTransData);

	GetRecoPara->PrGain = GetIntPara.BouValPara;

	GetIntPara.BouVal = (GetRecoPara->PrFreq/2);
	InterpFunc3(&GetIntPara, GetTransData);

	b = pow(10, GetRecoPara->PrGain/40);
	m = tanf(GetIntPara.BouValPara *PI/180);
	n = b - 1/b;

	q1 = (1.5 * n - sqrtf(2.25 * powf(n, 2) - 9 * powf(m, 2)))/(4.5 * m);
	q2 = (1.5 * n + sqrtf(2.25 * powf(n, 2) - 9 * powf(m, 2)))/(4.5 * m);

	if (fabs(GetFilterPara->DampRate - q1) <= fabs(GetFilterPara->DampRate - q2))
	{
		GetRecoPara->PrDampRate = q1;
	}
	else
	{
		GetRecoPara->PrDampRate = q2;
	}

	FilterErrFunc(GetRecoPara, GetFilterPara);
}


/*Interpolate the monotonically decreasing phase characteristic curve*/
void InterpFunc1(BasicAudio_InterpPara *GetIntPara, BasicAudio_TransPara *GetTransData)
{

	BasicAudio_FreqData PrFreqData;
	FreqDatafunc(&PrFreqData);

	for (int32_t  BouValLoop = 2; BouValLoop < SAMPLES_FFT/2; BouValLoop ++)
		{
			if(GetTransData->TransFuncPhase[BouValLoop] < GetIntPara->BouVal)
			{
				GetIntPara->BouValNum = BouValLoop;
			   break;
			}
		}

	GetIntPara->BouValL = GetTransData->TransFuncPhase[GetIntPara->BouValNum - 1];
	GetIntPara->BouValR =GetTransData->TransFuncPhase[GetIntPara->BouValNum];

	GetIntPara->CorBouValR = PrFreqData.TransFuncFreq[GetIntPara->BouValNum];

	GetIntPara->BouValPara =GetIntPara->CorBouValR - ((GetIntPara->BouVal - GetIntPara->BouValR) / (GetIntPara->BouValL - GetIntPara->BouValR)) * PrFreqData.ResoFreq;
}

/*Interpolate frequency*/
void InterpFunc2(BasicAudio_InterpPara *GetIntPara, BasicAudio_TransPara *GetTransData)
{
	BasicAudio_FreqData PrFreqData;
	FreqDatafunc(&PrFreqData);

	for (int32_t  BouValLoop = 0; BouValLoop < SAMPLES_FFT/2; BouValLoop ++)
	{
		if(PrFreqData.TransFuncFreq[BouValLoop] >= GetIntPara->BouVal)
		{
			GetIntPara->BouValNum = BouValLoop;
		   break;
		}
	}

	GetIntPara->BouValR = PrFreqData.TransFuncFreq[GetIntPara->BouValNum];

	GetIntPara->CorBouValL = GetTransData->TransFuncAmp[GetIntPara->BouValNum - 1];
	GetIntPara->CorBouValR = GetTransData->TransFuncAmp[GetIntPara->BouValNum];

	GetIntPara->BouValPara = GetIntPara->CorBouValR - (GetIntPara->BouVal - GetIntPara->BouValR) / PrFreqData.ResoFreq * (GetIntPara->CorBouValL - GetIntPara->CorBouValR);

}

/**/
void InterpFunc3(BasicAudio_InterpPara *GetIntPara, BasicAudio_TransPara *GetTransData)
{
	BasicAudio_FreqData PrFreqData;
	FreqDatafunc(&PrFreqData);

	for (int32_t  BouValLoop = 0; BouValLoop < SAMPLES_FFT/2; BouValLoop ++)
	{
		if(PrFreqData.TransFuncFreq[BouValLoop] >= GetIntPara->BouVal)
		{
			GetIntPara->BouValNum = BouValLoop;
		   break;
		}
	}

	GetIntPara->BouValR = PrFreqData.TransFuncFreq[GetIntPara->BouValNum];

	GetIntPara->CorBouValL = GetTransData->TransFuncPhase[GetIntPara->BouValNum - 1];
	GetIntPara->CorBouValR = GetTransData->TransFuncPhase[GetIntPara->BouValNum];

	GetIntPara->BouValPara = GetIntPara->CorBouValR - (GetIntPara->BouVal - GetIntPara->BouValR) / PrFreqData.ResoFreq *(GetIntPara->CorBouValL - GetIntPara->CorBouValR);

}

/*Interpolate the monotonically increasing amplitude characteristic curve*/
void InterpFunc4(BasicAudio_InterpPara *GetIntPara, BasicAudio_TransPara *GetTransData)
{
	BasicAudio_FreqData PrFreqData;
	FreqDatafunc(&PrFreqData);

	for (int32_t  BouValLoop = 0; BouValLoop < SAMPLES_FFT/2; BouValLoop ++)
		{
			if(GetTransData->TransFuncAmp[BouValLoop] >= GetIntPara->BouVal)
			{
				GetIntPara->BouValNum = BouValLoop;
			   break;
			}
		}

	GetIntPara->BouValL = GetTransData->TransFuncAmp[GetIntPara->BouValNum - 1];
	GetIntPara->BouValR = GetTransData->TransFuncAmp[GetIntPara->BouValNum];

	GetIntPara->CorBouValR = PrFreqData.TransFuncFreq[GetIntPara->BouValNum];

	GetIntPara->BouValPara = GetIntPara->CorBouValR - (GetIntPara->BouVal - GetIntPara->BouValR) / (GetIntPara->BouValL - GetIntPara->BouValR) * PrFreqData.ResoFreq;
}

void InterpFunc5(BasicAudio_InterpPara *GetIntPara, BasicAudio_TransPara *GetTransData)
{
	BasicAudio_FreqData PrFreqData;
	FreqDatafunc(&PrFreqData);

	for (int32_t  BouValLoop = 0; BouValLoop < SAMPLES_FFT/2; BouValLoop ++)
		{
			if(GetTransData->TransFuncAmp[BouValLoop] <= GetIntPara->BouVal)
			{
				GetIntPara->BouValNum = BouValLoop;
			   break;
			}
		}

	GetIntPara->BouValL = GetTransData->TransFuncAmp[GetIntPara->BouValNum - 1];
	GetIntPara->BouValR = GetTransData->TransFuncAmp[GetIntPara->BouValNum];

	GetIntPara->CorBouValR = PrFreqData.TransFuncFreq[GetIntPara->BouValNum];

	GetIntPara->BouValPara = GetIntPara->CorBouValR - (GetIntPara->BouVal - GetIntPara->BouValR) / (GetIntPara->BouValL - GetIntPara->BouValR) * PrFreqData.ResoFreq;
}

void InterpFunc6(BasicAudio_InterpPara *GetIntPara, BasicAudio_TransPara *GetTransData)
{

	BasicAudio_FreqData PrFreqData;
	FreqDatafunc(&PrFreqData);

	for (int32_t  BouValLoop = 0; BouValLoop < SAMPLES_FFT/2; BouValLoop ++)
		{
			if(GetTransData->TransFuncPhase[BouValLoop] > GetIntPara->BouVal)
			{
				GetIntPara->BouValNum = BouValLoop;
			   break;
			}
		}

	GetIntPara->BouValL = GetTransData->TransFuncPhase[GetIntPara->BouValNum - 1];
	GetIntPara->BouValR =GetTransData->TransFuncPhase[GetIntPara->BouValNum];

	GetIntPara->CorBouValR = PrFreqData.TransFuncFreq[GetIntPara->BouValNum];

	GetIntPara->BouValPara =GetIntPara->CorBouValR - ((GetIntPara->BouVal - GetIntPara->BouValR) / (GetIntPara->BouValL - GetIntPara->BouValR)) * PrFreqData.ResoFreq;
}

/*Get frequency value*/
void FreqDatafunc(BasicAudio_FreqData *GetFreqData)
{
	GetFreqData->ResoFreq = ((float)SAMPLE_FREQUENCY/(float)BLOCK_SIZE);

	for(int32_t CorrNum = 0; CorrNum < SAMPLES_FFT/2; CorrNum ++)
	{
		GetFreqData->TransFuncFreq[CorrNum] = GetFreqData->ResoFreq * CorrNum;
	}

}

void FilterErrFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara)
{
	GetRecoPara->FreqErr = fabs(GetRecoPara->PrFreq - GetFilterPara->Freq)/GetFilterPara->Freq;
	GetRecoPara->GainErr = fabs(GetRecoPara->PrGain - GetFilterPara->Gain);
	GetRecoPara->DampRateErr = fabs(GetRecoPara->PrDampRate - GetFilterPara->DampRate);
}

