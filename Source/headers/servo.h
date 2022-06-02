/*
 * servo.h
 *
 * Created: 5/11/2022 3:23:22 PM
 *  Author: alexandru, ionut, dragos
 */ 
#pragma once

#include <ATMEGA_FreeRTOS.h>
#include <stdint.h>
#include <stdio.h>
#include <rc_servo.h>
#include <task.h>
#include "../Source/headers/Organization.h"
#include "../Source/headers/Initializers.h"
#include "../Source/headers/tempHumid.h"

void servo_TaskRun();
void servo_TurnTask(void *pvParameters);

