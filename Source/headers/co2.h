/*
 * co2.h
 *
 * Created: 5/5/2022 1:14:54 PM
 *  Author: dragos, alexandru, ionut
 */
 #pragma once

 #include "ATMEGA_FreeRTOS.h"
 #include <stdint.h>


 void Co2_taskRun(void);
 void Co2_getDataFromSensorTask(void *pvParameters)
 void Co2_init();
