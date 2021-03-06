/*****************************************************************************
 * BasicAudioTest.c
 *****************************************************************************/

#include<stdint.h>
#include<stdio.h>
#include<math.h>
#include <filter.h>
#include<string.h>
#include <sys/platform.h>
#include "adi_initialize.h"

#include"BasicAudioTest.h"
#include"Limiter.h"
#include"WhiteNoise.h"
#include"Filter.h"



//extern Audio_Block ab_Limiter;

static float Input1[3600];
static float Input2[3600];

static float Output1[3600];
static float Output2[3600];

MODE RR;

extern Filter Filter_LowShelf;
extern Filter Filter_Peaking;
extern Filter Filter_HighShelf;

extern Audio_Block ab_Tone;
static Filter_Run_Config  Tone_Run_Config1;
//static Filter_Run_Config  Run_Config;


/*
 * If you want to use command program arguments, then place them in the following string.
 */

char __argv_string[] = "";

int main(int argc, char *argv[])
{
	/**
	 * Initialize managed drivers and/or services that have been added to 
	 * the project.
	 * @return zero on success
	 */

 	adi_initComponents();

	WhiteNoiseFunc(Input1);
	WhiteNoiseFunc(Input2);

 	ab_Tone.Init();

 	for(;;)
 	{
 		//HighShelf.Func(&Run_Config, HighShelf.Filter_Config);
 		for(uint32_t Block_Loop = 0; Block_Loop < 150; Block_Loop++)
 		{

 			float* Input[2] = {&Input1[Block_Loop * 24], &Input2[Block_Loop*24]};
 			float* Output[2] = {&Output1[Block_Loop * 24], &Output2[Block_Loop *24]};

 			ab_Tone.Func(Output, Input);
 		}

		while(1)
		{
			for(int i=0; i <100; i++){
			int x;
			x = 100;
			}
		}

 	}

	return 0;
}

