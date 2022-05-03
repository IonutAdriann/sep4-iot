/*
 * tempHum.h
 *
 * Created: 5/2/2022 1:00:55 PM
 *  Author: alexandru
 */ 
#pragma once

#include "ATMEGA_FreeRTOS.h"
#include <stdint.h>

void TempHumid_taskRun(void);
void TempHumid_getDataFromSensorTask(void *pvParameters);
void TempHumid_init();