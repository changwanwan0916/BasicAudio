/*
 * Volume.h
 *
 *  Created on: 2021��6��18��
 *      Author: Brisonus-DELL
 */

#ifndef VOLUME_H_
#define VOLUME_H_

#include"BasicAudioTest.h"


#define     VOLFISGAIN                                    (-99.0f)
#define     VOLGAINNUM                                    (112u)
#define     VOLDISGAIN                                    (1.0f)

typedef struct
{
	float VolInput[BLOCK_SIZE];
	float VolOutput[BLOCK_SIZE];

	float SumVolInput;
	float SumVolOutput;

	float VolGainAmp[VOLGAINNUM];
	float VolGain[VOLGAINNUM];
	float VolGainTest[VOLGAINNUM];
	float VolGainErr[VOLGAINNUM];

}BasicAudio_VolumePara;


void VolumeFunc(BasicAudio_VolumePara *VolumePara);

#endif /* VOLUME_H_ */
