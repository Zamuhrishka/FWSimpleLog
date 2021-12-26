/**
* \file         FWSimpleDebug.c
* \author       Kovalchuk Alexander (roux@yandex.ru)
* \brief        Very simple implementation of debug output.
*/
//_____ I N C L U D E S _______________________________________________________
#include "dlog_serialization.h"

#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

#include "dlog.h"
//_____ C O N F I G S  ________________________________________________________					
//_____ D E F I N I T I O N S _________________________________________________
#define 	LOG_MSG_SPLITTER			','
#define     LOG_MSG_ENDER               '\n'
#define 	LOG_MSG_ENDER_LEN  			sizeof(LOG_MSG_ENDER)
#define 	LOG_MSG_SPLITTER_NUMBER		2
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E S _____________________________________________________
//_____ P R I V A T E  F U N C T I O N S_______________________________________
/**
* Add into perort TLG__SPLITTER_TAG.
*
* Public function defined in @TestsListGenerator.h
*/
static char* DlogSer_AddSplitter(char * message)
{
    size_t  length = 0;
    if(message != NULL) 
    {
        message[length++] = LOG_MSG_SPLITTER;
        return &message[length];
    }

    return NULL;
}

/**
* Add into perort TLG__TEST_NAME_TAG tag and it value.
*
* Public function defined in @TestsListGenerator.h
*/
static char* DlogSer_AddSeverity(char * message, severity_t severity)
{
    if(NULL == message) {
        return NULL;
    }

    *message = severity;

    return &message[sizeof(severity)];
}

/**
* Add into perort TLG__TEST_NAME_TAG tag and it value.
*
* Public function defined in @TestsListGenerator.h
*/
char* DlogSer_AddModuleName(char * message, const char * name)
{
    if(NULL == message) {
        return NULL;
    }

    size_t len = strlen(name);
    if (len != 0) {
        memcpy(message, name, len);
    }

    return &message[len];
}

char* DlogSer_AddBody(char * message, const char * body)
{
    if(NULL == message) {
        return NULL;
    }

    size_t len = strlen(body);
    if (len != 0) {
        memcpy(message, body, len);
    }

    return &message[len];
}

char* DlogSer_AddEnder(char * message)
{
    if(NULL == message) {
        return NULL;
    }

    *message = LOG_MSG_ENDER;

    return &message[LOG_MSG_ENDER_LEN];
}
//_____ P U B L I C  F U N C T I O N S_________________________________________
bool dlog_serialization(const dlog_t* message, char* text, size_t len)
{
    assert(NULL != message);
    assert(NULL != text);

    const char * module = LogMessage_GetModuleName(message);
    const char * body = LogMessage_GetBody(message);
    severity_t severity = LogMessage_GetSeverity(message);

    if ((strlen(body) + strlen(module) + \
        sizeof(severity) + LOG_MSG_SPLITTER_NUMBER) > len) {
        return false;
    }

    char * next = DlogSer_AddSeverity(text, severity);
    if(next != NULL) {
        next = DlogSer_AddSplitter(next);
        if(next != NULL) {
            next = DlogSer_AddModuleName(next, module);
            if(next != NULL) {
                next = DlogSer_AddSplitter(next);
                if(next != NULL) {
                    next = DlogSer_AddBody(next, body);
                    if(next != NULL) {
                        DlogSer_AddEnder(next);
                    }                    
                }
            }
        }
    }

    return NULL != next ? true : false;
}