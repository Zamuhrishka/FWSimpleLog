/**
* \file         logger_core.h
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
#define LOGGER_MESSAGE_MAX_LEN					256
//_____ D E F I N I T I O N S _________________________________________________
/**
 * \brief	List of debug levels
 */
typedef enum
{
	SEVERITY_INFO 						= 		'0',											
	SEVERITY_WARNING 					= 		'1',											
	SEVERITY_ERROR 						= 		'2',											
	SEVERITY_FATAL 						= 		'3',											
}	severity_t;

#define LOGGER_DUMP_WIDTH_8						sizeof(uint8_t)
#define LOGGER_DUMP_WIDTH_16					sizeof(uint16_t)
#define LOGGER_DUMP_WIDTH_32					sizeof(uint32_t)
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
void logger_init(severity_t severity);

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
* \brief 	Print debug message into console.
*
* \param[in]  level: active level of debug.
* \param[in]  fmt: debug string.
*
* \return 	none.
*/
void log(severity_t severity, const char* module, const char* fmt, ...);

/**
 * @brief 
 * 
 * @param[] fmt 
 * @param[] ... 
 */
void logr(const char* fmt, ...);

/**
 * @brief 
 * 
 * @param[] buff 
 * @param[] addr 
 * @param[] len 
 * @param[] width 
 */
void logger_mem_dump(const void* buff, uint32_t addr, size_t len, uint32_t width);

/**
 * @brief 
 * 
 * @param[] buff 
 * @param[] addr 
 * @param[] len 
 */
void logger_dump(const void* buff, size_t len);

/* C++ detection */
#ifdef __cplusplus
}
#endif
