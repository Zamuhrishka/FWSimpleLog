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
//_____ C O N F I G S  ________________________________________________________
#define 	LOG_MSG_SEPARATOR			','
//_____ D E F I N I T I O N S _________________________________________________
/**
 * \brief	List of debug levels
 */
typedef enum
{
	INFO 		= 		'0',												///< Allow all debug message
	WARNING 	= 		'1',												///< Allow warning + error + critical message
	ERROR 		= 		'2',												///< Allow error + critical message
	FATAL 		= 		'3'													///< Allow only critical message
}	severity_t;

typedef enum
{
	LOG_MODULE_0	= 		'0',
	LOG_MODULE_1	= 		'1',
	LOG_MODULE_2	= 		'2',
	LOG_MODULE_3	= 		'3',
	LOG_MODULE_4	= 		'4',
	LOG_MODULE_5	= 		'5',
	LOG_MODULE_6	= 		'6',
	LOG_MODULE_7	= 		'7',
	LOG_MODULE_8	= 		'8',
	LOG_MODULE_9	= 		'9',
	LOG_MODULE_10	= 		'A',
	LOG_MODULE_11	= 		'B',
	LOG_MODULE_12	= 		'C',
	LOG_MODULE_13	= 		'D',
	LOG_MODULE_14	= 		'E',
	LOG_MODULE_15	= 		'F',
	LOG_MODULE_16	= 		'G',
	LOG_MODULE_17	= 		'H',
	LOG_MODULE_18	= 		'I',
	LOG_MODULE_19	= 		'J',
	LOG_MODULE_20	= 		'K',
	LOG_MODULE_21	= 		'L',
	LOG_MODULE_22	= 		'M',
	LOG_MODULE_23	= 		'N',
	LOG_MODULE_24	= 		'O',
	LOG_MODULE_25	= 		'P',
	LOG_MODULE_26	= 		'Q',
	LOG_MODULE_27	= 		'R',
	LOG_MODULE_28	= 		'S',
	LOG_MODULE_29	= 		'T',
	LOG_MODULE_30	= 		'U',
	LOG_MODULE_31	= 		'V',
	LOG_MODULE_32	= 		'W',
	LOG_MODULE_33	= 		'X',
	LOG_MODULE_34	= 		'Y',
	LOG_MODULE_35	= 		'Z',
}	logmod_t;

typedef bool (*output_fun_t)(const unsigned char * c, size_t size);

/**
 * \brief   Example of struct typedef definition
 */
typedef struct tagLog_t
{
    severity_t 		level;         												///< 
    logmod_t		module;           											///<
	char*			msg;														///<
}   log_t;
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/*!
* \brief 	Initialization of debug subsystem.
*
* \param  	none.
*
* \return 	true/false.
*/
bool logger_init(void);

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
void log_output_register(output_fun_t out);

/*!
* \brief 	Print debug message into console.
*
* \param[in]  level: active level of debug.
* \param[in]  fmt: debug string.
*
* \return 	none.
*/
void log(severity_t severity, logmod_t module, const char* fmt, ...);

void logr(const char* fmt, ...);

/* C++ detection */
#ifdef __cplusplus
}
#endif
