#include "unity.h"

#include "dlog_serialization.h"
#include "dlog.h"

dlog_t* dlog = NULL;

void setUp(void)
{
    dlog = LogMessage_Create();

    LogMessage_SetSeverity(dlog, SEVERITY_WARNING);
    LogMessage_SetModuleName(dlog, "GPS");
    LogMessage_SetBody(dlog, "Warning messages from module 2");
}

void tearDown(void)
{
    LogMessage_Destroy(dlog);
}

void test_serialization(void)
{
    char exp_text = "1,GPS,Warning messages from module 2";
    char text[200] = "--------------------------------------------------------------------------------------------------------------------------------------------------------";

    bool res = dlog_serialization(dlog, text);
    TEST_ASSERT_TRUE(res);
    TEST_ASSERT_EQUAL_STRING(exp_text, text);
}
