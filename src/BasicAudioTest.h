/*****************************************************************************
 * BasicAudioTest.h
 *****************************************************************************/

#ifndef __BASICAUDIOTEST_H__
#define __BASICAUDIOTEST_H__

#define     BLOCK_SIZE                                 (2048u)
#define     SAMPLE_FREQUENCY                           (48000u)

#define     FISFREQ                                    (20u)
#define     FREQNUM                                    (50u)
#define     DisFREQ                                    (400u)

#define     FISQ                                       (0.1f)
#define     QNUM                                       (8u)
#define     DisQ                                       (0.6f)


void GetFisOrdLowPassErr(float *Freq0, float *FisOrdLowPassErr);
void GetSecOrdLowPassErr(float SecOrdLowPassFreqErr[][QNUM],float SecOrdLowPassQErr[][QNUM]);

void GetFisOrdHigPassErr();
void GetSecOrdHigPassErr();
void GetFisOrdAllPassErr(float *FisOrdAllPassFreq0, float *FisOrdAllPassErr);
//void GetSecOrdAllPassErr(float SecOrdAllPassFreqErr[][QNUM],float SecOrdAllPassQErr[][QNUM]);
void GetSecOrdAllPassErr();
#endif /* __BASICAUDIOTEST_H__ */
