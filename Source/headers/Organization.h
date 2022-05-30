/*
 * Organization.h
 *
 * Created: 5/29/2022 5:10:07 PM
 *  Author: Ionut / Dragos/ Alexandru
 */ 

#pragma once

#include <ATMEGA_FreeRTOS.h>
#include <stdint.h>
#include <semphr.h>

extern SemaphoreHandle_t organizeSemaphore;
extern uint8_t servoLevel;

void Organization_init();
void setServoLevel(uint8_t level);
uint8_t getServoLevel();

