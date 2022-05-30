/*
 * co2.h
 *
 * Created: 5/5/2022 1:14:54 PM
 *  Author: dragos, alexandru, ionut
 */
 #pragma once

 #include <ATMEGA_FreeRTOS.h>
 #include <stdio.h>
 #include <mh_z19.h>
 #include <event_groups.h>
 #include "../Source/headers/Initializers.h"
 

 extern mh_z19_returnCode_t rc;

 void Co2_measureTask();
 void Co2_getDataFromSensorTask();
 uint16_t get_co2_data();
 void Co2_init();
 void myCo2CallBack(uint16_t* ppm);
 void createCo2Task(UBaseType_t priority);
 
