/*
 * sio.c
 *
 *  Created on: Feb 12, 2015
 *      Author: jcobb
 */

#include "lwip/sio.h"
#include "netif/ppp/ppp.h"


void linkStatusCB(void *ctx, int errCode, void *arg)
{
	int *connected = (int*) ctx;

	struct ppp_addrs *addrs = arg;

	if(errCode == PPPERR_NONE) {
		// life's good
		*connected = 1;

//		syslog(LOG_DEBUG, "ip_addr = %s", inet_ntoa(addrs->our_ipaddr));
//		syslog(LOG_DEBUG, "netmask = %s", inet_ntoa(addrs->netmask));
//		syslog(LOG_DEBUG, "dns1    = %s", inet_ntoa(addrs->dns1));
//		syslog(LOG_DEBUG, "dns2    = %s", inet_ntoa(addrs->dns2));
	} else {
		// connection lost
	}
}


sio_fd_t sio_open(u8_t x)
{
	sio_fd_t a = 0;
	return a;

}

void sio_send(u8_t x, sio_fd_t y)
{

}

u8_t sio_recv(sio_fd_t x)
{
	u8_t a = 0;
	return a;
}

u32_t sio_read(sio_fd_t fd, u8_t *data, u32_t len)
{
	u32_t tmp = 0;
	return tmp;
}

u32_t sio_write(sio_fd_t fd, u8_t *data, u32_t len)
{
	u32_t tmp = 0;
	return tmp;
}

void sio_read_abort(sio_fd_t fd)
{

}
