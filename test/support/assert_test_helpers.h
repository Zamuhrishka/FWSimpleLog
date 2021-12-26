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
#include "unity.h"
#include "CException.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N S _________________________________________________
//_____ M A C R O S ___________________________________________________________
#define TEST_ASSERT_FAIL_ASSERT(_code_under_test)         \
{                                                         \
  CEXCEPTION_T e;                                         \
  Try {                                                   \
    _code_under_test;                                     \
    TEST_FAIL_MESSAGE("Code under test did not assert");  \
  } Catch(e) {}                                           \
}


#define TEST_ASSERT_PASS_ASSERT(_code_under_test)               \
{                                                               \
  CEXCEPTION_T e;                                               \
  Try {                                                         \
    _code_under_test;                                           \
  } Catch(e) {                                                  \
    TEST_FAIL_MESSAGE("Code under test failed an assertion");   \
  }                                                             \
}
//_____ V A R I A B L E S _____________________________________________________
//_____ P U B L I C  F U N C T I O N S_________________________________________

/* C++ detection */
#ifdef __cplusplus
}
#endif