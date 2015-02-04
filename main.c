/*
 * main.c
 *
 *  Created on: Feb 4, 2015
 *      Author: jcobb
 */
#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "tasks.h" // local tasks defined for os

#define mainLED_TASK_PRIORITY (tskIDLE_PRIORITY)


portSHORT main(void)
{
	xTaskCreate(vLEDFlashTask, (int8_t*) "LED", configMINIMAL_STACK_SIZE, NULL, mainLED_TASK_PRIORITY, NULL);
	vTaskStartScheduler();

	while(1){}

	return 0;
}
