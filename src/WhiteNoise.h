/*
 * WhiteNoise.h
 *
 *  Created on: 2021??5??18??
 *      Author: Brisonus-DELL
 */

#ifndef WHITENOISE_H_
#define WHITENOISE_H_

#define     SEEDSNUM                                   (2000u)
#define     MAXSEED                                    (100000u)


void WhiteNoiseFunc(float *InputData);
void SinFunc(float InputData[], float Frequency);

//float RandomFunc(int *SeedsData, int32_t SeedNum, int32_t SeedsMax);
#endif /* WHITENOISE_H_ */
