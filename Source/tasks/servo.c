/*
 * servo.c
 *
 * Created: 5/11/2022 3:23:11 PM
 *  Author: Alexandru, Dragos, Ionut
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <rc_servo.h>

#include "../Headers/servo.h"
#include "../Headers/data.h"

TickType_t xLastWakeTime;
TickType_t xFrequency;

void servo_Init()
{
	rc_servo_initialise();
}

void servo_TaskRun(void)
{
	xTaskDelayUntil(&xLastWakeTime, xFrequency);
	if (minHumidity > humidity  )
	{
		rc_servo_setPosition(1, -100);
	}
	else 
	{
		rc_servo_setPosition(1, 100);
	}
}

void servo_TurnTask(void *pvParameters)
{
	xFrequency = 5000/portTICK_PERIOD_MS;
	
	xLastWakeTime = xTaskGetTickCount();
	
	for (;;)
	{
		servo_TaskRun();
	}
}