/*
 * servo.c
 *
 * Created: 5/11/2022 3:23:11 PM
 *  Author: Alexandru, Dragos, Ionut
 */ 


#include "../Headers/servo.h"



void servo_TurnTask(void *pvParameters)
{	


	for (;;) {
		vTaskDelay(pdMS_TO_TICKS(6000));
		uint16_t temo = organization_get_min_humidity();
		printf("TEMO--->>> %i",temo);
		if (temo != 0 && temo<40)
		{
			printf("SERVO");
			uint16_t actuator=0;
			if (actuator>0)
			{
				rc_servo_setPosition((uint8_t)0, 100);
			}
			else
			{
				rc_servo_setPosition((uint8_t)0, -100);
			}
			
		}
		
		
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
	, 3 // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
	, NULL );
}
