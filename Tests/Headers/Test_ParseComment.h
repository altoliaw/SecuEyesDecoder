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
void Test_ParseComment_normalCaseProcess2(void**);
void Test_ParseComment_normalCaseProcess3(void**);
void Test_ParseComment_normalCaseProcess4(void**);
void Test_ParseComment_normalCaseProcess5(void**);
void Test_ParseComment_normalCaseProcess6(void**);
void Test_ParseComment_normalCaseProcess7(void**);
void Test_ParseComment_normalCaseProcess8(void**);
void Test_ParseComment_normalCaseProcess9(void**);
void Test_ParseComment_normalCaseProcess10(void**);
void Test_ParseComment_normalCaseProcess11(void**);
void Test_ParseComment_normalCaseProcess12(void**);
void Test_ParseComment_normalCaseProcess13(void**);
void Test_ParseComment_normalCaseProcess14(void**);
void Test_ParseComment_userCaseProcess1(void**);
void Test_ParseComment_userCaseProcess2(void**);
void Test_ParseComment_encodedCaseProcess(void**);
void Test_ParseComment_encodedCaseProcess2(void**);