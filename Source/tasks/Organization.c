/*
 * Organization.c
 *
 * Created: 5/29/2022 5:15:50 PM
 *  Author: Ionut / Dragos/ Alexandru
 */ 

#include "../Source/headers/Organization.h"

SemaphoreHandle_t organizeSemaphore;
uint8_t servoLevel;

void Organization_init() {
	
	servoLevel = -100;
	organizeSemaphore = xSemaphoreCreateBinary();
	xSemaphoreGive(organizeSemaphore);
}

void setServoLevel(uint8_t level) {
	
	if(xSemaphoreTake(organizeSemaphore, portMAX_DELAY) == pdTRUE) {
		
		servoLevel = level;
		xSemaphoreGive(organizeSemaphore);
	}
}

uint8_t getServoLevel() {
	if(xSemaphoreTake(organizeSemaphore, portMAX_DELAY) == pdTRUE)
	{
		xSemaphoreGive(organizeSemaphore);
		
	}
	return servoLevel;
}
