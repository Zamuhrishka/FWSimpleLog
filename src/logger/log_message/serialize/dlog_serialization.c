/**
* \file         FWSimpleDebug.c
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        Very simple implementation of debug output.
*/
//_____ I N C L U D E S _______________________________________________________
#include "dlog_serialization.h"
#include "dlog.h"

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
bool dlog_serialization(const dlog_t* message, char* text)
{
    assert(NULL != message);
    assert(NULL != text);

    size_t text_len = strlen(text);
    if (strlen(LogMessage_GetBody(message)) + strlen(LogMessage_GetModuleName(message) + 3) > text_len) {
        return false;
    }

    memset(text, 0, text_len);

    *text = LogMessage_GetSeverity(message);
    text++;
    *text = LOG_MSG_SEPARATOR;
    text++;
    *text = LogMessage_GetModuleName(message);
    text++;
    *text = LOG_MSG_SEPARATOR;
    text++;

    const char * pBody = LogMessage_GetBody(message);
    if(NULL == pBody) {
        return false;
    }

    return (strcpy(text, pBody) != NULL) ? true : false;
}