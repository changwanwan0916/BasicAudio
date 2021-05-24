/*
 * RecoPara.h
 *
 *  Created on: 2021��5��18��
 *      Author: Brisonus-DELL
 */

#ifndef RECOPARA_H_
#define RECOPARA_H_

#include"Filter.h"

void PrFisOrdLowPassFunc(float *FisOrdLowPassFreq, float GetTransFuncAmp[], float GetTransFuncPhase[]);
float FreqErrFunc(BasicAudio_FilterPara *InputFreq, float PrFreqPara);
float QErrFuc(BasicAudio_FilterPara *InputQ, float PrQPara);
void PrFisOrdHigPassFunc(float *FisOrdHigPassFreq, float GetTransFuncAmp[], float GetTransFuncPhase[]);
void PrFisOrdAllPassFunc(float *FisOrdHigPassFreq, float GetTransFuncAmp[], float GetTransFuncPhase[]);
void PrSecOrdAllPassFunc(float *FisOrdAllPassFreq, float *SecOrdAllPassQ,float GetTransFuncAmp[], float GetTransFuncPhase[]);

void PrSecOrdLowPassFunc(float *FisOrdLowPassFreq, float *SecOrdLowPassQ,float GetTransFuncAmp[], float GetTransFuncPhase[]);
#endif /* RECOPARA_H_ */
