#ifndef UART_H
#define UART_H
#include "stdint.h"
#include "stm32f1xx_hal.h"
void receivedata(uint8_t c);
void uart_handle(void );
void uart_init(void);
#endif 

