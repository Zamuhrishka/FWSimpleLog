/**
* \file         FWSimpleDebug.c
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        Very simple implementation of debug output.
*/
//_____ I N C L U D E S _______________________________________________________
#include "logger.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#include "logger_output_interface.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
static struct 
{
  	severity_t 			severity; 													
	Logger_Mode_e 		mode;
	logger_output_fpt 	output;	
	dlog_t*				log;
} 	logger_ctx;

//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
* This function initialization of debug subsystem.
*
* Public function defined in debug.h
*/
bool logger_init(Logger_Mode_e mode, severity_t severity)
{
	logger_ctx.log = LogMessage_Create();
	if(NULL == logger_ctx.log) {
		return false;
	}

	logger_ctx.mode = mode;
	logger_ctx.severity = severity;
	logger_ctx.output = NULL;

	logger_output_init();

	return true;
}

void logger_set_mode(Logger_Mode_e mode)
{
	logger_ctx.mode = mode;
}

Logger_Mode_e logger_get_mode(void)
{
	return logger_ctx.mode;
}

/**
* This function setup debug level.
*
* Public function defined in debug.h
*/
void logger_set_severity(severity_t severity)
{
	logger_ctx.severity = severity;
}

/**
* This function return debug level.
*
* Public function defined in debug.h
*/
severity_t logger_get_severity(void)
{
	return logger_ctx.severity;
}

/**
* Register special function for print debug message.
*
* Public function defined in debug.h
*/
void logger_output_register(logger_output_fpt out)
{
	assert(out);
	logger_ctx.output = out;
}

/**
* Print debug message into console.
*
* Public function defined in debug.h
*/
void log(severity_t severity, const char* module, const char* fmt, ...)
{
	//TODO: Add semophor support
	if(logger_ctx.mode != LOGGER__SILENCE_MODE)
	{
		if (logger_ctx.severity <= severity) 
		{
			LogMessage_SetSeverity(logger_ctx.log, severity);
			LogMessage_SetModule(logger_ctx.log, module);

			va_list arp;
			va_start(arp, fmt);
			vsnprintf(LogMessage_GetMessage(), DLOG_BODY_MAX_LEN, fmt, arp);
			va_end(arp);

			if (NULL != logger_ctx.output) {
				logger_ctx.output(&logger_ctx.message);
			}
		}
	}
}

