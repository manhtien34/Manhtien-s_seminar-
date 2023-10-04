#ifndef FLASH_H
#define FLASH_H
#include "stm32f1xx_hal.h"
void flash_unclock(void);
void flash_clock(void);
void flash_ecreaae(uint32_t addr);
void flash_Write_arr(uint32_t addr,uint8_t *data,uint16_t len );
void flash_Read_arr(uint32_t addr,uint8_t *data,uint16_t len );
int flash_read_int(uint32_t addr);
#endif

