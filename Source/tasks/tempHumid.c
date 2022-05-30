/*
 * tempHumid.c
 *
 * Created: 5/3/2022 1:18:44 PM
 *  Author: alexandu, ionut, dragos
 */ 

#include "../headers/tempHumid.h"
//#include "../headers/data.h"


uint16_t temperature_data = 0;
uint16_t humidity_data = 0;
//TickType_t xLastWakeTime;
//TickType_t xFrequency;

void TempHumid_init()
{
	if (HIH8120_OK == hih8120_initialise())
	{
		printf("The driver for temperature and humidity is initialized"); //The driver is initialized.
	}
	else
	{	
		printf("The driver didn't start");
	}
}

void TempHumid_measureTask(void)
{
	//xTaskDelayUntil( &xLastWakeTime, xFrequency);
	
	if (HIH8120_OK != hih8120_wakeup())
	{
		printf("Temperature&humidity sensor didn't wake up retrying");	
		
	}
	vTaskDelay(pdMS_TO_TICKS(100));
	
	if ( HIH8120_OK !=  hih8120_measure())
	{
		printf("Temperature&humidity sensor could not perform measurement ");
		
	}
	
	vTaskDelay(pdMS_TO_TICKS(20));
	
}


void TempHumid_getDataFromSensorTask(void *pvParameters)
{
	while (1) {
		
		xEventGroupWaitBits(measureEventGroup,temperature_and_humidity_bit,pdTRUE,pdTRUE,portMAX_DELAY);
		//if (xSemaphoreTake(temperatureAndHumiditySemaphore, portMAX_DELAY) == pdTRUE) {
			
			TempHumid_measureTask();
			temperature_data = hih8120_getTemperature();
			humidity_data = hih8120_getHumidity();
			
			//xQueueSend(dataSensorQueue, &temperature, portMAX_DELAY);
			//xQueueSend(dataSensorQueue, &humidity, portMAX_DELAY);
			
			xEventGroupSetBits(dataConfigurationGroup,temperature_and_humidity_bit);
		//}
		
		vTaskDelay(pdMS_TO_TICKS(10));
	}
}

uint16_t get_temperature_data() {
	
	return temperature_data;
}

uint16_t get_humidity_data() {
	
	return humidity_data;
}

void createTempHumidTask(UBaseType_t priority) {
	TempHumid_init();
	
	xTaskCreate (
	TempHumid_getDataFromSensorTask
	, "Get data from Sensor task"
	, configMINIMAL_STACK_SIZE
	,  NULL
	, tskIDLE_PRIORITY + priority
	, NULL);
}