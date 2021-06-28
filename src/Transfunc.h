/*
 * Transfunc.h
 *
 *  Created on: 2021��5��18��
 *      Author: Brisonus-DELL
 */

#ifndef TRANSFUNC_H_
#define TRANSFUNC_H_

#include"Filter.h"

#define     SAMPLES_FFT                                (4096u)
#define     AVERAGE_NUM                                (100u)

#define     RESOFREQ                                   (Fs/SAMPLES_FFT)

typedef struct
{
	float fNumeratorR[SAMPLES_FFT/2];
	float fNumeratorI[SAMPLES_FFT/2];
	float fDenominator[SAMPLES_FFT/2];

	float TransFuncAmp[SAMPLES_FFT/2];
	float TransFuncPhase[SAMPLES_FFT/2];

}BasicAudio_TransPara;


void pWetchSingleLoop( BasicAudio_TransPara *TransComp, BasicAudio_BiquadPara *TransInput);
void GetTransfunc(BasicAudio_TransPara *TransData);
void InitMatrix(BasicAudio_TransPara *InitTransFunc);


#endif /* TRANSFUNC_H_ */
