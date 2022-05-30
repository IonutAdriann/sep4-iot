/*
 * configuration.h
 *
 * Created: 5/29/2022 5:23:10 PM
 *  Author: Ionut / Dragos / Alexandru
 */
#pragma once

#include <ATMEGA_FreeRTOS.h>
#include <event_groups.h>
#include <message_buffer.h>
#include <queue.h>
#include <semphr.h>
#include "../drivers/lora_driver.h"


#define temperature_and_humidity_bit (1 << 0)
#define co2_bit (1 << 1)


 EventGroupHandle_t dataConfigurationGroup; 
 EventGroupHandle_t measureEventGroup;
 MessageBufferHandle_t downlinkMessageBuffer;
  MessageBufferHandle_t uplinkMessageBuffer;
 QueueHandle_t dataSensorQueue;
 SemaphoreHandle_t temperatureAndHumiditySemaphore;
 SemaphoreHandle_t servoSemaphore;

void initializeDownlinkMessageBuffer();
void initializeEventGroup();
void initializeQueue();
void initializeTemperatureAndHumiditySemaphore();
void initializeServoSemaphore();