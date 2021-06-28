/*
 * Mute.h
 *
 *  Created on: 2021Äê6ÔÂ21ÈÕ
 *      Author: Brisonus-DELL
 */

#ifndef MUTE_H_
#define MUTE_H_

#include"BasicAudioTest.h"

typedef struct
{
	float MuteInputData[BLOCK_SIZE];
	float MutOutputData[BLOCK_SIZE];

}BasicAudio_MutePara;


void MuteFunc(BasicAudio_MutePara *MutePara);
#endif /* MUTE_H_ */
