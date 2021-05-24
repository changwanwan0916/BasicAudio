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

static int32_t RandomSeed[SEEDSNUM] = {
	#include "RandSeed.txt"
	};

static BasicAudio_FilterPara PrSecOrderLowPassPara;

static float SecLowPassInput[BLOCK_SIZE];
static float SecLowPassOutput[BLOCK_SIZE];

static float SecOrdLowPassFreq, SecOrdLowPassQ;

//static float fNumeratorR[SAMPLES_FFT/2] = {0} ;
//static float fNumeratorI[SAMPLES_FFT/2] = {0} ;
//static float fDenominator[SAMPLES_FFT/2] = {0} ;
static float PrSecOrdLowPassAmp[SAMPLES_FFT/2] = {0} ;
static float PrSecOrdLowPassPhase[SAMPLES_FFT/2] = {0} ;
static float SecOrdLowPassFreqErr[FREQNUM][QNUM], SecOrdLowPassQErr[FREQNUM][QNUM];

static float SecOrdAllPassFreqErr[FREQNUM][QNUM], SecOrdAllPassQErr[FREQNUM][QNUM];

static float Freq;
static float Freq0[FREQNUM];
static float FisOrdLowPassErr[FREQNUM];



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

		GetSecOrdAllPassErr();

		//GetFisOrdHigPassErr();

		//GetSecOrdAllPassErr(SecOrdAllPassFreqErr, SecOrdAllPassQErr);

		//GetFisOrdAllPassErr(Freq0, FisOrdLowPassErr);
		//GetSecOrdLowPassErr(SecOrdLowPassFreqErr,SecOrdLowPassQErr);

		/*FILE *pTff1 = fopen("SecOrdAllPassFreqErr.txt","w");
		FILE *pTff2 = fopen("SecOrdAllPassQErr.txt","w");

		for(int32_t ii = 0; ii < FREQNUM; ii++)
		{
			for(int32_t jj = 0; jj < QNUM; jj++)
			{
				fprintf(pTff1, "%f\n",SecOrdAllPassFreqErr[ii][jj]);
				fprintf(pTff2, "%f\n",SecOrdAllPassQErr[ii][jj]);
			}
		 }

		fclose(pTff1);
		fclose(pTff2);*/

		/*PrSecOrderLowPassPara.Freq = 1000.0f;
		PrSecOrderLowPassPara.DampRate = 0.707f;

		SecOrdLowPassFunc(&PrSecOrderLowPassPara);

		float fNumeratorR[SAMPLES_FFT/2] = {0} ;
		float fNumeratorI[SAMPLES_FFT/2] = {0} ;
		float fDenominator[SAMPLES_FFT/2] = {0} ;

		for(int ii = 0; ii < 100; ii ++)
		{
			for(int RandomLoop = 0; RandomLoop < BLOCK_SIZE; RandomLoop ++)
			{
				SecLowPassInput[RandomLoop] = RandomFunc(RandomSeed, SEEDSNUM, MAXSEED);  //Check

				//printf("%d\n", RandomLoop);
			}

			FilterFunc(SecLowPassOutput,SecLowPassInput, &PrSecOrderLowPassPara);
			pWetchSingleLoop(fNumeratorR, fNumeratorI, fDenominator, SecLowPassInput, SecLowPassOutput);
		}

		GetTransfunc(PrSecOrdLowPassAmp, PrSecOrdLowPassPhase, fNumeratorR, fNumeratorI, fDenominator);

		PrSecOrdLowPassFunc(&SecOrdLowPassFreq, &SecOrdLowPassQ,PrSecOrdLowPassAmp, PrSecOrdLowPassPhase);
*/
		while(1)
		{
			for(int i=0; i <100; i++){
				int x;
				x = 100;
			}

		}
	}


//	   //1.Initialize: filter parameter calculate
//		PrFisOrderLowPassPara.Freq = 500.0f;
//		FisOrdLowPassFunc(&PrFisOrderLowPassPara);
//
//		 //2.Filter:
//			 //* white noise generation
//		for(int i=0; i<AVERAGE_NUM; i++)
//		{
//			for(int32_t ii = 0; ii < BLOCK_SIZE; ii++)
//			{
//				InputData[ii] = RandomFunc(RandomSeed, SEEDSNUM, MAXSEED);
//			}
//
//			FilterFunc(FilterOutput, InputData, &PrFisOrderLowPassPara);
//
//			 //3.Calculate transfer function
//			pWetchSingleLoop(fNumeratorR, fNumeratorI, fDenominator, InputData, FilterOutput);
//		}
//
//		GetTransfunc(PrTransFuncAmp, PrTransFuncPhase, fNumeratorR, fNumeratorI, fDenominator);
//		 //4.Recognize parameter
//		PrFisOrdLowPassFunc(&Freq, PrTransFuncAmp, PrTransFuncPhase);
//
//		 //5. Calculate error
//
//		while(1)
//		{
//			for(int i=0; i <100; i++){
//				int x;
//				x = 100;
//			}
//
//		}

	return 0;
}

