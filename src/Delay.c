/*
 * Delay.c
 *
 *  Created on: 2021��6��18��
 *      Author: Brisonus-DELL
 */


#include<stdint.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

#include"Delay.h"
#include"WhiteNoise.h"

static int WriteData = DELAY_NUN;
static int ReadData;

static float Output1[BLOCK_SIZE];
static float Output2[BLOCK_SIZE];

void DelayFunc(BasicAudio_DelayPara *DelayPara)
{

	BasicAudio_ObufferPara ObufferPara;
	WhiteNoiseFunc(DelayPara->DelInputData);

	ObufferPara.Pio = &ObufferPara.ObufferData[0];

	ObufferPara.Num = WriteData;

	for(int32_t DelayLoop = 0; DelayLoop < BLOCK_SIZE; DelayLoop ++)
	{

		//Output1[DelayLoop] = DelayPara->DelInputData[DelayLoop];
		DelayPara->DelOutputData1[DelayLoop] = DelayPara->DelInputData[DelayLoop];

		*(ObufferPara.Pio + ObufferPara.Num) = DelayPara->DelInputData[DelayLoop];

		ObufferPara.Num ++;
		if(ObufferPara.Num == ORUFFER_LEN)
		{
			ObufferPara.Num = 0;
		}

		//Output2[DelayLoop] = *(ObufferPara.Pio + ReadData);
		DelayPara->DelOutputData2[DelayLoop] = *(ObufferPara.Pio + ReadData);
		ReadData ++;
		if(ReadData == ORUFFER_LEN)
		{
			ReadData = 0;
		}
	}

	WriteData += BLOCK_SIZE;

	if (WriteData >= ORUFFER_LEN)
	{
		WriteData -= ORUFFER_LEN;
	}

	ReadData = WriteData - DELAY_NUN;
	if (ReadData < 0)
	{
		ReadData = ORUFFER_LEN - (DELAY_NUN - WriteData);
	}

}