/*
 * Mixter.c
 *
 *  Created on: 2021Äê6ÔÂ21ÈÕ
 *      Author: Brisonus-DELL
 */

#include<stdint.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

#include"Mixter.h"
#include"WhiteNoise.h"
#include"Transfunc.h"


static float W[3] = {0.3, 0.3, 0.4};
//static float OutputData[BLOCK_SIZE];


void MixterFunc(BasicAudio_MixterPara *MixterPara)
{

	MixterPara->Freq1 = 2000;
	MixterPara->Freq2 = 4000;
	MixterPara->Freq3 = 5000;

	SinFunc(MixterPara->MixInputData1, MixterPara->Freq1);
	SinFunc(MixterPara->MixInputData2, MixterPara->Freq2);
	SinFunc(MixterPara->MixInputData3, MixterPara->Freq3);

	for(int32_t MixterLoop = 0; MixterLoop < BLOCK_SIZE; MixterLoop ++)
	{
		MixterPara->MixOutputData[MixterLoop] = MixterPara->MixInputData1[MixterLoop] * W[0] + MixterPara->MixInputData2[MixterLoop] * W[1] + MixterPara->MixInputData3[MixterLoop] * W[2];
	}

}
