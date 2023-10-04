#ifndef GETTEMPDS18B20_H
#define GETTEMPDS18B20_H
#include "stdint.h"
#include "ds18b20.h"
#include "DS18B20.h"
#include "string.h"
#include "response_ci.h"
#include <stdarg.h>
#include <stdio.h>
#include "stm32f1xx_hal.h"
float DS18B20_Gettemp(uint8_t channel);
#endif 
