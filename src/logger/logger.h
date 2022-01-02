/**
* \file         logger.h
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        Very simple implementation of debug output.
*/

#pragma once

/* C++ detection */
#ifdef __cplusplus
    extern "C" {
#endif
//_____ I N C L U D E S _______________________________________________________
#include "logger_core.h"

#include <stdbool.h>
#include <stdint.h>
//_____ C O N F I G S  ________________________________________________________
#define LOGGER_MESSAGE_MAX_LEN					256
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
#define LOG_INFO_PARAM(module, fmt, ...)      	log(SEVERITY_INFO, module, fmt, __VA_ARGS__)
#define LOG_WARN_PARAM(module, fmt, ...)      	log(SEVERITY_WARNING, module, fmt, __VA_ARGS__)
#define LOG_ERROR_PARAM(module, fmt, ...)     	log(SEVERITY_ERROR, module, fmt, __VA_ARGS__)
#define LOG_FATAL_PARAM(module, fmt, ...)     	log(SEVERITY_FATAL, module, fmt, __VA_ARGS__)

#define LOG_INFO(module, fmt)      				log(SEVERITY_INFO, module, fmt)
#define LOG_WARN(module, fmt)      				log(SEVERITY_WARNING, module, fmt)
#define LOG_ERROR(module, fmt)     				log(SEVERITY_ERROR, module, fmt)
#define LOG_FATAL(module, fmt)     				log(SEVERITY_FATAL, module, fmt)

#define LOG_DUMP8(buff)     					logger_mem_dump(buff, &buff[0], sizeof(buff)/sizeof(buff[0]), LOGGER_DUMP_WIDTH_8)
#define LOG_DUMP16(buff)     					logger_mem_dump(buff, &buff[0], sizeof(buff)/sizeof(buff[0]), LOGGER_DUMP_WIDTH_16)
#define LOG_DUMP32(buff)     					logger_mem_dump(buff, &buff[0], sizeof(buff)/sizeof(buff[0]), LOGGER_DUMP_WIDTH_32)

//TODO: Need to be reworked
#define LOG_ASSERT(fmt, ...)					LOG_FATAL_PARAM(fmt, __VA_ARGS__, __FILE__, __LINE__)
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________

/* C++ detection */
#ifdef __cplusplus
}
#endif
