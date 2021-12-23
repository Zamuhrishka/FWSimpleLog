/**
* \file         template.c
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        This file contains the prototypes functions which use for...
*/
//_____ I N C L U D E S _______________________________________________________
#include "FWSimpleLogUtils.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//! \brief Size in bits
//! \{
enum Constants
{
	U8B		=		0,
	U16B	=		1,
	U32B	=		2,
};
//! \}
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P R I V A T E  F U N C T I O N S_______________________________________
static inline uint8_t count_num(uint32_t dig, uint8_t f_n_bit)
{
	uint8_t num = 0;

	if(f_n_bit == U8B)
	{
		if( (dig / 100) != 0)
			num = 3;
		else if( (dig / 10) != 0)
			num = 2;
		else
			num = 1;
	}

	else if(f_n_bit == U16B)
	{
		if( (dig / 10000) != 0)
			num = 5;
		else if( (dig / 1000) != 0)
			num = 4;
		else if( (dig / 100) != 0)
			num = 3;
		else if( (dig / 10) != 0)
			num = 2;
		else
			num = 1;
	}

	else if(f_n_bit == U32B)
	{
		if( (dig / 1000000000) != 0)
			num = 10;
		else if( (dig / 100000000) != 0)
			num = 9;
		else if( (dig / 10000000) != 0)
			num = 8;
		else if( (dig / 1000000) != 0)
			num = 7;
		else if( (dig / 100000) != 0)
			num = 6;
		else if( (dig / 10000) != 0)
			num = 5;
		else if( (dig / 1000) != 0)
			num = 4;
		else if( (dig / 100) != 0)
			num = 3;
		else if( (dig / 10) != 0)
			num = 2;
		else
			num = 1;
	}

	return(num);
}
//_____ P U B L I C  F U N C T I O N S_________________________________________
/**
* This function used to convert uint32_t number to string.
*
* Public function defined in convert.h
*/
void logger_num_to_string(char *str, uint32_t dig)
{
	uint8_t num = 0;

	num = count_num(dig, U32B);

	switch(num)
	{
		case 1:
			str[0] = (dig % 10) + '0';
			break;
		case 2:
			str[0] = ((dig % 100) / 10) + '0';
			str[1] = (dig % 10) + '0';
			break;
		case 3:
			str[0] = ((dig % 1000) / 100) + '0';
			str[1] = ((dig % 100) / 10) + '0';
			str[2] = (dig % 10) + '0';
			break;
		case 4:
			str[0] = ((dig % 10000) / 1000) + '0';
			str[1] = ((dig % 1000) / 100) + '0';
			str[2] = ((dig % 100) / 10) + '0';
			str[3] = (dig % 10) + '0';
			break;
		case 5:
			str[0] = ((dig % 100000) / 10000) + '0';
			str[1] = ((dig % 10000) / 1000) + '0';
			str[2] = ((dig % 1000) / 100) + '0';
			str[3] = ((dig % 100) / 10) + '0';
			str[4] = (dig % 10) + '0';
			break;
		case 6:
			str[0] = ((dig % 1000000) / 100000) + '0';
			str[1] = ((dig % 100000) / 10000) + '0';
			str[2] = ((dig % 10000) / 1000) + '0';
			str[3] = ((dig % 1000) / 100) + '0';
			str[4] = ((dig % 100) / 10) + '0';
			str[5] = (dig % 10) + '0';
			break;
		case 7:
			str[0] = ((dig % 10000000) / 1000000) + '0';
			str[1] = ((dig % 1000000) / 100000) + '0';
			str[2] = ((dig % 100000) / 10000) + '0';
			str[3] = ((dig % 10000) / 1000) + '0';
			str[4] = ((dig % 1000) / 100) + '0';
			str[5] = ((dig % 100) / 10) + '0';
			str[6] = (dig % 10) + '0';
			break;
		case 8:
			str[0] = ((dig % 100000000) / 10000000) + '0';
			str[1] = ((dig % 10000000) / 1000000) + '0';
			str[2] = ((dig % 1000000) / 100000) + '0';
			str[3] = ((dig % 100000) / 10000) + '0';
			str[4] = ((dig % 10000) / 1000) + '0';
			str[5] = ((dig % 1000) / 100) + '0';
			str[6] = ((dig % 100) / 10) + '0';
			str[7] = (dig % 10) + '0';
			break;
		case 9:
			str[0] = ((dig % 1000000000) / 100000000) + '0';
			str[1] = ((dig % 100000000) / 10000000) + '0';
			str[2] = ((dig % 10000000) / 1000000) + '0';
			str[3] = ((dig % 1000000) / 100000) + '0';
			str[4] = ((dig % 100000) / 10000) + '0';
			str[5] = ((dig % 10000) / 1000) + '0';
			str[6] = ((dig % 1000) / 100) + '0';
			str[7] = ((dig % 100) / 10) + '0';
			str[8] = (dig % 10) + '0';
			break;
		case 10:
			str[0] = ((dig % 10000000000) / 1000000000) + '0';
			str[1] = ((dig % 1000000000) / 100000000) + '0';
			str[2] = ((dig % 100000000) / 10000000) + '0';
			str[3] = ((dig % 10000000) / 1000000) + '0';
			str[4] = ((dig % 1000000) / 100000) + '0';
			str[5] = ((dig % 100000) / 10000) + '0';
			str[6] = ((dig % 10000) / 1000) + '0';
			str[7] = ((dig % 1000) / 100) + '0';
			str[8] = ((dig % 100) / 10) + '0';
			str[9] = (dig % 10) + '0';
			break;
	}
}