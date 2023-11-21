#pragma once
/** @file parseSqlStmt.h
 * The SecuEyes decoder (AP User decode, APU) with base 64 en(de)coding
 *
 * @author Nick, Liao
 * @date 2023/07/03
 *
 * @remarks (2023/11/21, Nick modified): The new file for main and unit tests
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define START_END_SYMBOL "#^" // The synmetric tag for the comment section
#define DELIMITER "," // The delimiter in the comment section

unsigned char* base64Encode(unsigned char*, unsigned int);
unsigned char* base64Decode(unsigned char*, unsigned int);
unsigned int getBase64Index(unsigned char);
int parseSqlStmt(unsigned char*, unsigned int, unsigned char**, unsigned char**, unsigned char*, unsigned char*, short);
