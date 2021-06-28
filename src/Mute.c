/*
 * Mute.c
 *
 *  Created on: 2021Äê6ÔÂ21ÈÕ
 *      Author: Brisonus-DELL
 */


#include<stdint.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

#include"Mute.h"
#include"WhiteNoise.h"

void MuteFadeInFunc(BasicAudio_MutePara *FadeInPara);
void MuteFadeOutFunc(BasicAudio_MutePara *FadeOutPara);


static float Frame_Size = 0;
static float HalfCosWin[BLOCK_SIZE] =
{
	#include"HalfCosWin.txt"
};

void MuteFunc(BasicAudio_MutePara *MutePara)
{

	WhiteNoiseFunc(MutePara->MuteInputData);

	if(Frame_Size < 2)
	{
		if(Frame_Size < 1)
		{
			MuteFadeInFunc(MutePara);
		}
		else
		{
			for(int32_t MuteLoop = 0; MuteLoop < BLOCK_SIZE; MuteLoop++)
			{

				MutePara->MutOutputData[MuteLoop] = MutePara->MuteInputData[MuteLoop];
			}
		}


		Frame_Size++;
	}
	else
	{
		if(Frame_Size < 3)
		{
			MuteFadeOutFunc(MutePara);
			Frame_Size++;
		}
		else
		{
			for(int32_t MuteLoop = 0; MuteLoop < BLOCK_SIZE; MuteLoop++)
			{

				MutePara->MutOutputData[MuteLoop] = 0;
			}
		}
	}

}

void MuteFadeInFunc(BasicAudio_MutePara *FadeInPara)
{
	for(int32_t FadeInLoop = 0; FadeInLoop < BLOCK_SIZE; FadeInLoop ++)
	{
		FadeInPara->MutOutputData[FadeInLoop] = FadeInPara->MuteInputData[FadeInLoop] * HalfCosWin[BLOCK_SIZE - FadeInLoop];
	}
}

void MuteFadeOutFunc(BasicAudio_MutePara *FadeOutPara)
{
	for(int32_t FadeOutLoop = 0; FadeOutLoop < BLOCK_SIZE; FadeOutLoop ++)
	{
		FadeOutPara->MutOutputData[FadeOutLoop] = FadeOutPara->MuteInputData[FadeOutLoop] * HalfCosWin[FadeOutLoop];
	}
}

