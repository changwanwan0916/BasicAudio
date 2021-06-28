/*
 * Mixter.h
 *
 *  Created on: 2021Äê6ÔÂ21ÈÕ
 *      Author: Brisonus-DELL
 */

#ifndef MIXTER_H_
#define MIXTER_H_

#include"BasicAudioTest.h"

typedef struct
{

	float Freq1, Freq2, Freq3;

	float MixInputData1[BLOCK_SIZE];
	float MixInputData2[BLOCK_SIZE];
	float MixInputData3[BLOCK_SIZE];

	float MixOutputData[BLOCK_SIZE];

}BasicAudio_MixterPara;

void MixterFunc(BasicAudio_MixterPara *MixterPara);
#endif /* MIXTER_H_ */
