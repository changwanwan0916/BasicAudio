/*
 * RecoPara.h
 *
 *  Created on: 2021��5��18��
 *      Author: Brisonus-DELL
 */

#ifndef RECOPARA_H_
#define RECOPARA_H_

#include"Filter.h"
#include"Transfunc.h"

typedef struct
{
	float PrFreq;
	float PrGain;
	float PrDampRate;

	float FreqErr;
	float GainErr;
	float DampRateErr;

}BasicAudio_RecoPara;


typedef struct
{
	float BouVal;
	int BouValNum;

	float BouValL;
	float BouValR;

	float CorBouValL;
	float CorBouValR;

	float BouValPara;
}BasicAudio_InterpPara;

typedef struct
{
	float ResoFreq;
	float TransFuncFreq[SAMPLES_FFT/2];

}BasicAudio_FreqData;


void PrFirOrdLowPasFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData);

void SecOrdLowPasFreqErr(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData);
void SecOrdLowPasQErr(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData);

//void PrSecOrdLowPasFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData);
void PrFisOrdHigPasFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData);
void PrSecOrdHigPasFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData);
void PrSecOrdAllPasFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData);
void PrSecOrdLowSheFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetFilterPara, BasicAudio_TransPara *GetTransData);
void PrPeakingFunc(BasicAudio_RecoPara *GetRecoPara, BasicAudio_FilterPara *GetPeakingPara, BasicAudio_TransPara *GetTransData);

float MaxValFunc(float Data[]);
#endif /* RECOPARA_H_ */
