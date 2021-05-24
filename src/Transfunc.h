/*
 * Transfunc.h
 *
 *  Created on: 2021��5��18��
 *      Author: Brisonus-DELL
 */

#ifndef TRANSFUNC_H_
#define TRANSFUNC_H_

#define     SAMPLES_FFT                                (2048u)
#define     AVERAGE_NUM                                (100u)

#define     RESOFREQ                                   (Fs/SAMPLES_FFT)



void pWetchSingleLoop(float fNumeratorR[],float fNumeratorI[],float fDenominator[], float InputData[], float FilterOutput[]);
void GetTransfunc(float *TransFuncAmp, float *TransFuncPhase, float fNumeratorR[],float fNumeratorI[],float fDenominator[]);


#endif /* TRANSFUNC_H_ */
