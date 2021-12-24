/**
* \file         FWSimpleDebug.c
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        Very simple implementation of debug output.
*/
//_____ I N C L U D E S _______________________________________________________
#include "host_out.h"
#include "logger_port.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
static 	output_fun_t  	output_fn = NULL;

char tx_message[LOG_BUFFER_SIZE];
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
void logger_output_function_reg(output_fun_t out)
{
    assert(out);
	output_fn = out;
}



void logger_output_to_host(const log_msg_t* msg)
{
	memset(tx_message, 0, sizeof(tx_message));

    //TODO: Add serialize/deserialize functions for log_message <--> string
    /*
    tx_message[0] = log_message_get_severity(msg);
	tx_message[1] = LOG_MSG_SEPARATOR;
	tx_message[2] = log_message_get_module(msg);
	tx_message[3] = LOG_MSG_SEPARATOR;

    */

	tx_message[0] = msg->level;
	tx_message[1] = LOG_MSG_SEPARATOR;
	tx_message[2] = msg->module;
	tx_message[3] = LOG_MSG_SEPARATOR;
	strcpy(&tx_message[4], msg->msg);

	size_t len = strlen(tx_message);

	output_fn(tx_message, strlen(tx_message));
}