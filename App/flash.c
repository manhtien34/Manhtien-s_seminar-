#include "flash.h"
void flash_unclock(){
HAL_FLASH_Unlock();
}
void flash_clock(){
HAL_FLASH_Lock();
}
void flash_ecreaae(uint32_t addr){
	FLASH_EraseInitTypeDef eraseInit;
//	eraseInit.Banks=1;
	eraseInit.NbPages=1; // xoa 1 pasge
	eraseInit.PageAddress=addr;
	eraseInit.TypeErase=FLASH_TYPEERASE_PAGES;//xoa fage chu k xoa toan bo
	uint32_t PageError;
	HAL_FLASHEx_Erase(&eraseInit,&PageError);
	
}
int flash_read_int(uint32_t addr){
return *(__IO uint8_t *)(addr);
}

void flash_Write_arr(uint32_t addr,uint8_t *data,uint16_t len ){
	flash_unclock();
	flash_ecreaae(addr);
for (uint8_t i=0;i<len;i+=2){
HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD,addr+i,data[i]|(uint16_t )data[i+1]<<8);
}
flash_clock();
}
void flash_Read_arr(uint32_t addr,uint8_t *data,uint16_t len ){
	for (uint8_t i=0;i<len;i+=2){
	volatile uint32_t *p =(volatile uint32_t *)(addr+i);
		uint16_t data_temp=*p;
		data[i]=data_temp;
		data[i+1]=data_temp>>8;
	}
}
//void flash_Write_float(uint32_t addr,float f){
//	flash_unclock();
//uint8_t data[4];
//	*(float *)data=f;
//	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,addr,*(uint32_t *)data);
//	flash_clock();
//}
//float flash_Read_float(uint32_t addr){
//uint32_t data=*(__IO uint32_t *)(addr);
//return *(float *)(&data);
//}

