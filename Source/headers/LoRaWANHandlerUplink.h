/*
 * LoRaWANHandlerUplink.h
 *
 * Created: 5/27/2022 1:49:14 PM
 *  Author: Ionut / Alexandru/ Dragos
 */ 

#include <ATMEGA_FreeRTOS.h>
#include <lora_driver.h>
#include <message_buffer.h>
#include <task.h>
#include <status_leds.h>
#include <stddef.h>
#include <stdio.h>

#include "../Source/headers/SensorDataSharePackage.h"
#include "../Source/headers/Initializers.h"



void lora_uplink_handler_create(UBaseType_t lora_handler_task_priority);