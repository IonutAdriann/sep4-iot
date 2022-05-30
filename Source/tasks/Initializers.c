/*
 * Initializers.c
 *
 * Created: 5/29/2022 5:38:54 PM
 *  Author: Ionut / Dragos / Alexandru
 */ 
#include "../Source/headers/Initializers.h"


void initializeTemperatureAndHumiditySemaphore() {
	temperatureAndHumiditySemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive(temperatureAndHumiditySemaphore);
}

void initializeServoSemaphore() {
	servoSemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive(servoSemaphore);
}

void initializeQueue() {
	dataSensorQueue = xQueueCreate(3, sizeof(uint16_t));
}

void initializeEventGroup() {
	dataConfigurationGroup = xEventGroupCreate();
	measureEventGroup=xEventGroupCreate();
}

void initializeDownlinkMessageBuffer() {
	
	uplinkMessageBuffer=xMessageBufferCreate(sizeof(lora_driver_payload_t) * 2);
	downlinkMessageBuffer = xMessageBufferCreate(sizeof(lora_driver_payload_t) * 2);
}
