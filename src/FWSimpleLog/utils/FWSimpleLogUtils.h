/**
* \file         template.h
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        This file contains the prototypes functions which use for...
*/

#pragma once

/* C++ detection */
#ifdef __cplusplus
    extern "C" {
#endif
//_____ I N C L U D E S _______________________________________________________
#include <stdint.h>
#include <stdbool.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
 * \brief		This function convert uint32_t number to string.
 *
 * \param[out] 	str: string that corresponds to number.
 * \param[in] 	dig: number.
 *
 * \return 		void.
**/
void convert_uint32_to_string(char *str, uint32_t dig);

/* C++ detection */
#ifdef __cplusplus
}
#endif