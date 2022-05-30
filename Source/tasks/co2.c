/*
 * co2.c
 *
 * Created: 5/5/2022 1:15:22 PM
 *  Author: dragos, alexandru, ionut
 */
 
 #include "../Source/headers/co2.h"
 //#include "../Source/headers/data.h"
 

mh_z19_returnCode_t rc;

 //TickType_t xLastWakeTime;
 //TickType_t xFrequency;
 uint16_t co2_data;
 
 void Co2_init() {
	 
	mh_z19_initialise(ser_USART3);
	mh_z19_injectCallBack(myCo2CallBack);
 }
 
 void Co2_measureTask(void) {
 
	rc = mh_z19_takeMeassuring();
 
	if (rc != MHZ19_OK)
	{
		printf("das ist kaput, scheisse");
	}	
 }
 
 void Co2_getDataFromSensorTask() {
	 
	 while (1) {
		
		 EventBits_t sensorDataBits = xEventGroupWaitBits(measureEventGroup,co2_bit,pdTRUE,pdTRUE,portMAX_DELAY);
		 
		 if ((sensorDataBits & co2_bit) == co2_bit) 
			 Co2_measureTask();
			 
			 vTaskDelay(pdMS_TO_TICKS(50));
	 }
 }
 
 uint16_t get_co2_data() {
	 return co2_data;
 }

void myCo2CallBack(uint16_t* ppm) {
	//xQueueSend(dataSensorQueue , &ppm, portMAX_DELAY);
	co2_data = ppm;
	printf("CO2 Ionut --> %i",co2_data);
	xEventGroupSetBits(dataConfigurationGroup, co2_bit);
	
}

void createCo2Task( UBaseType_t priority) {
	Co2_init();
	xTaskCreate(
	Co2_getDataFromSensorTask
	, "Get data from Sensor task "
	, configMINIMAL_STACK_SIZE
	,  NULL
	, tskIDLE_PRIORITY + priority
	,NULL
	);
}
