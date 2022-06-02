/*
 * Organization.c
 *
 * Created: 5/29/2022 5:15:50 PM
 *  Author: Ionut / Dragos/ Alexandru
 */ 

#include "../Source/headers/Organization.h"
#include "../Source/headers/Initializers.h"

uint16_t hum_data;
extern SemaphoreHandle_t mutex;


void organization_set_min_humidity(uint16_t min_humidity_data) {
	printf("set here");
	hum_data=1;
	if (xSemaphoreTake(mutex, pdMS_TO_TICKS(200)) == pdTRUE)
	{
		printf("set inside");
		hum_data = min_humidity_data;
		xSemaphoreGive(mutex);
	}
	
}

uint16_t organization_get_min_humidity() {
	 // the value is used to determine if the iot can get the hum from the gateway app
	return hum_data;
}


