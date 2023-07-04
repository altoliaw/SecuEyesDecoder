#pragma once
/** @file main.c
 * The SecuEyes decoder with base 64 en(de)coding
 *
 * @author Nick, Liao
 * @date 2023-07-03
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char* base64Encode(unsigned char*, unsigned int);
unsigned char* base64Decode(unsigned char*, unsigned int);
unsigned int getBase64Index(unsigned char);

int parseSqlStmt(
    unsigned char* sqlStmt,
    unsigned int sqlStmtLen,
    unsigned char** userId,
    unsigned char** ip,
    unsigned char* startEndSymbol,
    unsigned char* delimiter);
