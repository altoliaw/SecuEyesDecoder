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
void Test_ParseAbbreviationJsonComment_normalCaseProcess2(void**);
void Test_ParseAbbreviationJsonComment_normalCaseProcess3(void**);
void Test_ParseAbbreviationJsonComment_normalCaseProcess4(void**);
void Test_ParseAbbreviationJsonComment_normalCaseProcess5(void**);
void Test_ParseAbbreviationJsonComment_normalCaseProcess6(void**);
void Test_ParseAbbreviationJsonComment_encryptCaseProcess1(void**);
void Test_ParseAbbreviationJsonComment_encryptCaseProcess2(void**);
void Test_ParseAbbreviationJsonComment_specialCaseProcess1(void**);
void Test_ParseAbbreviationJsonComment_specialCaseProcess2(void**);