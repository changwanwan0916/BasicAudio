/*****************************************************************************
 * BasicAudioTest.h
 *****************************************************************************/

#ifndef __BASICAUDIOTEST_H__
#define __BASICAUDIOTEST_H__

#define     BLOCK_SIZE                                 (4096u)
#define     SAMPLE_FREQUENCY                           (48000u)
#define     SAMPLE_TIME                                (0.0000208333333f)

#define     FISFREQ                                    (20u)
#define     FREQNUM                                    (100u)
#define     FREQRATIO                                  (1.07f)

#define     FISQ                                       (0.1f)
#define     QNUM                                       (20u)
#define     QRATIO                                     (1.32f)

#define     FISGAIN                                    (-24.0f)
#define     GAINNUM                                    (20u)
#define     DISGAIN                                    (2.0f)

typedef struct
{
	float PrFreq[FREQNUM];
	float PrFreqErr[FREQNUM];

}BasicAudio_GetFirOrdLowPasPara;

typedef struct
{
	float Freq[FREQNUM][QNUM];
	float FreqErr[FREQNUM][QNUM];

	float DampRate[FREQNUM][QNUM];
	float DampRateErr[FREQNUM][QNUM];

}BasicAudio_GetSecOrdLowPasPara;

typedef struct
{
	float PrFreq[FREQNUM];
	float PrFreqErr[FREQNUM];

}BasicAudio_GetFisOrdHigPasPara;

typedef struct
{
	float Freq[FREQNUM][QNUM];
	float FreqErr[FREQNUM][QNUM];

	float DampRate[FREQNUM][QNUM];
	float DampRateErr[FREQNUM][QNUM];

}BasicAudio_GetSecOrdHigPasPara;

typedef struct
{
	float Freq[FREQNUM][QNUM];
	float FreqErr[FREQNUM][QNUM];

	float DampRate[FREQNUM][QNUM];
	float DampRateErr[FREQNUM][QNUM];

}BasicAudio_GetSecOrdAllPasPara;

typedef struct
{
	float Freq[FREQNUM][QNUM][GAINNUM];
	float FreqErr[FREQNUM][QNUM][GAINNUM];

	float DampRate[FREQNUM][QNUM][GAINNUM];
	float DampRateErr[FREQNUM][QNUM][GAINNUM];

	float Gain[FREQNUM][QNUM][GAINNUM];
	float GainErr[FREQNUM][QNUM][GAINNUM];

}BasicAudio_GetSecOrdLowShePara;

/*typedef struct
{
	float Freq[FREQNUM][QNUM][GAINNUM];
	float FreqErr[FREQNUM][QNUM][GAINNUM];

	float DampRate[FREQNUM][QNUM][GAINNUM];
	float DampRateErr[FREQNUM][QNUM][GAINNUM];

	float Gain[FREQNUM][QNUM][GAINNUM];
	float GainErr[FREQNUM][QNUM][GAINNUM];

}BasicAudio_GetSecOrdHigShePara;*/

typedef struct
{
	float Freq[FREQNUM][QNUM][GAINNUM];
	float FreqErr[FREQNUM][QNUM][GAINNUM];

	float DampRate[FREQNUM][QNUM][GAINNUM];
	float DampRateErr[FREQNUM][QNUM][GAINNUM];

	float Gain[FREQNUM][QNUM][GAINNUM];
	float GainErr[FREQNUM][QNUM][GAINNUM];

}BasicAudio_GetPeakingPara;

void GetFisOrdLowPassErr(BasicAudio_GetFirOrdLowPasPara *PrFirOrdLowPasPara);
void GetSecOrdLowPassErr(BasicAudio_GetSecOrdLowPasPara *PrSecOrdLowPasPara);
void GetFisOrdHigPassErr(BasicAudio_GetFisOrdHigPasPara *PrFirOrdHigPasPara);
void GetSecOrdHigPassErr(BasicAudio_GetSecOrdHigPasPara *PrSecOrdHigPasPara);
void GetSecOrdAllPassErr(BasicAudio_GetSecOrdAllPasPara *PrSecOrdAllPasPara);
void GetSecOrdLowSheErr(BasicAudio_GetSecOrdLowShePara *PrSecOrdShePasPara);
void GetPeakingErr(BasicAudio_GetPeakingPara *PrPeakingPara);
#endif /* __BASICAUDIOTEST_H__ */
