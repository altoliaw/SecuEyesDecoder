#pragma once
/** @file Test_PraseComment.h
 * Verifying if the function, pareSqlStmt, can be parsed acccurately; the testing includes various situations in the following functions
 *
 * @author Nick, Liao and Ian, Chen
 * @date 2023/11/21
 *
 * @remark (2023/11/21, modified by Nick) The decoded string are modified. In the past, the decoded string contains 2 types of data and 1 delimiter character;
 * After revision, the decoded string contains 3 types of data and 2 delimiter characters
 */
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include "../../Headers/ParseSqlStmt.h"

void Test_ParseComment_normalCaseProcess(void**);
