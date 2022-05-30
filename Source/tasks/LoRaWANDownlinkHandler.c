/*
 * LoRaWANDownlinkHandler.c
 *
 * Created: 5/27/2022 2:18:30 PM
 *  Author: Dragos, Ionut, Alexandru
 */ 
#include "../Source/headers/LoRaWANDownlinkHandler.h"

lora_driver_payload_t downlink_payload;

void lora_downlink_task()
{
		for(;;)
		{
			xMessageBufferReceive(downlinkMessageBuffer, &downlink_payload, sizeof(lora_driver_payload_t), portMAX_DELAY);
			printf("DOWN LINK<<<<<: from port: %d with %d bytes received!",downlink_payload.portNo, downlink_payload.len); ///ev aici putem schimba ca ar arata cam identic cu ei
		
			if (4 == downlink_payload.len)
			{
				uint8_t level =  (downlink_payload.bytes[0]);
				setServoLevel(level); ///asta dam remove
				xSemaphoreGive(servoSemaphore);  //aici trb schimbat iar
			}

			vTaskDelay(pdMS_TO_TICKS(100));
		}
		
}


void lora_downlink_handler_create(UBaseType_t lora_handler_task_priority)
{

		xTaskCreate(
		lora_downlink_task,
		"lora_downlink"
		, configMINIMAL_STACK_SIZE
		, NULL
		,tskIDLE_PRIORITY + lora_handler_task_priority
		, NULL );
}


