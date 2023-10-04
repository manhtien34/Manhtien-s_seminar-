#ifndef SETTEMPERATURE_CI_H
#define SETTEMPERATURE_CI_H
#include "stdint.h"
#include "stm32f1xx_hal.h"
int  settempuratureMax(char **argv,uint8_t argv_num);
int  settempuratureMin(char **argv,uint8_t argv_num);
int GetTempMax(void);

#endif 
