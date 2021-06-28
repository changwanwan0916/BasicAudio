/*
 * Filter.h
 *
 *  Created on: 2021��5��18��
 *      Author: Brisonus-DELL
 */

#ifndef FILTER_H_
#define FILTER_H_

#include"BasicAudioTest.h"

#define     NUM_DEN_ORDER                              (3u)
#define     FILTERSECTION                              (1u)
#define     PI                                         (3.1415926f)

typedef struct
{
	float Den[NUM_DEN_ORDER];
	float Num[NUM_DEN_ORDER];

	float Freq;
	float Gain;
	float DampRate;

	float Omega;

	float Coeff;
}BasicAudio_FilterPara;

typedef struct
{
	float Variable1;
	float Variable2;
	float variable3;

	float variable4;
	float variable5;
	float variable6;
	float variable7;
	float variable8;
	float variable9;
	float variable10;

	float variable11;
	float variable12;
	float variable13;
	float variable14;
	float variable15;

}BasicAudio_FilterVariable;


typedef struct
{
	float FilterInput[BLOCK_SIZE];
	float FilterOutput[BLOCK_SIZE];

	float pm FilterCoeff[5 * FILTERSECTION];
	float dm FilterState[2 * FILTERSECTION];

}BasicAudio_BiquadPara;


void FirOrdLowPasFunc(BasicAudio_FilterPara *FirOrdLowPasPara);
void SecOrdLowPasFunc(BasicAudio_FilterPara *SecOrdLowPasPara);
void FirOrdHigPasFunc(BasicAudio_FilterPara *FirOrdHigPasPara);
void SecOrdHigPasFunc(BasicAudio_FilterPara *SecOrdHigPasPara);
void SecOrdAllPasFunc(BasicAudio_FilterPara *SecOrdAllPasPara);
void SecOrdLowSheFunc(BasicAudio_FilterPara *SecOrdLowShePara);
void SecOrdHigSheFunc(BasicAudio_FilterPara *SecOrdHigShePara);
void PeakingFunc(BasicAudio_FilterPara *PeakingPara);

void BiquadFunc(BasicAudio_BiquadPara *FilterPara,BasicAudio_FilterPara *GetCoeff);

#endif /* FILTER_H_ */
