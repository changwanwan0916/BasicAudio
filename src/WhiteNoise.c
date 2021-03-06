/*
 * WhiteNoise.c
 *
 *  Created on: 2021??5??18??
 *      Author: Brisonus-DELL
 */

#include<stdint.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <builtins.h>

#include"WhiteNoise.h"

static int32_t lRandNoise;
static float SinTime;



void WhiteNoiseFunc(float *InputData)
{
		for(uint32_t WhiteNoiseLoop = 0; WhiteNoiseLoop < 3600; WhiteNoiseLoop ++)
		{
			lRandNoise = rand() - 0x40000000 ;
			InputData[WhiteNoiseLoop] = conv_float_by(lRandNoise, -31);

		}
}


/*void SinFunc(float InputData[], float Frequency)
{
	for(uint32_t SinLoop = 0; SinLoop < BLOCK_SIZE; SinLoop++)
	{
		SinTime += SAMPLE_TIME;
		InputData[SinLoop] = sinf(2 * PI * Frequency * SinTime);
	}
}*/


/*
static int32_t RandomSeed[SEEDSNUM] = {
	#include "RandSeed.txt"
	};

float RandomFunc(int *SeedsData, int32_t SeedNum, int32_t SeedsMax);
void UpdataFunc(int32_t *GetNewSeeds, int32_t NewSeedData, int32_t SeedsNum);

//White Noise: Generate white noise signal as input signal
void WhiteNoiseFunc(float InputData[])
{
	for(uint32_t WhiteNoiseLoop = 0; WhiteNoiseLoop < BLOCK_SIZE; WhiteNoiseLoop ++)
	{
		InputData[WhiteNoiseLoop] = RandomFunc(RandomSeed, SEEDSNUM, MAXSEED);
	}
}

//random number generate function:use random seeds to generate new random number
float RandomFunc(int *SeedsData, int32_t SeedNum, int32_t SeedsMax)
{
	int32_t Ult;
	float RandomData;

	Ult = SeedsData[0] - SeedsData[SeedNum - 1];
	Ult = Ult % SeedsMax;

	RandomData = (float)Ult / (float)SeedsMax;

	UpdataFunc(SeedsData, Ult, SeedNum);

	return RandomData;
}

//random number generate function??move data to the left,complement end use new data
void UpdataFunc(int32_t *GetNewSeeds, int32_t NewSeedData, int32_t SeedsNum)
{

	for(int32_t ii = 1; ii < SeedsNum; ii++)
	{
		GetNewSeeds[ii - 1] = GetNewSeeds[ii];
		GetNewSeeds[SeedsNum - 1] = NewSeedData;
	}

}

*/
