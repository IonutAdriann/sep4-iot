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


void organization_set_min_humidity();
uint16_t organization_get_min_humidity();

