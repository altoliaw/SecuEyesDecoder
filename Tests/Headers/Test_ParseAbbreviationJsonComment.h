#pragma once
/** @file Test_PraseComment.h
 * Verifying if the function, pareSqlStmt, can be parsed accurately; the testing includes various situations in the following functions
 *
 * @author Nick, Liao
 * @date 2024/08/22
 *
 */
#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include "../../Headers/ParseSqlStmt.h"

void Test_ParseAbbreviationJsonComment_normalCaseProcess1(void**);
