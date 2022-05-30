/*
 * LoRaWANDownlinkHandler.h
 *
 * Created: 5/27/2022 2:05:22 PM
 *  Author: Ionut, Dragos, Alexandru
 */ 
#pragma once

#include <ATMEGA_FreeRTOS.h>
#include <lora_driver.h>
#include <message_buffer.h>
#include <task.h>
#include <stdint.h>
#include <stdio.h>
#include "../Source/headers/Initializers.h"
#include "../Source/headers/Organization.h"



void lora_downlink_handler_create(UBaseType_t lora_handler_task_priority);