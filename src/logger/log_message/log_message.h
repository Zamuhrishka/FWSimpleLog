/**
* \file         log_port.h
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        This file contains the prototypes functions which use for...
*/

#pragma once

/* C++ detection */
#ifdef __cplusplus
    extern "C" {
#endif
//_____ I N C L U D E S _______________________________________________________
#include <stdbool.h>
#include <stdint.h>
//_____ C O N F I G S  ________________________________________________________
#define LOG_BUFFER_SIZE			256u	
//_____ D E F I N I T I O N S _________________________________________________
struct tagLogMessage_t;
typedef struct tagLogMessage_t logMessage_t;

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

//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
logMessage_t* LogMessage_Create(void);
void LogMessage_Destroy(logMessage_t* message);

#if 0
void LogMessage_SetTimestamp(logMessage_t* message, time_t timestamp);
time_t LogMessage_GetTimestamp(const logMessage_t* message);
#endif

void LogMessage_SetSeverity(logMessage_t* message, severity_t sevetiry);
severity_t LogMessage_GetSeverity(const logMessage_t* message);

void LogMessage_SetModule(logMessage_t* message, logmod_t module);
logmod_t LogMessage_GetModule(const logMessage_t* message);

void LogMessage_SetMessage(logMessage_t* message, const char *  message);
const char * LogMessage_GetMessage(const logMessage_t* message);

/* C++ detection */
#ifdef __cplusplus
}
#endif