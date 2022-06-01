/*
 * LoRaWANDownlinkHandler.c
 *
 * Created: 5/27/2022 2:18:30 PM
 *  Author: Dragos, Ionut, Alexandru
 */ 
#include "../Source/headers/LoRaWANDownlinkHandler.h"
#include "../Source/headers/Initializers.h"
#include "../Source/headers/Organization.h"


extern MessageBufferHandle_t downlinkMessageBuffer;
lora_driver_payload_t downlink_payload;

uint16_t minHumid;

void lora_downlink_handler_run() {
	
	for(;;) {
		
		lora_downlink_handler_task();
	}
	
}


void lora_downlink_handler_task()
{
	
	EventBits_t temp=xMessageBufferReceive(downlinkMessageBuffer, &downlink_payload, sizeof(lora_driver_payload_t), portMAX_DELAY);
	
		if(temp > 0)
		{
			printf("DOWN LINK<<<<<: from port: %d with %d bytes received!",downlink_payload.portNo, downlink_payload.len); 
		
			if (2 == downlink_payload.len)
			{
				
			uint16_t minHumid = (downlink_payload.bytes[0] << 8) + downlink_payload.bytes[1];
			printf("Minimum Humidity  %d", minHumid);
			organization_set_min_humidity(minHumid);
			}
			else {
				
				vTaskDelay(pdMS_TO_TICKS(15000));
			}
		}
}


void lora_downlink_handler_create(UBaseType_t lora_handler_task_priority)
{
		xTaskCreate(
		lora_downlink_handler_run
		,"lora_downlink"
		, configMINIMAL_STACK_SIZE
		, (void*)downlinkMessageBuffer
		,lora_handler_task_priority
		, NULL );
}


