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
#include <string.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include "../../Headers/ParseSqlStmt.h"

void Test_ParseJsonComment_normalCaseProcess1(void**);
void Test_ParseJsonComment_normalCaseProcess2(void**);
void Test_ParseJsonComment_normalCaseProcess3(void**);
void Test_ParseJsonComment_normalCaseProcess4(void**);
void Test_ParseJsonComment_normalCaseProcess5(void**);
void Test_ParseJsonComment_normalCaseProcess6(void**);
void Test_ParseJsonComment_normalCaseProcess7(void**);
void Test_ParseJsonComment_normalCaseProcess8(void**);
void Test_ParseJsonComment_normalCaseProcess9(void**);
void Test_ParseJsonComment_normalCaseProcess10(void**);
void Test_ParseJsonComment_normalCaseProcess11(void**);
void Test_ParseJsonComment_customCaseProcess1(void**);
void Test_ParseJsonComment_customCaseProcess2(void**);
void Test_ParseJsonComment_encryptCaseProcess1(void**);
void Test_ParseJsonComment_encryptCaseProcess2(void**);