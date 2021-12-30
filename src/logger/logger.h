/**
* \file         FWSimpleDebug.h
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        Very simple implementation of debug output.
*/

#pragma once

/* C++ detection */
#ifdef __cplusplus
    extern "C" {
#endif
//_____ I N C L U D E S _______________________________________________________
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "dlog.h"
#include "logger_output_interface.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
typedef enum {
	LOGGER__SILENCE_MODE	=	0,
	LOGGER__SIMPLE_MODE,															//Only text messages without severity and module
	LOGGER__FULL_MODE
} Logger_Mode_e;

//_____ M A C R O S ___________________________________________________________
#define LOG_INFO(module, fmt, ...)      log(DBG_INFO, module, fmt, __VA_ARGS__)
#define LOG_WARN(module, fmt, ...)      log(DBG_WARNING, module, fmt, __VA_ARGS__)
#define LOG_ERROR(module, fmt, ...)     log(DBG_ERROR, module, fmt, __VA_ARGS__)
#define LOG_FATAL(module, fmt, ...)     log(DBG_CRITICAL, module, fmt, __VA_ARGS__)
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/*!
* \brief 	Initialization of debug subsystem.
*
* \param  	none.
*
* \return 	true/false.
*/
bool logger_init(Logger_Mode_e mode, severity_t severity);

/*!
* \brief 	Switch on debug.
*
* \param  	none.
*
* \return 	none.
*/
void logger_on(void);

/*!
* \brief 	Switch off debug.
*
* \param  	none.
*
* \return 	none.
*/
void logger_off(void);

/*!
* \brief 	Setup debug level.
*
* \param[in]  level: active level of debug.
* 			DBG_INFO - allow all type of debug message;
* 			DBG_WARNING - common debug messages switch off;
* 			DBG_ERROR - warning and common debug messages switch off;
* 			DBG_CRITICAL - allow only critical debug messages;
*
* \return 	none.
*/
void logger_set_severity(severity_t severity);

/*!
* \brief 	Return debug level.
*
* \param  	none.
*
* \return 	active level of debug.
*/
severity_t logger_get_severity(void);

/*!
* \brief 	Register special function for print debug message.
*
* \param[in]  out: output function
*
* \return 	none.
*/
// void log_output_register(output_fun_t out);

/*!
* \brief 	Print debug message into console.
*
* \param[in]  level: active level of debug.
* \param[in]  fmt: debug string.
*
* \return 	none.
*/
void log(severity_t severity, const char* module, const char* fmt, ...);

void logr(const char* fmt, ...);

/* C++ detection */
#ifdef __cplusplus
}
#endif
