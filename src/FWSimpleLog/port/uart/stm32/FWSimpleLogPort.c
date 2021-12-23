/**
* \file    		debug_port.c
* \author  		Kovalchuk Alexander (roux@yandex.ru)
* \brief   		This file contains the prototypes functions which use for...
*/

/*
 * Copyright (c) year Alexander KOVALCHUK
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of library_name.
 *
 * Author:          Alexander KOVALCHUK <roux@yandex.ru>
 */
//_____ I N C L U D E S _______________________________________________________
#include "FWSimpleLog.h"
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

#include "stm32f4xx_hal.h"
#include "rtc.h"

#if !defined(NDEBUG)
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N ___________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E   D E F I N I T I O N  ________________________________
extern UART_HandleTypeDef huart2;
extern DMA_HandleTypeDef hdma_usart2_tx;

char ts[32] = "\0";
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________
//_____ S T A T I C  F U N C T I O N   D E F I N I T I O N   __________________
//_____ F U N C T I O N   D E F I N I T I O N   _______________________________
/**
* This function initialization of debug subsystem.
*
* Public function defined in debug_port.h
*/
bool debug_port_init(void)
{
	return true;
}

/**
* This function transmit symbols to debug console.
*
* Public function defined in debug_port.h
*/
bool debug_port_output(const unsigned char * c, size_t size)
{
#if 0
	HAL_UART_Transmit_DMA(&huart2, c, size);
	while(HAL_DMA_GetState(&hdma_usart2_tx) != HAL_DMA_STATE_READY) {};
	while(__HAL_UART_GET_FLAG(&huart2, UART_FLAG_TXE) != true) {};
#endif
	HAL_UART_Transmit(&huart2, c, size, 1000);
	return true;
}


time_t debug_get_timestamp(void)
{
	// return HAL_GetTick();
	RTC_TimeTypeDef sTime = {0};
	RTC_DateTypeDef DateToUpdate = {0};
	struct tm currTime;

	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN); 
	HAL_RTC_GetDate(&hrtc, &DateToUpdate, RTC_FORMAT_BIN);

	currTime.tm_year = DateToUpdate.Year + 100;  // In fact: 2000 + 18 - 1900
	currTime.tm_mday = DateToUpdate.Date;
	currTime.tm_mon  = DateToUpdate.Month - 1;

	currTime.tm_hour = sTime.Hours;
	currTime.tm_min  = sTime.Minutes;
	currTime.tm_sec  = sTime.Seconds;

	return mktime(&currTime);
}

char* debug_str_timestamp(void)
{
	char* pStr = NULL;
	time_t timestamp = zlog_get_timestamp();

	pStr = ctime(&timestamp);

	size_t len = strlen(pStr);
	// pStr[len-1] = '\0';
	pStr[len-1] = ' ';

	return pStr;
}


#else
/**
* This function initialization of debug subsystem.
*
* Public function defined in debug_port.h
*/
bool zlog_port_init(void)
{
	((void)(0));
	return false;
}

/**
* This function transmit symbols to debug console.
*
* Public function defined in debug_port.h
*/
bool zlog_port_output(const unsigned char * c, size_t size)
{
	((void)(0));
	return false;
}
#endif
