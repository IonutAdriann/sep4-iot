/*
 * Application.h
 *
 * Created: 5/29/2022 3:45:26 PM
 *  Author: Ionut
 */ 

#pragma once

#include <ATMEGA_FreeRTOS.h>
#include <task.h>
#include <event_groups.h>
#include <queue.h>
#include <stdio.h>
#include "../Source/headers/Initializers.h"
#include "../Source/headers/SensorDataSharePackage.h"

void applicationTaskRun(UBaseType_t priority);
void applicationTask(void *pvParameters);

