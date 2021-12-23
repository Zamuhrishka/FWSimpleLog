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
#include <time.h>
//_____ C O N F I G S  ________________________________________________________
// #define LOG_TS_SUPPORT_ENABLE		1

#define 	LOG_MSG_SEPARATOR			','
//_____ D E F I N I T I O N S _________________________________________________
/**
 * \brief	List of debug levels
 */
typedef enum
{
	DBG_INFO 		= 		'0',												///< Allow all debug message
	DBG_WARNING 	= 		'1',												///< Allow warning + error + critical message
	DBG_ERROR 		= 		'2',												///< Allow error + critical message
	DBG_CRITICAL 	= 		'3'													///< Allow only critical message
}	debug_levels_e;

typedef enum
{
	DBG_MODULE_0	= 		'0',
	DBG_MODULE_1	= 		'1',
	DBG_MODULE_2	= 		'2',
	DBG_MODULE_3	= 		'3',
	DBG_MODULE_4	= 		'4',
	DBG_MODULE_5	= 		'5',
	DBG_MODULE_6	= 		'6',
	DBG_MODULE_7	= 		'7',
	DBG_MODULE_8	= 		'8',
	DBG_MODULE_9	= 		'9',
	DBG_MODULE_10	= 		'A',
	DBG_MODULE_11	= 		'B',
	DBG_MODULE_12	= 		'C',
	DBG_MODULE_13	= 		'D',
	DBG_MODULE_14	= 		'E',
	DBG_MODULE_15	= 		'F',
	DBG_MODULE_16	= 		'G',
	DBG_MODULE_17	= 		'H',
	DBG_MODULE_18	= 		'I',
	DBG_MODULE_19	= 		'J',
	DBG_MODULE_20	= 		'K',
	DBG_MODULE_21	= 		'L',
	DBG_MODULE_22	= 		'M',
	DBG_MODULE_23	= 		'N',
	DBG_MODULE_24	= 		'O',
	DBG_MODULE_25	= 		'P',
	DBG_MODULE_26	= 		'Q',
	DBG_MODULE_27	= 		'R',
	DBG_MODULE_28	= 		'S',
	DBG_MODULE_29	= 		'T',
	DBG_MODULE_30	= 		'U',
	DBG_MODULE_31	= 		'V',
	DBG_MODULE_32	= 		'W',
	DBG_MODULE_33	= 		'X',
	DBG_MODULE_34	= 		'Y',
	DBG_MODULE_35	= 		'Z',
}	debug_module_e;

typedef bool (*output_fun_t)(const unsigned char * c, size_t size);

/**
 * \brief   Example of struct typedef definition
 */
typedef struct _tstruct
{
#if defined(LOG_TS_SUPPORT_ENABLE)
    time_t 			timestamp;         											///< example32 elemet
#endif
    debug_levels_e 	level;         												///< example16 elemet
    char 			module;           											///< example8 elemet
	char*			msg;														///< example8 elemet
}   log_msg_t;
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
bool log_init(void);

/*!
* \brief 	Switch on debug.
*
* \param  	none.
*
* \return 	none.
*/
void log_on(void);

/*!
* \brief 	Switch off debug.
*
* \param  	none.
*
* \return 	none.
*/
void log_off(void);

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
void log_set_level(debug_levels_e level);

/*!
* \brief 	Return debug level.
*
* \param  	none.
*
* \return 	active level of debug.
*/
debug_levels_e log_get_level(void);

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
void log(debug_levels_e level, debug_module_e module, const char* fmt, ...);


//#define 	LOG_INFO()
//#define 	LOG_WARN()
//#define 	LOG_ERROR()
//#define 	LOG_FATAL() 

/* C++ detection */
#ifdef __cplusplus
}
#endif
