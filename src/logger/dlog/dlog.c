/**
* \file         dlog.c
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        Very simple implementation of debug output.
*/
//_____ I N C L U D E S _______________________________________________________
#include "dlog.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
//_____ C O N F I G S  ________________________________________________________           					
//_____ D E F I N I T I O N S _________________________________________________
/**
 * \brief   Example of struct typedef definition
 */
struct tagDebugLog_t
{
    severity_t 		severity;         												
    char		    module[DLOG_MODULE_MAX_LEN];           											
	char			body[DLOG_BODY_MAX_LEN];														
};
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
static dlog_t log = {0};
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
dlog_t* LogMessage_Create(void)
{
    return &log;
}

void LogMessage_Destroy(dlog_t* message)
{
    message->severity = SEVERITY_INFO;
    memset(message->body, '\0', sizeof(message->body));
    memset(message->module, '\0', sizeof(message->module));
}

void LogMessage_SetSeverity(dlog_t* message, severity_t sevetiry)
{
    assert(message);

    message->severity = sevetiry;
}

severity_t LogMessage_GetSeverity(const dlog_t* message)
{
    assert(message);

    return message->severity;
}

void LogMessage_SetModuleName(dlog_t* message, const char * module_name)
{
    assert(message);

    size_t len = strlen(module_name);
    len = (len < DLOG_MODULE_MAX_LEN) ? len : DLOG_MODULE_MAX_LEN;

    strncpy(message->module, module_name, len);
}

const char * LogMessage_GetModuleName(const dlog_t* message)
{
    assert(message);

    return message->module;
}

void LogMessage_SetBody(dlog_t* message, const char *  body)
{
    assert(message);

    size_t len = strlen(body);
    len = (len < DLOG_BODY_MAX_LEN) ? len : DLOG_BODY_MAX_LEN;

    strncpy(message->body, body, len);
}

const char * LogMessage_GetBody(const dlog_t* message)
{
    assert(message);

    return message->body;
}