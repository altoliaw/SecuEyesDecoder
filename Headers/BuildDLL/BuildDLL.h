#pragma once
/** @file BuildDll.h
 * The starting entry for exporting library
 *
 * @author Nick, Liao
 * @date 2024/05/20
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../Headers/ParseSqlStmt.h"

unsigned int ___encryptSEDecoder(unsigned char*, unsigned int, unsigned char*, unsigned int*);
unsigned int ___decryptSEDecoder(unsigned char*, unsigned int, unsigned char*, unsigned int*);

// Libraries exported in different types of platforms
#if defined(_WIN32) || defined(_WIN64)
#define EXPORT __declspec(dllexport)

EXPORT unsigned int ___encryptSEDecoder(unsigned char*, unsigned int, unsigned char*, unsigned int*);
EXPORT unsigned int ___decryptSEDecoder(unsigned char*, unsigned int, unsigned char*, unsigned int*);

#else

__attribute__((visibility("default"))) unsigned int ___encryptSEDecoder(unsigned char*, unsigned int, unsigned char*, unsigned int*);
__attribute__((visibility("default"))) unsigned int ___decryptSEDecoder(unsigned char*, unsigned int, unsigned char*, unsigned int*);

#endif