/*
 * data.h
 *
 * Created: 5/5/2022 1:13:58 PM
 *  Author: alexandru, ionut, dragos
*/
#include <semphr.h>

#ifndef data_h
#define data_h

typedef struct SensorsData
{
uint16_t temperature;
uint16_t humidity;
uint16_t ppm;

} SensorsData;


SemaphoreHandle_t semaphore;

#endif
