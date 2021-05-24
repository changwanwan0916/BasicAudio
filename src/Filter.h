/*
 * Filter.h
 *
 *  Created on: 2021��5��18��
 *      Author: Brisonus-DELL
 */

#ifndef FILTER_H_
#define FILTER_H_

#define     NUM_DEN_ORDER                              (3u)
#define     FILTERSECTION                              (1u)
#define     PI                                         (3.1415926f)
#define     SAMPLE_TIME                                (0.0000208333333f)

typedef struct
{
	float Den[NUM_DEN_ORDER];
	float Num[NUM_DEN_ORDER];

	float Freq;
	float Gain;
	float DampRate;

}BasicAudio_FilterPara;

typedef struct
{
	float pm FilterCoeff[5 * FILTERSECTION];
	float dm FilterState[2 * FILTERSECTION];

}BasicAudio_Filter;

void FisOrdLowPassFunc(BasicAudio_FilterPara *FisOrdLowPassPara);
void SecOrdLowPassFunc(BasicAudio_FilterPara *SecOrdLowPassPara);
void FisOrdHigPassFunc(BasicAudio_FilterPara *FisOrdHigPassPara);
void SecOrdHigPassFunc(BasicAudio_FilterPara *FisOrdHigPassPara);
void FisOrdAllPassFunc(BasicAudio_FilterPara *FisOrdAllPassPara);
void SecOrdAllPassFunc(BasicAudio_FilterPara *SecOrdAllPassPara);

void FilterFunc(float Filter_Output[], float Filter_Input[], BasicAudio_FilterPara *GetCoeff);

#endif /* FILTER_H_ */
