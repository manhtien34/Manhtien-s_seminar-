#include "gettempds18b20.h"
extern TIM_HandleTypeDef htim1;
extern UART_HandleTypeDef huart1;
float DS18B20_Gettemp(uint8_t channel){
	DS18B20_Name DS1;
DS18B20_Init(&DS1,&htim1,GPIOB,GPIO_PIN_15);
	float temp2;
		temp2=DS18B20_ReadTemp(&DS1);
	if(channel ==1)  
	return temp2;
}
