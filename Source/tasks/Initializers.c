/*
 * Initializers.c
 *
 * Created: 5/29/2022 5:38:54 PM
 *  Author: Ionut / Dragos / Alexandru
 */ 
#include "../Source/headers/Initializers.h"

//initialize the temperature and humidity semaphore
void initializeTemperatureAndHumiditySemaphore() {
	temperatureAndHumiditySemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive(temperatureAndHumiditySemaphore);
}
//initialize the mutex
void initialize_mutex() {
	mutex = xSemaphoreCreateMutex();
}
//initialize the eventGroup
void initializeEventGroup() {
	dataConfigurationGroup = xEventGroupCreate();
	measureEventGroup=xEventGroupCreate();
}
//initialize the message buffer for the downlink
void initializeDownlinkMessageBuffer() {
	
	uplinkMessageBuffer=xMessageBufferCreate(sizeof(lora_driver_payload_t) * 2);
	downlinkMessageBuffer = xMessageBufferCreate(sizeof(lora_driver_payload_t) * 2);
}
