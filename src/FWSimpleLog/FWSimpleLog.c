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
#define LOG_BUFFER_SIZE			256u											///< Size of debug queue
//_____ D E F I N I T I O N S _________________________________________________
// #if defined(DBG_COLOR_SUPPORT)
// static const char* colors[] =
// {
// 	"",
// 	"\033[33m",
// 	"\033[31m",
// 	"\033[91m\033[1m"
// };
// #endif

// static char level_names[] = 
// {
//   '0', 
//   '1', 
//   '2', 
//   '3'
// };
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
static struct 
{
  	debug_levels_e 	level; 															///< 0 (TRACE) to 5 (FATAL)
	bool 			quiet; 															///< if console logging is silent/quiet
#if defined(LOG_TS_SUPPORT_ENABLE)
	bool			ts;
#endif
	output_fun_t  	output_fn; 														///< I/O for console logging
	char 			string[LOG_BUFFER_SIZE];
	log_msg_t		message;
} 	log_context;

char tx_message[LOG_BUFFER_SIZE];
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
* This function initialization of debug subsystem.
*
* Public function defined in debug.h
*/
bool log_init(void)
{
	log_context.quiet = false;
	log_context.level = DBG_INFO;
	log_context.output_fn = NULL;

#if defined(LOG_TS_SUPPORT_ENABLE)
	log_context.ts = true;
#endif

	memset(log_context.string, '\0', LOG_BUFFER_SIZE);

	return true;
}

/**
* This function switch debug on.
*
* Public function defined in debug.h
*/
void log_on(void)
{
	log_context.quiet = false;
}

/**
* This function switch debug off.
*
* Public function defined in debug.h
*/
void log_off(void)
{
	log_context.quiet = true;
}

/**
* This function setup debug level.
*
* Public function defined in debug.h
*/
void log_set_level(debug_levels_e level)
{
	log_context.level = level;
}

/**
* This function return debug level.
*
* Public function defined in debug.h
*/
debug_levels_e log_get_level(void)
{
	return log_context.level;
}

/**
* Register special function for print debug message.
*
* Public function defined in debug.h
*/
void log_output_register(output_fun_t out)
{
	assert(out);
	log_context.output_fn = out;
}

/**
* Print debug message into console.
*
* Public function defined in debug.h
*/
void log(debug_levels_e level, debug_module_e module, const char* fmt, ...)
{
	va_list arp;

	if(!log_context.quiet)
	{
		if (log_context.level <= level) 
		{
#if defined(LOG_TS_SUPPORT_ENABLE)
			if(log_context.ts) 
			{
				log_context.message.timestamp = debug_get_timestamp();
			}
#endif
			log_context.message.level = level;
			log_context.message.module = module;

			va_start(arp, fmt);
			vsnprintf(log_context.string, LOG_BUFFER_SIZE, fmt, arp);
			va_end(arp);

			log_context.message.msg = &log_context.string[0];

			log_stransmit_to_host(&log_context.message);
		}
	}
}



void log_stransmit_to_host(const log_msg_t* msg)
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

	log_context.output_fn(tx_message, strlen(tx_message));
}

void log_save_to_flash(const log_msg_t* msg)
{
	va_list arp;
	size_t len = 0;
	char* ptr = NULL;

	memset(tx_message, 0, sizeof(tx_message));
#if defined(LOG_TS_SUPPORT_ENABLE)
	if(log_context.ts) 
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
