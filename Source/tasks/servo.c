/*
 * servo.c
 *
 * Created: 5/11/2022 3:23:11 PM
 *  Author: Alexandru, Dragos, Ionut
 */ 
#include "../Headers/servo.h"


//task for the servo to turn
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

// task for the servo to run
void servo_TaskRun()
{
	rc_servo_initialise();
	
	xTaskCreate(
	servo_TurnTask
	, "Actuator"  // A name for humans
	, configMINIMAL_STACK_SIZE 
	, NULL
	, 3 // Priority setter
	, NULL );
}
