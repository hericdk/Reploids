#ifndef UTILS_AUDIO_H
#define UTILS_AUDIO_H

#include <driver/i2s.h>

#define I2S_PORT I2S_NUM_0
#define SAMPLE_RATE 16000
#define I2S_BCK 12
#define I2S_WS 0
#define I2S_DATA 34

void setupI2S();
int getAudioLevel();

#endif