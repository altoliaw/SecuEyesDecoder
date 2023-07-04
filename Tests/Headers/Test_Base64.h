#pragma once
/** @file Test_Base64.h
 * A test for Main.c
 * @author Ian.Chen
 * @brief Unit test for Base64.
 * @version 1.0
 * @date 2023-07-03
 */
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include "Base64.h"

void Test_Base64Encoders_and_Decoders_Single(void** State);
void Test_Base64Encoders_and_Decoders_Word(void** State);
void Test_Base64Encoders_and_Decoders_String(void** State);