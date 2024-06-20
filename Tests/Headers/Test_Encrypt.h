#pragma once
/** @file Test_Base64.h
 * Unit test for Base64 encoding and decoding
 *
 * @author Nick Liao and Ian, Chen
 * @date 2023/07/03
 */
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include "../../Headers/ParseSqlStmt.h"

void Test_Encrypt_DecryptProcess1(void**);
void Test_Encrypt_DecryptProcess2(void**);