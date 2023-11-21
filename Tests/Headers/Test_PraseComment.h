#pragma once
/** @file Test_PraseComment.h
 *
 * @author Nick, Liao and Ian Chen
 * @date 2023-11-21
 */
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include "../../Headers/ParseSqlStmt.h"

void Test_parseSqlStmt_Normal(void**);
void Test_parseSqlStmt_Normal_FirstNULL(void**);
void Test_parseSqlStmt_Normal_LastNULL(void**);
void Test_parseSqlStmt_Normal_MultiDelimiter(void**);
void Test_parseSqlStmt_Target_At_Mid_TwoDelimiter(void**);
void Test_parseSqlStmt_Target_At_Mid(void**);
void Test_parseSqlStmt_Multi_Target(void**);