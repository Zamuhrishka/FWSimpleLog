/**
* \file         log.h
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

#include "logger.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
#define LOG_INFO(module, fmt, ...)      log(DBG_INFO, module, fmt, __VA_ARGS__)
#define LOG_WARN(module, fmt, ...)      log(DBG_WARNING, module, fmt, __VA_ARGS__)
#define LOG_ERROR(module, fmt, ...)     log(DBG_ERROR, module, fmt, __VA_ARGS__)
#define LOG_FATAL(module, fmt, ...)     log(DBG_CRITICAL, module, fmt, __VA_ARGS__)
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________

/* C++ detection */
#ifdef __cplusplus
}
#endif