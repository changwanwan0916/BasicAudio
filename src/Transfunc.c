/*
 * Transfunc.c
 *
 *  Created on: 2021��5��18��
 *      Author: Brisonus-DELL
 */

#include<stdint.h>
#include<stdio.h>
#include<math.h>
#include <filter.h>

#include"Transfunc.h"
#include"Filter.h"

static void prvFFTDualSignal(float fA[], float fB[], float fAr[], float fAi[], float fBr[], float fBi[]);
static void prvIFFTDualSignal(float fA[], float fB[], float fAr[], float fAi[], float fBr[], float fBi[]);

/* Parameter for dual signal fft */
static complex_float dm cfInput[SAMPLES_FFT];
static complex_float dm cfTemp[SAMPLES_FFT];
static complex_float dm cfOutput[SAMPLES_FFT];
static complex_float pm cfTwiddle[SAMPLES_FFT/2];

/* Data storage for fft output, also TransFunc_t's output */
static float fReal1[SAMPLES_FFT];
static float fImag1[SAMPLES_FFT];
static float fReal2[SAMPLES_FFT];
static float fImag2[SAMPLES_FFT];

/* Data storage for transfer function calculation */
static float fNumeratorR[SAMPLES_FFT/2] = {0} ;
static float fNumeratorI[SAMPLES_FFT/2] = {0} ;
static float fDenominator[SAMPLES_FFT/2] = {0} ;
static float TransFuncR[SAMPLES_FFT/2] = {0} ;
static float TransFuncI[SAMPLES_FFT/2] = {0} ;



void pWetchSingleLoop( float fNumeratorR[],float fNumeratorI[],float fDenominator[], float InputData[], float FilterOutput[])
{
	twidfft(cfTwiddle, SAMPLES_FFT);

	prvFFTDualSignal(InputData,FilterOutput,fReal1,fImag1,fReal2,fImag2);

	for(int fLoop=0; fLoop<SAMPLES_FFT/2; fLoop++){

	float fXR = fReal1[fLoop];
	float fXI = fImag1[fLoop];
	float fYR = fReal2[fLoop];
	float fYI = fImag2[fLoop];

	fNumeratorR[fLoop] += (fXR*fYR + fYI*fXI)/AVERAGE_NUM;
	fNumeratorI[fLoop] += (fXR*fYI - fXI*fYR)/AVERAGE_NUM;

	fDenominator[fLoop] += (fXR*fXR + fXI*fXI)/AVERAGE_NUM;
	}
}


void GetTransfunc(float *TransFuncAmp, float *TransFuncPhase, float fNumeratorR[],float fNumeratorI[],float fDenominator[])
{
	for(int fLoop=0; fLoop<SAMPLES_FFT/2; fLoop++)
	{

	TransFuncR[fLoop] = fNumeratorR[fLoop]/fDenominator[fLoop];
	TransFuncI[fLoop] = fNumeratorI[fLoop]/fDenominator[fLoop];

	TransFuncAmp[fLoop] = sqrtf(TransFuncR[fLoop]*TransFuncR[fLoop]+
										TransFuncI[fLoop]*TransFuncI[fLoop]);
	TransFuncPhase[fLoop] = (atan2f(TransFuncI[fLoop],TransFuncR[fLoop])) * 180 / PI;
	}
}



/*void Transfunc(float *TransFuncAmp, float *TransFuncPhase, float InputData1[], float FilterOutput1[])
{
	Initialize twiddle coefficient

		 Transfer function calculation

}*/




/**********************************
 * Name: FFTDualSignal
 * Function: Transform two time sigal to frequency domain uses just one FFT
 * The output magnitude is half normalized (0.5 * origin)
 *************************************/
static void prvFFTDualSignal(float fA[], float fB[], float fAr[], float fAi[], float fBr[], float fBi[])
{

	uint32_t ulI;
	for(ulI = 0 ; ulI<SAMPLES_FFT; ulI++){
		cfInput[ulI].re = fA[ulI];
		cfInput[ulI].im = fB[ulI];
	}

	cfft(cfInput, cfTemp, cfOutput, cfTwiddle, 1, SAMPLES_FFT);

	fAr[0] = cfOutput[0].re;
	fAi[0] = 0;
	fBr[0] = cfOutput[0].im;
	fBi[0] = 0;

	for (ulI = 0; ulI < SAMPLES_FFT / 2; ulI++) {
		// Real(A)
		fAr[ulI + 1] = 0.5 * (cfOutput[ulI + 1].re + cfOutput[SAMPLES_FFT - 1 - ulI].re);
		fAr[ulI + SAMPLES_FFT / 2] = 0.5 * (cfOutput[SAMPLES_FFT / 2 + ulI].re + cfOutput[SAMPLES_FFT / 2 - ulI].re);
		// Imag(A)
		fAi[ulI + 1] = 0.5 * (cfOutput[ulI + 1].im - cfOutput[SAMPLES_FFT - 1 - ulI].im);
		fAi[ulI + SAMPLES_FFT / 2] = 0.5 * (cfOutput[SAMPLES_FFT / 2 + ulI].im - cfOutput[SAMPLES_FFT / 2 - ulI].im);

		// Real(B)
		fBr[ulI + 1] = 0.5 * (cfOutput[ulI + 1].im + cfOutput[SAMPLES_FFT - 1 - ulI].im);
		fBr[ulI + SAMPLES_FFT / 2] = 0.5 * (cfOutput[SAMPLES_FFT / 2 + ulI].im + cfOutput[SAMPLES_FFT / 2 - ulI].im);
		// Imag(B)
		fBi[ulI + 1] = -0.5 * (cfOutput[ulI + 1].re - cfOutput[SAMPLES_FFT - 1 - ulI].re);
		fBi[ulI + SAMPLES_FFT / 2] = -0.5 * (cfOutput[SAMPLES_FFT / 2 + ulI].re - cfOutput[SAMPLES_FFT / 2 - ulI].re);
	}
}

/**********************************
 * Name: iFFTDualSignal
 * Function: Transform two complex signal to time domain uses just one IFFT
 * Use half normalized magnitude in frequency, the out put gets the oringinal magnitude
 *************************************/
static void prvIFFTDualSignal(float fA[], float fB[], float fAr[], float fAi[], float fBr[], float fBi[])
{
	uint32_t ulI;

	for (ulI = 0; ulI < SAMPLES_FFT; ulI++) {
		cfInput[ulI].re = fAr[ulI] - fBi[ulI];
		cfInput[ulI].im = fAi[ulI] + fBr[ulI];
	}

	ifft(cfInput, cfTemp, cfOutput, cfTwiddle, 1, SAMPLES_FFT);

	for(ulI = 0; ulI < SAMPLES_FFT; ulI++){
		fA[ulI] = cfOutput[ulI].re;
        fB[ulI] = cfOutput[ulI].im;
	}

}
