#ifndef CLI_TYPE_H
#define CLI_TYPE_H
#include<stdint.h>
typedef int (*cli_command_fun_t)(char **argv,uint8_t argv_num); //DAY LA CON TRO HAM CACH KHAI BAO LA  TENKIEUDULIEU(*TENHAM)(DOISO)
/* typedef LAKIEU DUBLIEU DO NGUOI DUNG DINH NGHIA GIONG DEFINE , CO THE THAY DOI TEN GOI DUOC
#include <iostream>
using namespace std;
typedef int bien;
int main()
{
    bien t;
    cin>>t;
    cout<<"Hello World"<<t;

    return 0;
}*/ 
	typedef struct{
	cli_command_fun_t funtion;  // KHAI BAO DE SU DUNG CON TRO HAM
	char *help;
	
}cli_command_info_t;
typedef struct{
 const char *name; // TEN LENH 
	const cli_command_info_t *command_infor;//HAN NAY TRO TOI STRUCT  TREN  
	
}cli_command_entry_t;  // NHU VAY ENTRY CHUA INFOR CON INFOR CHUA CACS HAM CAN GOI 
#endif 

