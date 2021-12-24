/**
* \file         FWSimpleDebug.c
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        Very simple implementation of debug output.
*/
//_____ I N C L U D E S _______________________________________________________
#include "log_message_serialization.h"
#include "log_message.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
//_____ C O N F I G S  ________________________________________________________					
//_____ D E F I N I T I O N S _________________________________________________
#define 	LOG_MSG_SEPARATOR			','
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
bool log_serialization(const logMessage_t* message, char* text)
{
    assert(NULL != message);
    assert(NULL != text);

    size_t text_len = strlen(text);
    if (strlen(message.body) /*+sizeOfModule + sizeOfSeverity + numberOfSeparators*/  > text_len) {
        return false;
    }

    memset(text, 0, text_len);

    //TODO: Rework this part
    text[0] = LogMessage_GetSeverity(msg);
	text[1] = LOG_MSG_SEPARATOR;
	text[2] = LogMessage_GetModule(msg);
	text[3] = LOG_MSG_SEPARATOR;

    return (strcpy(&text[4], message->body) != NULL) ? true : false;
}