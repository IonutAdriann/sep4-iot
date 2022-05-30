/*
 * SensorDataSharePackage.h
 *
 * Created: 5/29/2022 4:20:27 PM
 *  Author: Ionut / Dragos/ Alexandru
 */ 
#pragma once

#include <ATMEGA_FreeRTOS.h>
#include <lora_driver.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


void SensorDataSharePackage_setPackage_lenght(uint8_t lenght);
void SensorDataSharePackage_setTemperature_value(uint16_t value);
void SensorDataSharePackage_setHumidity_value(uint16_t value);
void SensorDataSharePackage_setCo2_value(uint16_t value);
void SensorDataSharePackage_setServo(uint8_t servo_state);
lora_driver_payload_t SensorDataSharePackage_getLoraPayload(uint8_t port_No);
