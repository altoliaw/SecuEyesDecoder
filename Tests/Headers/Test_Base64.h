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

void Test_Base64Encoders_and_Decoders_Single(void**);
void Test_Base64Encoders_and_Decoders_Word(void**);
void Test_Base64Encoders_and_Decoders_String(void**);