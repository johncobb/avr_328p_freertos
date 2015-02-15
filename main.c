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


#include "lwipopts.h"

/* lwIP includes */
#include "lwip/sys.h"
#include "lwip/api.h"
#include "lwip/tcpip.h"
#include "lwip/memp.h"
#include "lwip/stats.h"
#include "netif/loopif.h"
#include "netif/ppp/ppp.h"


#define mainLED_TASK_PRIORITY			(tskIDLE_PRIORITY)
#define mainCOM_TEST_PRIORITY			(tskIDLE_PRIORITY+1)
#define mainCOM_TEST_LED				(tskIDLE_PRIORITY+2)

//#define mainLED_TASK_PRIORITY (tskIDLE_PRIORITY)


/* Baud rate used by the serial port tasks. */
#define mainCOM_TEST_BAUD_RATE			(( unsigned long )38400)


void init(void);

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
static void fnc_tcpip_init_done(void *arg);

static void fnc_tcpip_init_done(void *arg)
{

}
#define PPP_USART_PORT		0
void init(void)
{
	int connected = 0;
	int tcpip_init_done_arg = 0;
	int pd;
	const char *username = "myuser";
	const char *password = "mypassword";

	/* Initialize lwIP and its interface layer. */
	#if LWIP_STATS
		stats_init();
	#endif

	sys_init();
	mem_init();
	memp_init();
	pbuf_init();
	netif_init();

	struct ip_addr ipaddr, netmask, gw;

	IP4_ADDR(&gw, 192, 168, 0, 1);
	IP4_ADDR(&ipaddr, 192, 168, 0, 2);
	IP4_ADDR(&netmask, 255, 255, 255, 0);



	tcpip_init(fnc_tcpip_init_done, &tcpip_init_done_arg);

	while(!tcpip_init_done_arg){
		// TODO: implement sleep
	}


	pppInit();
	pppSetAuth(PPPAUTHTYPE_ANY, username, password);



	pd = pppOpen(PPP_USART_PORT, linkStatusCB, &connected);

	if(pd >= 0)
	{
		while(1) {

//			if(timeout) {
//				// TODO: handle timeout
//				handle_timeout
//			}

			// create sockets
			// do writes and reads on sockets

		}

		pppClose(pd);



	}






}
