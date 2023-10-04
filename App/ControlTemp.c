#include "response_ci.h"
#include "ControlTemp.h"
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart1;
void TemptooHight(){
response_print2("\n nhiet do qua cao");
}
void TemptooLow(){
response_print2("\n nhiet do qua thap");
}