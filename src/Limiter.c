/*
 * Limiter.c
 *
 *  Created on: 2021��6��18��
 *      Author: Brisonus-DELL
 */


#include<stdint.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

#include"Limiter.h"
#include"WhiteNoise.h"
#include"BasicAudioTest.h"


void LimiterFunc(BasicAudio_LimiterPara *LimiterPara)
{
	WhiteNoiseFunc(LimiterPara->LimInputData);

	LimiterPara->aA = expf((-logf(9)) / (SAMPLE_FREQUENCY * ATTACK_TIME));
	LimiterPara->aR = expf((-logf(9)) / (SAMPLE_FREQUENCY * RELEASE_TIME));

	for(int32_t LimLoop = 0; LimLoop < BLOCK_SIZE; LimLoop++)
	{
		LimiterPara->xdB[LimLoop] = 20 * log10f(fabs(LimiterPara->LimInputData[LimLoop]));

		if(LimiterPara->xdB[LimLoop] > THRESHOLD)
		{
			LimiterPara->xSc[LimLoop] = THRESHOLD;
		}
		else
		{
			LimiterPara->xSc[LimLoop] = LimiterPara->xdB[LimLoop];
		}

		LimiterPara->gC[LimLoop] = LimiterPara->xSc[LimLoop] - LimiterPara->xdB[LimLoop];

		if(LimLoop == 0)
		{
			LimiterPara->gS[LimLoop] = (1 - LimiterPara->aA) * LimiterPara->gC[LimLoop];
		}
		else
		{
			if(LimiterPara->gS[LimLoop - 1] >= LimiterPara->gC[LimLoop])
			{
				LimiterPara->gS[LimLoop] = LimiterPara->aA * LimiterPara->gS[LimLoop - 1] + (1 - LimiterPara->aA) * LimiterPara->gC[LimLoop];
			}
			else
			{
				LimiterPara->gS[LimLoop] = LimiterPara->aR * LimiterPara->gS[LimLoop - 1] + (1 - LimiterPara->aR) * LimiterPara->gC[LimLoop];
			}
		}

		LimiterPara->gLin[LimLoop] = powf(10, LimiterPara->gS[LimLoop]/20);
		LimiterPara->LimOutputData[LimLoop] = LimiterPara->gLin[LimLoop] * LimiterPara->LimInputData[LimLoop];
	}
}

/*static float LimInput[BLOCK_SIZE];
static float LimOutput[BLOCK_SIZE];
static float LimOutput1[BLOCK_SIZE];
static float dB[BLOCK_SIZE];

static float xdB[BLOCK_SIZE];
static float xSc[BLOCK_SIZE];
static float gC[BLOCK_SIZE];
static float gS[BLOCK_SIZE];
static float gLin[BLOCK_SIZE];


void LimiterFunc(BasicAudio_LimiterPara *LimiterPara)
{
	WhiteNoiseFunc(LimInput);

	LimiterPara->aA = expf((-logf(9)) / (SAMPLE_FREQUENCY * ATTACK_TIME));
	LimiterPara->aR = expf((-logf(9)) / (SAMPLE_FREQUENCY * RELEASE_TIME));

	for(int32_t LimLoop = 0; LimLoop < BLOCK_SIZE; LimLoop++)
	{
		dB[LimLoop] = -10;
		xdB[LimLoop] = 20 * log10f(fabs(LimInput[LimLoop]));

		if(xdB[LimLoop] > THRESHOLD)
		{
			xSc[LimLoop] = THRESHOLD;
		}
		else
		{
			xSc[LimLoop] = xdB[LimLoop];
		}

		gC[LimLoop] = xSc[LimLoop] - xdB[LimLoop];

		if(LimLoop == 0)
		{
			gS[LimLoop] = (1 - LimiterPara->aA) * gC[LimLoop];
		}
		else
		{
			if(gS[LimLoop - 1] >= gC[LimLoop])
			{
				gS[LimLoop] = LimiterPara->aA * gS[LimLoop - 1] + (1 - LimiterPara->aA) * gC[LimLoop];
			}
			else
			{
				gS[LimLoop] = LimiterPara->aR * gS[LimLoop - 1] + (1 - LimiterPara->aR) * gC[LimLoop];
			}
		}

		gLin[LimLoop] = powf(10, gS[LimLoop]/20);
		LimOutput[LimLoop] = gLin[LimLoop] * LimInput[LimLoop];

		LimOutput1[LimLoop] = 20 * log10f(fabs(LimOutput[LimLoop]));
	}
}*/
