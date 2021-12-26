/**
* \file         dlog.h
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
#define DLOG_BODY_LEN						256
#define DLOG_MODULE_NAME_MAX_LEN            32  
//_____ D E F I N I T I O N S _________________________________________________
struct tagDebugLog_t;
typedef struct tagDebugLog_t dlog_t;

/**
 * \brief	List of debug levels
 */
typedef enum
{
	SEVERITY_INFO 		= 		'0',												///<
	SEVERITY_WARNING 	= 		'1',												///<
	SEVERITY_ERROR 		= 		'2',												///<
	SEVERITY_FATAL 		= 		'3'													///<
}	severity_t;

//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
dlog_t* LogMessage_Create(void);
void LogMessage_Destroy(dlog_t* message);

void LogMessage_SetSeverity(dlog_t* message, severity_t sevetiry);
severity_t LogMessage_GetSeverity(const dlog_t* message);

void LogMessage_SetModuleName(dlog_t* message, const char * module_name);
const char * LogMessage_GetModuleName(const dlog_t* message);

void LogMessage_SetBody(dlog_t* message, const char *  body);
const char * LogMessage_GetBody(const dlog_t* message);

/* C++ detection */
#ifdef __cplusplus
}
#endif