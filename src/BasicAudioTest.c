/*****************************************************************************
 * BasicAudioTest.c
 *****************************************************************************/

#include<stdint.h>
#include<stdio.h>
#include<math.h>
#include <filter.h>
#include <sys/platform.h>
#include "adi_initialize.h"
#include "BasicAudioTest.h"


#include"Filter.h"
#include"WhiteNoise.h"
#include"Transfunc.h"
#include"RecoPara.h"
#include"Volume.h"
#include"Limiter.h"
#include"Mute.h"
#include"Mixter.h"
#include"Delay.h"


static BasicAudio_GetFirOrdLowPasPara GetFirOrdLowPasPara;
static BasicAudio_GetSecOrdLowPasPara GetSecOrdLowPasPara;
static BasicAudio_GetFisOrdHigPasPara GetFirOrdHigPasPara;
static BasicAudio_GetSecOrdHigPasPara GetSecOrdHigPasPara;
static BasicAudio_GetSecOrdAllPasPara GetSecOrdAllPasPara;
static BasicAudio_GetSecOrdLowShePara GetSecOrdLowShePara;
static BasicAudio_GetPeakingPara GetPeakingPara;

static BasicAudio_VolumePara GetVolumePara;
static BasicAudio_LimiterPara GetLimiterPara;

static BasicAudio_MutePara GetMutePara;

static BasicAudio_MixterPara GetMixterPara;
static BasicAudio_DelayPara GetDelayPara;

static float Output[BLOCK_SIZE * 4];

static int Num = 0;


/**
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
	
	for(;;)
		{

		/*for(int32_t ii = 0; ii < 10; ii++)
		{
			DelayFunc(&GetDelayPara);
		}*/
		MixterFunc(&GetMixterPara);
		//VolumeFunc(&GetVolumePara);

		//LimiterFunc(&GetLimiterPara);
			//GetFisOrdLowPassErr(&GetFirOrdLowPasPara);
			//GetSecOrdLowPassErr(&GetSecOrdLowPasPara);
			//GetFisOrdHigPassErr(&GetFirOrdHigPasPara);
			//GetSecOrdHigPassErr(&GetSecOrdHigPasPara);
			//GetSecOrdAllPassErr(&GetSecOrdAllPasPara);
			//GetSecOrdLowSheErr(&GetSecOrdLowShePara);
		   // GetPeakingErr(&GetPeakingPara);



			FILE *pTff1 = fopen("Mixter.txt","w");
			//FILE *pTff2 = fopen("Signal2.txt","w");
			//FILE *pTff3 = fopen("SecOrdLowSheGain.txt","w");

			for(int32_t Num1 = 0; Num1 < BLOCK_SIZE; Num1++)
			{
				//for(int32_t Num2 = 0; Num2 < QNUM; Num2 ++)
				//{
					//for(int32_t Num3 = 0; Num3 < GAINNUM; Num3 ++)
					//{
						fprintf(pTff1, "%f\n",GetMixterPara.MixOutputData[Num1]);
						//fprintf(pTff2, "%f\n",GetDelayPara.DelOutputData2[Num1]);
						//fprintf(pTff3, "%f\n",GetSecOrdLowShePara.GainErr[Num1][Num2][Num3]);
					//}
				//}
			 }

			 fclose(pTff1);
			 //fclose(pTff2);
			 //fclose(pTff3);*/

		/*if(Num < 4)
		{
			MuteFunc(&GetMutePara);

			for(int32_t ii = 0; ii < BLOCK_SIZE; ii++)
			{
				Output[Num * BLOCK_SIZE + ii] = GetMutePara.MutOutputData[ii];
			}

			Num++;
		}
		else
		{
			while(1)
			{
				for(int i=0; i <100; i++){
				int x;
				x = 100;
				}
			}
		}*/


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

