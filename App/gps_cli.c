#include "gps_cli.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include <math.h>
#include "response_ci.h"
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart1;
double lat1, lon1,lat2, lon2;
typedef struct{
 float lattidu;
 float longtidu;
 }infor_gps ;
char* parseGpsData(uint8_t *buffer, uint32_t len, float *lat, float *lon) {
  char *latStr = strstr((char *)buffer, "$GPGGA,");
  char *lonStr = strstr((char *)buffer, "$GPGGA,");
  if (latStr == NULL || lonStr == NULL) {
  *lat = 0.0;
  *lon = 0.0;
  return 0;
 }
  latStr += 17;  
  lonStr += 30;  
  char latBuffer[12] = {0};
  char lonBuffer[12] = {0};
  strncpy(latBuffer, latStr, 11);
  strncpy(lonBuffer, lonStr, 11);
  *lat = strtof(latBuffer, NULL);
  *lon = strtof(lonBuffer, NULL);
	*lat=*lat/100;
	*lon=*lon/100;
  lat2 = modf(*lat,&lat1);
  lat2=lat2*100/60;
  lon2 = modf(*lon,&lon1);
  lon2=lon2*100/60;
  *lat=lat1+lat2;
  *lon=lon1+lon2;
	response_print2("latitude: %7f",*lat);
	response_print2( "longtitude: %7f",*lon);  

}

