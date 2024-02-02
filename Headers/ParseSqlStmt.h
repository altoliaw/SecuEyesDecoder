#pragma once
/** @file parseSqlStmt.h
 * The SecuEyes decoder (AP User decode, APU) with base 64 en(de)coding
 *
 * @author Nick, Liao
 * @date 2023/07/03
 *
 * @remark (2023/11/21, modified by Nick) The decoded string are modified. In the past, the decoded string contains 2 types of data and 1 delimiter character;
 * After revision, the decoded string contains 3 types of data and 2 delimiter characters; as a result, the function parseSqlStmt shall be modified
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>

#define START_END_SYMBOL "#^" // The symmetric tag for the comment section, the size shall be equal to two
#define DELIMITER "," // The delimiter in the comment section
#define ENCRYPTION_KEY 0x87655F6A // The encryption key (32 bits) which the user defines

unsigned char* APUDataEncrypt(const unsigned char*, unsigned int);
unsigned char* APUDataDecrypt(const unsigned char*, unsigned int);
unsigned char* base64Encode(unsigned char*, unsigned int);
unsigned char* base64Decode(unsigned char*, unsigned int);
unsigned int getBase64Index(unsigned char);
int parseSqlStmt(unsigned char*, unsigned int, unsigned char**, unsigned char**, unsigned char**, unsigned char*, unsigned char*, short, short);
int parseEncryptedSqlStmt(unsigned char*, unsigned int, unsigned char**, unsigned char**, unsigned char**, unsigned char*, unsigned char*, short, short);