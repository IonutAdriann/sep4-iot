/*
 * tempHumid.h
 *
 * Created: 5/3/2022 1:22:15 PM
 *  Author: alexandru, ionut, dragos
 */ 
#pragma once

#include <ATMEGA_FreeRTOS.h>
#include <stdint.h>
#include <stdio.h>
#include <hih8120.h>
#include <task.h>
#include <semphr.h>

#include "../Source/headers/Initializers.h"

void TempHumid_measureTask();
void TempHumid_getDataFromSensorTask(void *pvParameters);
void createTempHumidTask(UBaseType_t priority);
void TempHumid_init();
uint16_t get_temperature_data();
uint16_t get_humidity_data();

