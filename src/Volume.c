/*
 * Volume.c
 *
 *  Created on: 2021��6��18��
 *      Author: Brisonus-DELL
 */

#include<stdint.h>
#include<stdio.h>
#include<math.h>

#include"BasicAudioTest.h"
#include"Volume.h"
#include"WhiteNoise.h"

static float VolGainErr1[VOLGAINNUM];

void VolumeFunc(BasicAudio_VolumePara *VolumePara)
{
	WhiteNoiseFunc(VolumePara->VolInput);

	for(int32_t VolGainLoop = 0; VolGainLoop < VOLGAINNUM; VolGainLoop ++)
	{
		VolumePara->VolGain[VolGainLoop] = VOLFISGAIN + VolGainLoop * VOLDISGAIN;
		VolumePara->VolGainAmp[VolGainLoop] = powf(10, VolumePara->VolGain[VolGainLoop]/20);

		VolumePara->SumVolInput = 0;
		VolumePara->SumVolOutput = 0;

		for(int32_t VolInputLoop = 0; VolInputLoop < BLOCK_SIZE; VolInputLoop++)
		{
			VolumePara->VolOutput[VolInputLoop] = VolumePara->VolGainAmp[VolGainLoop] * VolumePara->VolInput[VolInputLoop];

			VolumePara->SumVolInput += VolumePara->VolInput[VolInputLoop];
			VolumePara->SumVolOutput += VolumePara->VolOutput[VolInputLoop];
		}

		VolumePara->VolGainTest[VolGainLoop] = 20 * log10f(VolumePara->SumVolOutput/VolumePara->SumVolInput);
		VolGainErr1[VolGainLoop] = fabs(VolumePara->VolGain[VolGainLoop] - VolumePara->VolGainTest[VolGainLoop]);
	}

}
