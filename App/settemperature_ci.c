#include "settemperature_ci.h"
#include "response_ci.h"
#include "gettempds18b20.h"
#include "string.h"
#include <stdlib.h>
#include "flash.h"
#define addtempmax 0x801FC00 // dia chi page cuoi 127 
#define addtempmin 0x801F800 // 0x801FC00-1024
int settempuratureMax(char **argv,uint8_t argv_num){
	if(argv_num <2){
		response_print2("not enough Array,arg=%d",argv_num);
		
	}
	else if (argv_num >2){
		response_print2("too much Array,arg=%d",argv_num);
	}
	int SetTempMax=atoi(argv[1]);// CHUYEN TU CHUOI SANG SO
	response_print2("\n TEMPERATURE MAX is %d",SetTempMax);
	flash_Write_arr(addtempmax,(uint8_t *)&SetTempMax,sizeof(SetTempMax));
  return SetTempMax;
}
int  settempuratureMin(char **argv,uint8_t argv_num){
	if(argv_num <2){
		response_print2("not enough Array,arg=%d",argv_num);
	}
	else if (argv_num >2){
		response_print2("too much Array,arg=%d",argv_num);
	}
	int SetTempMin=atoi(argv[1]);// CHUYEN TU CHUOI SANG SO
	response_print2("\n TEMPERATURE in is %d",SetTempMin);
	flash_Write_arr(addtempmin,(uint8_t *)&SetTempMin,sizeof(SetTempMin));
  return SetTempMin;
}


