/**
* \file         logger_core.c
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        Very simple implementation of debug output.
*/
//_____ I N C L U D E S _______________________________________________________
#include "logger_core.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#include "logger_output.h"
//_____ C O N F I G S  ________________________________________________________
#define ENDER_CHAR		            		'\n' 
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
static struct 
{
  	severity_t 			severity;
	bool				silence;												
	char 				buffer[LOGGER_MESSAGE_MAX_LEN];
} 	logger_ctx;

//_____ P R I V A T E  F U N C T I O N S_______________________________________
void logger_printf()
{

}

void logger_putc()
{
	
}

void logger_puts()
{
	
}

#if defined(DEBUG_ASSERT)
void __attribute__((noreturn)) __assert_func (const char *file, int line, const char *func, const char *failedexpr)
{
	logr(SEVERITY_FATAL, "Wrong parameters value: file %s on line %d\r\n", file, line);
	abort();
	/* NOTREACHED */
}
#endif


//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
* This function initialization of debug subsystem.
*
* Public function defined in debug.h
*/
void logger_init(severity_t severity)
{
	logger_ctx.silence = false;
	logger_ctx.severity = severity;
}

/**
* This function initialization of debug subsystem.
*
* Public function defined in debug.h
*/
void logger_on(void)
{
	logger_ctx.silence = true;
}

/**
* This function initialization of debug subsystem.
*
* Public function defined in debug.h
*/
void logger_off(void)
{
	logger_ctx.silence = false;
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
* Print debug message into console.
*
* Public function defined in debug.h
*/
void log(severity_t severity, const char* module, const char* fmt, ...)
{
	if(NULL == module || NULL == fmt) {
		return;
	}

	if(!logger_ctx.silence)
	{
		if (logger_ctx.severity <= severity) 
		{
			memset(logger_ctx.buffer, '\0', sizeof(logger_ctx.buffer));

			va_list arp;
			va_start(arp, fmt);		
			vsnprintf(logger_ctx.buffer, LOGGER_MESSAGE_MAX_LEN, fmt, arp);
			va_end(arp);

			size_t offset = strlen(logger_ctx.buffer);
			if(offset < LOGGER_MESSAGE_MAX_LEN) 
			{
				size_t len = LOGGER_MESSAGE_MAX_LEN - offset;
			
				snprintf(&logger_ctx.buffer[offset], len, ";%c;%s;%c", severity, module, ENDER_CHAR);

				logger_output(logger_ctx.buffer, strlen(logger_ctx.buffer));
			}			
		}
	}
}

/**
* Print debug message into console.
*
* Public function defined in debug.h
*/
void logr(const char* fmt, ...)
{
	if(NULL == fmt) {
		return;
	}

	if(!logger_ctx.silence)
	{
		memset(logger_ctx.buffer, '\0', sizeof(logger_ctx.buffer));

		va_list arp;
		va_start(arp, fmt);		
		vsnprintf(logger_ctx.buffer, LOGGER_MESSAGE_MAX_LEN, fmt, arp);
		va_end(arp);

		logger_output(logger_ctx.buffer, strlen(logger_ctx.buffer));	
	}
}

/**
* This function dump a line of binary dump.
*
* Public function defined in debug.h
*/
void logger_mem_dump(const void* buff, uint32_t addr, size_t len, uint32_t width)
{
	int i;
	const unsigned char *bp;
	const unsigned short *sp;
	const unsigned long *lp;

	logr("0x%08lX ", addr);		/* address */

	switch (width)
	{
		case LOGGER_DUMP_WIDTH_8:
			bp = buff;
			for (i = 0; i < len; i++) {		/* Hexdecimal dump */
				logr(" %02X", bp[i]);
			}
			logger_output(' ', 1);
			for (i = 0; i < len; i++) {		/* ASCII dump */
				logger_output((unsigned char)((bp[i] >= ' ' && bp[i] <= '~') ? bp[i] : '.'), 1);
			}
			break;
		case LOGGER_DUMP_WIDTH_16:
			sp = buff;
			do								/* Hexdecimal dump */
				logr(" %04X", *sp++);
			while (--len);
			break;
		case LOGGER_DUMP_WIDTH_32:
			lp = buff;
			do								/* Hexdecimal dump */
				logr(" %08LX", *lp++);
			while (--len);
			break;
	}

	logr(ENDER_CHAR);
}

/**
* This function dump a line of binary dump.
*
* Public function defined in debug.h
*/
void logger_dump(const void* buff, size_t len)
{
	const unsigned char *bp = buff;
	for (int i = 0; i < len; i++) {		/* Hexdecimal dump */
		logr(" %02X", bp[i]);
	}
	logger_output(' ', 1);
	for (int i = 0; i < len; i++) {		/* ASCII dump */
		logger_output((unsigned char)((bp[i] >= ' ' && bp[i] <= '~') ? bp[i] : '.'), 1);
	}
}

