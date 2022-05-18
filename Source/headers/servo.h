/*
 * servo.h
 *
 * Created: 5/11/2022 3:23:22 PM
 *  Author: alexa
 */ 
#pragma once

#include "ATMEGA_FreeRTOS.h"
#include <stdint.h>

void servo_TaskRun(void);
void servo_TurnTask(void *pvParameters);
void servo_Init();