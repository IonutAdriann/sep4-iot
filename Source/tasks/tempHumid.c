/*
 * tempHumid.c
 *
 * Created: 5/3/2022 1:18:44 PM
 *  Author: alexandu, ionut, dragos
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <hih8120.h>
#include "../headers/tempHumid.h"
#include "../headers/data.h"

TickType_t xLastWakeTime;
TickType_t xFrequency;

void TempHumid_taskRun(void)
{
	xTaskDelayUntil( &xLastWakeTime, xFrequency);
	
	if (HIH8120_OK != hih8120_wakeup())
	{
		vTaskDelay(pdMS_TO_TICKS(100));
		printf("Temperature&humidity sensor didn't wake up retrying");
		while (HIH8120_OK != hih8120_wakeup())
		{
			vTaskDelay(pdMS_TO_TICKS(100));
		}
	}
	
	vTaskDelay(pdMS_TO_TICKS(500));
	
	temperature = hih8120_getTemperature();
	humidity = hih8120_getHumidity();
}

void TempHum_init()
{
	if (HIH8120_OK == hih8120_initialise())
	{
		//The driver is initialised.
	}
	else
	{
		printf("The driver didn't start");
	}
}

void TempHumid_getDataFromSensorTask(void *pvParameters)
{
	xFrequency = 5000/portTICK_PERIOD_MS;
	
	xLastWakeTime = xTaskGetTickCount();
	
	for(;;)
	{
		TempHumid_taskRun();
	}
}