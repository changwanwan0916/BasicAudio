/*
 * @Descripttion: 
 * @version: 
 * @Author: zsq
 * @Date: 2021-07-07 20:48:09
 * @LastEditors: sueRimn
 * @LastEditTime: 2021-07-08 13:12:01
 */
/*
 * Delay.h
 *
 *  Created on: 
 *      Author: Brisonus-DELL
 */

#ifndef DELAY_H_
#define DELAY_H_

typedef struct
{
	float delayTime;
}Delay_Config;

typedef struct
{
	uint32_t delaySize;
	float** RbufferAdd;
	uint32_t WriteNum;
}Delay_RunTime;

typedef struct
{
	Delay_Config **Del_Config;
	Delay_RunTime **Del_RunTime;
}Algo_Delay;

inline void Set_Delay_Config(uint32_t at, Delay_Config *lc)
{
	lc->delayTime = at;
}

#endif /* DELAY_H_ */
