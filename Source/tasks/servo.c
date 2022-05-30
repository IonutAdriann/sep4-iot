/*
 * servo.c
 *
 * Created: 5/11/2022 3:23:11 PM
 *  Author: Alexandru, Dragos, Ionut
 */ 


#include "../Headers/servo.h"
//#include "../Headers/data.h"

//TickType_t xLastWakeTime;
//TickType_t xFrequency;

/*void servo_Init()
{
	rc_servo_initialise();
}*/

void servo_TurnTask(void *pvParameters)
{

	for (;;) {
		
		if (xSemaphoreTake(servoSemaphore, portMAX_DELAY) == pdTRUE) {
			
			printf("Turning on the actuator to the power... ");
			rc_servo_setPosition(1, getServoLevel()); // schimbam in servo power
		}
		vTaskDelay(pdMS_TO_TICKS(100));
		
	}
}


void servo_TaskRun()
{
	rc_servo_initialise();
	
	xTaskCreate(
	servo_TurnTask
	, "Actuator"  // A name just for humans
	, configMINIMAL_STACK_SIZE // This stack size can be checked & adjusted by reading the Stack Highwater
	, NULL
	, tskIDLE_PRIORITY + 3 // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
	, NULL );
}
