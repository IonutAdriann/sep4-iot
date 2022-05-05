/*
 * co2.c
 *
 * Created: 5/5/2022 1:15:22 PM
 *  Author: dragos, alexandru, ionut
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <mh_z19.h>
 #include "../Source/headers/co2.h"
 #include "../Source/headers/data.h"
 #include "semphr.h" ///semaphore library


 TickType_t xLastWakeTime;
 TickType_t xFrequency;
 
 void Co2_init()
 {
 mh_z19_initialise(ser_USART3);
 }
 
 void Co2_taskRun(void)
 {
 xTaskDelayUntil( &xLastWakeTime, xFrequency);
 
 mh_z19_returnCode_t rc;
 
 rc = mh_z19_takeMeassuring();
 
 vTaskDelay(pdMS_TO_TICKS(1200));
 if (rc != MHZ19_OK)
 {
 printf("das ist kaput, scheisse");
 }
 mh_z19_getCo2Ppm(&ppm);
 
 }
 
 void Co2_getDataFromSensorTask(void *pvParameters)
 {
 xFrequency = 5000/portTICK_PERIOD_MS;
 xLastWakeTime = xTaskGetTickCount();

 for(;;)
 {
 Co2_taskRun();
 }
 }

