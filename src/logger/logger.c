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
	Logger_Mode_e 	mode;

	logger_output_fpt output;
	
	char 			string[LOG_BUFFER_SIZE];
	logMessage_t*			log;
} 	logger_ctx;

//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
* This function initialization of debug subsystem.
*
* Public function defined in debug.h
*/
bool logger_init(void)
{
	logger_ctx.mode = LOGGER__FULL_MODE;
	logger_ctx.severity = INFO;
	logger_ctx.output = NULL;

	logger_ctx.log = LogMessage_Create();
	if(NULL == logger_ctx.log) {
		return false;
	}

	memset(logger_ctx.string, '\0', LOG_BUFFER_SIZE);

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

// /**
// * This function switch debug on.
// *
// * Public function defined in debug.h
// */
// void logger_on(void)
// {
// 	logger_ctx.silence = false;
// }

// /**
// * This function switch debug off.
// *
// * Public function defined in debug.h
// */
// void logger_off(void)
// {
// 	logger_ctx.silence = true;
// }

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
// void logger_output_register(output_fun_t out)
// {
// 	assert(out);
// 	logger_ctx.output_fn = out;
// }

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
void log(severity_t severity, logmod_t module, const char* fmt, ...)
{
	va_list arp;

	if(!logger_ctx.mode != LOGGER__SILENCE_MODE)
	{
		if (logger_ctx.severity <= severity) 
		{
#if defined(LOG_TS_SUPPORT_ENABLE)
			if(logger_ctx.ts) 
			{
				logger_ctx.message.timestamp = debug_get_timestamp();
			}
#endif
			// logger_ctx.message.severity = severity;
			// logger_ctx.message.module = module;


			LogMessage_SetSeverity(logger_ctx.message, sevetiry);
			LogMessage_SetModule(logger_ctx.message, module);

			//FIXME: Possible stack overflow situation
			assert(strlen(fmt) < LOG_BUFFER_SIZE);

			// va_start(arp, fmt);
			// vsnprintf(logger_ctx.string, LOG_BUFFER_SIZE, fmt, arp);
			// va_end(arp);


			va_start(arp, fmt);
			vsnprintf(LogMessage_GetMessage(), LOG_BUFFER_SIZE, fmt, arp);
			va_end(arp);

			logger_ctx.message.msg = &logger_ctx.string[0];

			if (NULL != logger_ctx.output)
			{
				logger_ctx.output(&logger_ctx.message);
			}
		}
	}
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
