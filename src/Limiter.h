/*
 * Limiter.h
 *
 *  Created on: 2021��6��18��
 *      Author: Brisonus-DELL
 */

#ifndef LIMITER_H_
#define LIMITER_H_

#include"BasicAudioTest.h"

#define     ATTACK_TIME                                (0.0005f)
#define     RELEASE_TIME                               (0.1f)
#define     THRESHOLD                                  (-10.0f)

typedef struct
{
	float LimInputData[BLOCK_SIZE];
	float LimOutputData[BLOCK_SIZE];

	float aA;
	float aR;

	float xdB[BLOCK_SIZE];
	float xSc[BLOCK_SIZE];
	float gC[BLOCK_SIZE];
	float gS[BLOCK_SIZE];
	float gLin[BLOCK_SIZE];

}BasicAudio_LimiterPara;

void LimiterFunc(BasicAudio_LimiterPara *LimiterPara);
#endif /* LIMITER_H_ */