#pragma once

/**
 * @file Test_Base64.h
 * @author Ian.Chen
 * @brief Unit test for Base64.
 * @version 0.1
 * @date 2023-07-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "Base64.h"
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>


void Test_Base64Encoders_and_Decoders_Single(void** State);

void Test_Base64Encoders_and_Decoders_Word(void** State);

void Test_Base64Encoders_and_Decoders_String(void** State);