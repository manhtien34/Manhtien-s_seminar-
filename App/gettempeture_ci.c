#include "gettempeture_ci.h"
#include "response_ci.h"
#include "gettempds18b20.h"
#include "string.h"
#include <stdlib.h>
//extern UART_HandleTypeDef huart2; //DUNG DE S U DUNG MOT BIEN BAT KI TRONG PRJECT
//HAL_UART_Transmit(&huart2,(uint8_t *)"\n ok \n  ",10,100);
int gettempuraturene(char **argv,uint8_t argv_num){


	if(argv_num <2){
		response_print2("not enough Array,arg=%d",argv_num);
	}
	else if (argv_num >2){
		response_print2("too much Array,arg=%d",argv_num);
	}
	
	uint8_t channel=atoi(argv[1]);// CHUYEN TU CHUOI SANG SO
	response_print2("\n TEMPERATURE =%f",DS18B20_Gettemp(channel));
	return DS18B20_Gettemp(channel);
}
