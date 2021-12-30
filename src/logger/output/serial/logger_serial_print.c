/**
* \file         FWSimpleDebug.c
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        Very simple implementation of debug output.
*/
//_____ I N C L U D E S _______________________________________________________
#include "logger_serial_print.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#include "serial_port.h"
#include "dlog_serialization.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
static char text[DLOG_BODY_MAX_LEN] = "";
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
void logger_output_init(void)
{
	logger_port_init();
}

void logger_serial_print(const dlog_t* msg)
{
	assert(msg);

	if(dlog_serialization(msg, text, sizeof(text))) 
	{
		logger_port_output(text, strlen(text));
		memset(text, '\0', sizeof(text));
	}
}