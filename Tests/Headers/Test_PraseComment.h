
#pragma once

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include "Base64.h"


#define START_END_SYMBOL "#^"
#define DELIMITER ","

/**
 * @brief Test Encoded Message Normal
 * 
 * @param state 
 */
void Test_parseSqlStmt_Normal(void **state);


/**
 * @brief Test Encoded Message in of middle of string
 * 
 * @param state 
 */
void Test_parseSqlStmt_Target_At_Mid(void **state);


/**
 * @brief Test Has Multi Encoded Message 
 * 
 * @param state 
 */
void Test_parseSqlStmt_Multi_Target(void **state);