/*
 * WhiteNoise.c
 *
 *  Created on: 2021��5��18��
 *      Author: Brisonus-DELL
 */

#include<stdint.h>
#include<stdio.h>
#include<math.h>

#include"WhiteNoise.h"

/*random number generate function��move data to the left,complement end use new data*/
void UpdataFunc(int32_t *GetNewSeeds, int32_t NewSeedData, int32_t SeedsNum)
{

	for(int32_t ii = 1; ii < SeedsNum; ii++)
	{
		GetNewSeeds[ii - 1] = GetNewSeeds[ii];
		GetNewSeeds[SeedsNum - 1] = NewSeedData;
	}

}

/*random number generate function:use random seeds to generate new random number*/
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



