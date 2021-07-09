/*
 * Tone.h
 *
 *  Created on: 2021��7��8��
 *      Author: Brisonus-DELL
 */

#ifndef TONE_H_
#define TONE_H_

typedef enum
{
	BASS,
	MIDDLE,
	TREBLE
}Tone_Control;

typedef struct
{
	Tone_Control Control;
}Tone_Control_Type;

#endif /* TONE_H_ */
