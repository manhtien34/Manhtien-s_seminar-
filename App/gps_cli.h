#ifndef GPS_CI_H
#define GPS_CI_H
#include "main.h"
char* parseGpsData(uint8_t *buffer, uint32_t len, float *lat, float *lon);
float getlatGps(void);
void hamnhanthu(void);
void displayGpsCoordinates(uint8_t *buffer, uint32_t len);
#endif 

