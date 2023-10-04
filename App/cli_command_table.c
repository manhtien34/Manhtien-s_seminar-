#include "cli_command_table.h"
#include "cli_types.h"
#include "gettempeture_ci.h"
#include "settemperature_ci.h"

const cli_command_info_t command_infor_gettemp={ //INFOR CHI LA TEN HAM  VA TEXT HELP DE HIEN THI HO TRO UI THOI 
gettempuraturene,
	"gettemp from ds18b20"

};
const cli_command_info_t command_infor_settemp_Max={
settempuratureMax,
	"settemp max"

};
const cli_command_info_t command_infor_settemp_Min={
settempuratureMin,
	"settemp min"

};
cli_command_entry_t command_entry_table[]={ // []O DAY LA TAP HOP CACS  LENH CHUNG TA CO THE BO SO VAO HOAC KHONG 
{"gettemp",&command_infor_gettemp},//DAY LA XONG 1 HAM 
{"settempMax",&command_infor_settemp_Max},
{"settempMin",&command_infor_settemp_Min},
{NULL,NULL} // CAN CO HAM NAY CHU NEU KHONG HAM SE DUYET MAI MAI 
};


