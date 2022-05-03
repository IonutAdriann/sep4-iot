/*
 * tempHumid.h
 *
 * Created: 5/3/2022 1:22:15 PM
 *  Author: alexandru, ionut, dragos
 */ 
#pragma once

#include "ATMEGA_FreeRTOS.h"
#include <stdint.h>

void TempHumid_taskRun(void);
void TempHumid_getDataFromSensorTask(void *pvParameters);
void TempHumid_init();

