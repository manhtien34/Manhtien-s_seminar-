	#include "cli_command.h"
	#include "string.h"
	#include "response_ci.h"
	#include "gettempeture_ci.h"
	#include "cli_types.h"
	#include "uarth.h"
	extern cli_command_entry_t command_entry_table[];
	extern UART_HandleTypeDef huart1;
	const cli_command_info_t *find_command_infor(char *cmd){  // CONST KHAI BAO BIEN MA KHONG THE THAY DOI 
	const cli_command_entry_t *command_entry=command_entry_table;
	while(command_entry->command_infor!=NULL){
	if (strcmp(command_entry->name,cmd)==0){
	 return command_entry->command_infor;
	}
	command_entry ++;
	}
	return NULL;
	}
	void cli_command_excute(char *uart_buffer,uint8_t len){
		
			 char *argv[20];
			 uint8_t  arg_num=0;
		char *pch;
		pch=strtok(uart_buffer," ");
				while(pch !=NULL){
					argv[arg_num]=pch;
				 pch=strtok(NULL," ");
					arg_num++;
				}

				const cli_command_info_t *command_infor= find_command_infor(argv[0]); // HAM NAY CO TAC DUNG LAY CAI DAU UART VAO DE DOI CHIEU LENH TUONG UNG BEN cli_command_table.C
				if(command_infor !=NULL){
				command_infor->funtion(argv,arg_num);
				}
				else{
				response_print2("not find this command ");
				 response_print2("////");
					response_print2(argv[0]);
					response_print2("///");
				}

	}
	




	