/*
 * Limiter.h
 *
 *  Created on: 2021??7??4??
 *      Author: Brisonus-DELL
 */

#ifndef LIMITER_H_
#define LIMITER_H_

typedef struct
{
	float Attack_Time;
	float Release_Time;
	float Treshold;

}Limiter_Config;

typedef struct
{
	float aA;
	float aR;
}Limiter_RunTime;


typedef struct
{
	Limiter_Config **Lim_Config;
	Limiter_RunTime **Lim_RunTime;

}Algo_Limiter;


//typedef struct
//{
//	float xdB;
//	float xSc;
//	float gC;
//	//float gS[BLOCK_SIZE];
//	float gLin;
//
//}Limiter_Para;

inline void Set_Limiter_Config(float at, float rt, float thr, Limiter_Config *lc)
{
	lc->Attack_Time = at;
	lc->Release_Time = rt;
	lc->Treshold = thr;
}

#endif /* LIMITER_H_ */
