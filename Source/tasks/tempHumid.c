/*
 * tempHumid.c
 *
 * Created: 5/3/2022 1:18:44 PM
 *  Author: alexandu, ionut, dragos
 */ 

#include "../headers/tempHumid.h"

//define default values for temperature and humidity
float temperature_data = 0.0;
uint16_t humidity_data = 0;

// task to initialize the drivers
void TempHumid_init()
{
	if (HIH8120_OK == hih8120_initialise())
	{
		printf("The driver for temperature and humidity is initialized"); //The driver is initialized.
	}
	else
	{	
		printf("The driver didn't start");// The driver didn't initialize.
	}
}

// task for the temperature and humidity for the sensor to work
void TempHumid_measureTask(void)
{
	
	
	if (HIH8120_OK != hih8120_wakeup())
	{
		printf("Temperature&humidity sensor didn't wake up retrying");	//The sensor didn't wake up
		
	}
	vTaskDelay(pdMS_TO_TICKS(100));
	
	if ( HIH8120_OK !=  hih8120_measure())
	{
		printf("Temperature&humidity sensor could not perform measurement "); //The sensor coudn't perform the measurement 
		
	}
	
	vTaskDelay(pdMS_TO_TICKS(20));
	
}

// create task to perform measurement for the temperature and humidity
void createTempHumidTask(UBaseType_t priority) {
	TempHumid_init(); 
	
	xTaskCreate (
	TempHumid_getDataFromSensorTask
	, "Get data from Sensor task"
	, configMINIMAL_STACK_SIZE
	,  NULL
	, priority
	, NULL);
}

void TempHumid_getDataFromSensorTask(void *pvParameters)
{
	while (1) {
		
		xEventGroupWaitBits(measureEventGroup,temperature_and_humidity_bit,pdTRUE,pdTRUE,portMAX_DELAY);
		
			
			TempHumid_measureTask();
			temperature_data = hih8120_getTemperature_x10();
			humidity_data = hih8120_getHumidityPercent_x10();
			printf("Temperature and Humidity task created  ");
			xEventGroupSetBits(dataConfigurationGroup,temperature_and_humidity_bit);
		
		vTaskDelay(pdMS_TO_TICKS(10));
	}
}
// getter for temperature data
uint16_t get_temperature_data() {
	
	return temperature_data;
}
// getter for humidity data
uint16_t get_humidity_data() {
	
	return humidity_data;
}

