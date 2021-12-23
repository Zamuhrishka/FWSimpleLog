/**
* \file         FWSimpleDebug.c
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        Very simple implementation of debug output.
*/
//_____ I N C L U D E S _______________________________________________________
#include "FWSimpleLog.h"
#include "FWSimpleLogUtils.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#if !defined(NDEBUG)
//_____ C O N F I G S  ________________________________________________________
///Size of debug queue
#define LOG_BUFFER_SIZE			256u											
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
static struct 
{
  	severity_t 		severity; 														///<
	bool 			silence; 														///<
	output_fun_t  	output_fn; 														///<
	char 			string[LOG_BUFFER_SIZE];
	log_t			message;
} 	logger_ctx;

char tx_message[LOG_BUFFER_SIZE];
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
* This function initialization of debug subsystem.
*
* Public function defined in debug.h
*/
bool logger_init(void)
{
	logger_ctx.silence = false;
	logger_ctx.severity = INFO;
	logger_ctx.output_fn = NULL;

	memset(logger_ctx.string, '\0', LOG_BUFFER_SIZE);

	return true;
}

/**
* This function switch debug on.
*
* Public function defined in debug.h
*/
void logger_on(void)
{
	logger_ctx.silence = false;
}

/**
* This function switch debug off.
*
* Public function defined in debug.h
*/
void logger_off(void)
{
	logger_ctx.silence = true;
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
void logger_output_register(output_fun_t out)
{
	assert(out);
	logger_ctx.output_fn = out;
}

/**
* Print debug message into console.
*
* Public function defined in debug.h
*/
void log(debug_levels_e level, debug_module_e module, const char* fmt, ...)
{
	va_list arp;

	if(!logger_ctx.quiet)
	{
		if (logger_ctx.level <= level) 
		{
#if defined(LOG_TS_SUPPORT_ENABLE)
			if(logger_ctx.ts) 
			{
				logger_ctx.message.timestamp = debug_get_timestamp();
			}
#endif
			logger_ctx.message.level = level;
			logger_ctx.message.module = module;

			va_start(arp, fmt);
			vsnprintf(logger_ctx.string, LOG_BUFFER_SIZE, fmt, arp);
			va_end(arp);

			logger_ctx.message.msg = &logger_ctx.string[0];

			logger_stransmit_to_host(&logger_ctx.message);
		}
	}
}



void logger_stransmit_to_host(const log_msg_t* msg)
{
	memset(tx_message, 0, sizeof(tx_message));
	// tx_message[0] = '<';
	tx_message[0] = msg->level;
	tx_message[1] = LOG_MSG_SEPARATOR;
	tx_message[2] = msg->module;
	tx_message[3] = LOG_MSG_SEPARATOR;
	strcpy(&tx_message[4], msg->msg);

	size_t len = strlen(tx_message);
	// tx_message[len] = '>';

	logger_ctx.output_fn(tx_message, strlen(tx_message));
}

void logger_save_to_flash(const log_msg_t* msg)
{
	va_list arp;
	size_t len = 0;
	char* ptr = NULL;

	memset(tx_message, 0, sizeof(tx_message));
#if defined(LOG_TS_SUPPORT_ENABLE)
	if(logger_ctx.ts) 
	{
		char ts[10] = {0};

		convert_uint32_to_string(ts, msg->timestamp);
		ptr = strcat(tx_message, ts);
		len = strlen(tx_message);
		tx_message[len] = LOG_MSG_SEPARATOR;
	}
#endif
}

#else
/**
* This function initialization of debug subsystem.
*
* Public function defined in debug.h
*/
bool debug_init(void)
{
	((void)(0));
	return true;
}

/**
* This function switch debug on.
*
* Public function defined in debug.h
*/
void debug_on(void)
{
	((void)(0));
}

/**
* This function switch debug off.
*
* Public function defined in debug.h
*/
void debug_off(void)
{
	((void)(0));
}

/**
* This function setup debug level.
*
* Public function defined in debug.h
*/
void debug_set_level(debug_levels_e level)
{
	((void)(0));
}

/**
* This function return debug level.
*
* Public function defined in debug.h
*/
debug_levels_e debug_get_level(void)
{
	((void)(0));
	return debug_level;
}

/**
* Register special function for print debug message.
*
* Public function defined in debug.h
*/
void debug_output_register(output_fun_t out)
{
	((void)(0));	
}

/**
* This function print debug message into console.
*
* Public function defined in debug.h
*/
void debug_print(debug_levels_e level, const char* fmt, ...)
{
	((void)(0));
}

#endif
