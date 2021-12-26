#include "unity.h"

#include "dlog.h"

dlog_t* dlog = NULL;

void setUp(void)
{
    dlog = LogMessage_Create();
}

void tearDown(void)
{
    LogMessage_Destroy(dlog);
}
void test_severity(void)
{
    severity_t severity = SEVERITY_INFO;

    LogMessage_SetSeverity(dlog, SEVERITY_WARNING);
    severity = LogMessage_GetSeverity(dlog);
    TEST_ASSERT_EQUAL_INT(severity, SEVERITY_WARNING);

    LogMessage_SetSeverity(dlog, SEVERITY_INFO);
    severity = LogMessage_GetSeverity(dlog);
    TEST_ASSERT_EQUAL_INT(severity, SEVERITY_INFO);

    LogMessage_SetSeverity(dlog, SEVERITY_ERROR);
    severity = LogMessage_GetSeverity(dlog);
    TEST_ASSERT_EQUAL_INT(severity, SEVERITY_ERROR);

    LogMessage_SetSeverity(dlog, SEVERITY_FATAL);
    severity = LogMessage_GetSeverity(dlog);
    TEST_ASSERT_EQUAL_INT(severity, SEVERITY_FATAL);
}

void test_moduleName(void)
{
    const char* exp_name = "Example module name";

    LogMessage_SetModuleName(dlog, exp_name);
    const char* name = LogMessage_GetModuleName(dlog);
    TEST_ASSERT_EQUAL_STRING(exp_name, name);
}

void test_body(void)
{
    const char* exp_body = "Warning messages from module 2";

    LogMessage_SetBody(dlog, exp_body);
    const char* body = LogMessage_GetBody(dlog);
    TEST_ASSERT_EQUAL_STRING(exp_body, body);
}
