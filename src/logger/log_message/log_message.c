/**
* \file         FWSimpleDebug.c
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        Very simple implementation of debug output.
*/
//_____ I N C L U D E S _______________________________________________________
#include "log_message.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
//_____ C O N F I G S  ________________________________________________________					
//_____ D E F I N I T I O N S _________________________________________________
/**
 * \brief   Example of struct typedef definition
 */
struct tagLogMessage_t
{
    #if 0
    time_t timestamp;
    #endif
    severity_t 		severity;         												
    logmod_t		module;           											
	char			body[LOG_BUFFER_SIZE];														
};
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
static logMessage_t log_message = {0};
//_____ P R I V A T E  F U N C T I O N S_______________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________
logMessage_t* LogMessage_Create(void)
{
    return &log_message;
}

void LogMessage_Destroy(logMessage_t* message)
{

}

#if 0
void LogMessage_SetTimestamp(logMessage_t* message, time_t timestamp)
{

}

time_t LogMessage_GetTimestamp(const logMessage_t* message)
{

}
#endif

void LogMessage_SetSeverity(logMessage_t* message, severity_t sevetiry)
{
    assert(message);

    //TODO: Check severity on valid range
    message->severity = sevetiry;
}

severity_t LogMessage_GetSeverity(const logMessage_t* message)
{
    assert(message);

    return message->severity;
}

void LogMessage_SetModule(logMessage_t* message, logmod_t module)
{
    assert(message);

    message->module = module;
}

logmod_t LogMessage_GetModule(const logMessage_t* message)
{
    assert(message);

    return message->module;
}

void LogMessage_SetMessage(logMessage_t* message, const char *  message)
{
    assert(message);

    if(strlen(message) <= LOG_BUFFER_SIZE) 
    {
        char* res = strcpy(message.body, message);
    }
}

const char * LogMessage_GetMessage(const logMessage_t* message)
{
    assert(message);

    return message->body;
}