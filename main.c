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
#include "Drivers/partest.h"
#include "Drivers/serial.h"
#include "Drivers/comtest.h"
#include "Drivers/partest.h"


#define mainLED_TASK_PRIORITY			(tskIDLE_PRIORITY)
#define mainCOM_TEST_PRIORITY			(tskIDLE_PRIORITY+1)
#define mainCOM_TEST_LED				(tskIDLE_PRIORITY+2)

//#define mainLED_TASK_PRIORITY (tskIDLE_PRIORITY)


/* Baud rate used by the serial port tasks. */
#define mainCOM_TEST_BAUD_RATE			(( unsigned long )38400)


void vApplicationIdleHook( void );

portSHORT main(void)
{
	//xTaskCreate(vLEDFlashTask, (int8_t*) "LED", configMINIMAL_STACK_SIZE, NULL, mainLED_TASK_PRIORITY, NULL);

	vParTestInitialise();

	vAltStartComTestTasks(mainCOM_TEST_PRIORITY, mainCOM_TEST_BAUD_RATE, mainCOM_TEST_LED);

	vTaskStartScheduler();

	return 0;
}


void vApplicationIdleHook( void )
{
	//vCoRoutineSchedule();
}
