#include "uarth.h"
#include "string.h"
#include "gettempeture_ci.h"
#include "settemperature_ci.h"
#include "response_ci.h"

#include "cli_command.h"


#define MAX_DATA_UART 100
static   char  uart_buffer[MAX_DATA_UART]; // khai bao bien cuc bo , neu lo ben khac dat cung ten thi cunng khong bao loi
static  uint8_t uart_lend=0;
static uint8_t uart_flag =0;
//extern UART_HandleTypeDef huart1; //DUNG DE S U DUNG MOT BIEN BAT KI TRONG PRJECT
//extern UART_HandleTypeDef huart2; //DUNG DE S U DUNG MOT BIEN BAT KI TRONG PRJECT

void receivedata(uint8_t data_rx){ // NHAN DATA
if(data_rx=='?'){ //NHAN XONG 
	uart_buffer[uart_lend++]='\0';//TAO THANH 1 CHUOI 
	uart_flag =1;
}
else{
	uart_buffer[uart_lend++]=data_rx; // NEU CHUA NHAN XONG THI TIEP TUC GAN GIA TRI 
}
}
void uart_handle(){


   if(uart_flag){ 
        cli_command_excute(uart_buffer, uart_lend);
		 uart_lend=0;
 		 	uart_flag =0;
	  
		 }
}
void uart_init(){
	
}
