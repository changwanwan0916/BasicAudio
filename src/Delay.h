/*
 * Delay.h
 *
 *  Created on: 2021��6��18��
 *      Author: Brisonus-DELL
 */

#ifndef DELAY_H_
#define DELAY_H_

#include"BasicAudioTest.h"

#define     DELAY_NUN                                  (20u)
#define     ORUFFER_LEN                                (BLOCK_SIZE + DELAY_NUN)

typedef struct
{
	
	float DelInputData[BLOCK_SIZE];

	float DelOutputData1[BLOCK_SIZE];
	float DelOutputData2[BLOCK_SIZE];


}BasicAudio_DelayPara;

typedef struct
{
	float ObufferData[ORUFFER_LEN];
	float *Pio;
	int Num;

}BasicAudio_ObufferPara;

void DelayFunc(BasicAudio_DelayPara *DelayPara);

#endif /* DELAY_H_ */