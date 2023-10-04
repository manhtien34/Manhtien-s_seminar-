#include "settemperature_ci.h"
#include "response_ci.h"
#include "gettempeture_ci.h"
#include "gettempds18b20.h"
#include "ControlTemp.h"
#include "flash.h"
#include "string.h"
#define addtempmax 0x801FC00 // dia chi page cuoi 127 
#define addtempmin 0x801F800 // 0x801FC00-1024

int TempMaxSet;
int TempMinSet;
 char argv[]="gettemp";
void temprature_hande(){
	flash_Read_arr(addtempmax,(uint8_t *)&TempMaxSet,sizeof(TempMaxSet));
		flash_Read_arr(addtempmin,(uint8_t *)&TempMinSet,sizeof(TempMinSet));
	uint8_t channel =1;
  int temp=DS18B20_Gettemp(channel);
  response_print2("tempnow %d .",temp);

	HAL_Delay(1000);
}
void hamdieuchinh(int tempcurent,int tempmax,int tempmin ){
if (tempcurent>tempmax){
void TemptooHight();
}
if (tempcurent<tempmin){}
void TemptooLow();
}

