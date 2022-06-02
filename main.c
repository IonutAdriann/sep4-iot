/*
* main.c
* Author : IHA
*
* Example main file including LoRaWAN setup
* Just for inspiration :)
*/

#include <stdio.h>
#include <avr/io.h>
#include <ATMEGA_FreeRTOS.h>
#include <task.h>
#include <semphr.h>
#include <stdio_driver.h>
#include <serial.h>
#include <lora_driver.h>
#include <status_leds.h>
#include <event_groups.h>
#include "../Source/headers/tempHumid.h"
#include "../Source/headers/co2.h"
#include "../Source/headers/servo.h"
#include "../Source/headers/LoRaWANHandlerUplink.h"
#include "../Source/headers/LoRaWANDownlinkHandler.h"
#include "../Source/headers/Application.h"
#include "../Source/headers/Initializers.h"
#include "../Source/headers/Organization.h"


extern MessageBufferHandle_t downlinkMessageBuffer;


void taskInitializeData()
{
	initializeTemperatureAndHumiditySemaphore();
	initializeEventGroup();
	initializeDownlinkMessageBuffer();
	initialize_mutex();
	lora_driver_initialise(ser_USART1, downlinkMessageBuffer);
}

/*-----------------------------------------------------------*/
void create_tasks(void)
{
	createTempHumidTask(1);
	createCo2Task(1);
	applicationTaskRun(3);
	lora_uplink_handler_create(4);
	lora_downlink_handler_create(5);
	servo_TaskRun(2);
}


/*-----------------------------------------------------------*/
void initialiseSystem()
{
	stdio_initialise(ser_USART0);
	taskInitializeData();
	create_tasks();
		
}

/*-----------------------------------------------------------*/
int main(void)
{
	initialiseSystem(); 
	printf("Program Started!!\n");
	vTaskStartScheduler(); // Initialize and run the freeRTOS scheduler.


	while (1)
	{
		
	}
}

