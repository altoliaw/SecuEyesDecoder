#pragma once

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include "../../Headers/ParseSqlStmt.h"


#define START_END_SYMBOL "#^"
#define DELIMITER ","

/**
 * @brief Test Encoded Message Normal
 *
 * @param state
 */
void Test_parseSqlStmt_Normal(void **state);


void Test_parseSqlStmt_Normal_FirstNULL(void **state);
void Test_parseSqlStmt_Normal_LastNULL(void **state);

/**
 * @brief Testing SQL statement has multi delimiter, e.g. unsigned char *sqlStmt = "112333@gmail.com,,,,200.221.99.3";
 *
 * @param state
 */
void Test_parseSqlStmt_Normal_MultiDelimiter(void **state);

/**
 * @brief esting SQL statement has multi delimiter, e.g. unsigned char *sqlStmt = "112333@gmail.com,,200.221.99.3,";
 *
 * @param state
 */
void Test_parseSqlStmt_Target_At_Mid_TwoDelimiter(void **state);

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