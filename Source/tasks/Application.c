/*
 * Application.c
 *
 * Created: 5/29/2022 3:45:07 PM
 *  Author: Ionut/ Alexandru/ Dragos
 */ 

#include "../Source/headers/Application.h"
lora_driver_payload_t payload;
extern MessageBufferHandle_t uplinkMessageBuffer;
extern EventGroupHandle_t measureEventGroup;
extern EventGroupHandle_t dataConfigurationGroup;


void applicationTask(void *pvParameters)
{
	for (;;)
	{
		
		xEventGroupSetBits(measureEventGroup,co2_bit | temperature_and_humidity_bit);
		

		EventBits_t eventBits = xEventGroupWaitBits(dataConfigurationGroup,temperature_and_humidity_bit|co2_bit, pdTRUE, pdTRUE,portMAX_DELAY);
	
		
		if((eventBits &(co2_bit | temperature_and_humidity_bit))==(co2_bit | temperature_and_humidity_bit)) 
		{
			
			SensorDataSharePackage_setCo2_value(get_co2_data());
			SensorDataSharePackage_setTemperature_value(get_temperature_data());
			SensorDataSharePackage_setHumidity_value(get_humidity_data());
			payload=SensorDataSharePackage_getLoraPayload(2);
			xMessageBufferSend(uplinkMessageBuffer,(void*)&payload,sizeof(lora_driver_payload_t),portMAX_DELAY);
			vTaskDelay(pdMS_TO_TICKS(30000));
		}
		vTaskDelay(pdMS_TO_TICKS(50));
	}
}

void applicationTaskRun(UBaseType_t priority)
{
	xTaskCreate(
	applicationTask
	,  "AppTask"
	,  configMINIMAL_STACK_SIZE
	,  NULL
	,  tskIDLE_PRIORITY + priority
	,  NULL );
}

