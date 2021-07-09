/*
 * Filter.h
 *
 *  Created on: 2021Äê7ÔÂ7ÈÕ
 *      Author: Brisonus-DELL
 */

#ifndef FILTER_H_
#define FILTER_H_

#define     NUM_DEN_ORDER                              (3u)
#define     FILTERSECTION                              (1u)
#define     PI                                         (3.1415926f)

typedef struct
{
	float Omega;
	float Sample_Time;

	float ShelfVar1;
	float ShelfVar2;
	float ShelfVar3;
	float ShelfVar4;
	float ShelfVar5;
	float ShelfVar6;

	float PeakVar1;
	float PeakVar2;
	float PeakVar3;
	float PeakVar4;
	float PeakVar5;
	float PeakVar6;
}Filter_Vari;


typedef struct
{
	float Freq;
	float Gain;
	float q;
}Filter_Init_Config;

typedef struct
{
	float Den[NUM_DEN_ORDER];
	float Num[NUM_DEN_ORDER];

	float Coeff;
}Filter_Run_Config;

typedef struct
{
	Filter_Init_Config* Init_Config_Inter;
	Filter_Run_Config* Run_Config_Inter;
}Filter_Config_Inter;

typedef struct
{
	float pm Filter_Coeff[5 * FILTERSECTION];
	float dm Filter_State[2 * FILTERSECTION];
}Biqud_Init_Config;


//typedef void(*Filter_Init)();
//typedef void(*Filter_Set)(Filter_Init_Config*);
typedef void(*Filter_Func)(Filter_Run_Config*, Filter_Init_Config*);

typedef struct
{
	char* Filter_Name;
	Filter_Init_Config* Filter_Config;

	Filter_Func Func;
}Filter;

inline void Set_Filter_ConfigFunc(float freq, float gain, float Q, Filter_Init_Config *fic)
{
	fic->Freq = freq;
	fic->Gain = gain;
	fic->q = Q;
}


void State_Init_Func(void);
void Biquad_Func(float Output[], float Input[], Filter_Run_Config *Filter_Run_Data);

#endif /* FILTER_H_ */
