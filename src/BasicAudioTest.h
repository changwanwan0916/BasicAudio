/*
 * BasicAudioTest.h
 *
 *  Created on: 2021??7??4??
 *      Author: Brisonus-DELL
 */

#ifndef BASICAUDIOTEST_H_
#define BASICAUDIOTEST_H_

typedef enum
{
	GLOBAL,ALGORITHM

}WHICH;

typedef enum
{
	ENT,
	INFO,
	CHIME,

}MODE;

typedef struct
{
	WHICH which;
	void* Config;

}Audio_Config;

typedef struct
{
	uint32_t Input_ChNum;
	uint32_t Output_ChNum;

	uint32_t Block_Size;
	uint32_t Sample_Rate;

}Audio_Gobal_Config;


typedef void(*Algo_Init)();
typedef void(*Algo_Set)(void*, void*);
typedef void(*Block_Func)(float*[], float*[]);

typedef struct
{
	const char* Name;
	void* Config;

	Algo_Init Init;
	Algo_Set Set;
	Block_Func Func;

}Audio_Block;

inline void Set_Audio_Global(uint32_t bs, uint32_t st, uint32_t Ch_Num, Audio_Gobal_Config *ag)
{
	ag->Block_Size = bs;
	ag->Sample_Rate = st;

//	ag->Block_ChNum = Ch_Num;
}

#endif /* BASICAUDIOTEST_H_ */
