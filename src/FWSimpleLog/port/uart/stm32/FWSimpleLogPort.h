/********************************************************************************
*
* @file    		dbg_port.h
* @author  		Kovalchuk Alexander - 	alexander.kovalchuk@promwad.com
* @brief   		This file contains the prototypes functions and methods,
* 				which use for adding debug functionality
*
********************************************************************************/
#pragma once
//_____ D E F I N I T I O N ___________________________________________________
//_____ I N C L U D E S _______________________________________________________
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <time.h>
//_____ C O N F I G S  ________________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E   D E C L A R A T I O N S _____________________________
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________
//_____ S T A T I �  F U N C T I O N   D E F I N I T I O N   __________________
//_____ F U N C T I O N   D E C L A R A T I O N S _____________________________
bool debug_port_init(void);
bool debug_port_output(const unsigned char * c, size_t size);
time_t debug_get_timestamp(void);
char* debug_str_timestamp(void);
