/** @file main.c
 * The SecuEyes decoder with base 64 en(de)coding
 *
 * @author Nick, Liao
 * @date 2023-07-03
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START_END_SYMBOL "#^"
#define DELIMITER ","

unsigned char* base64Encode(unsigned char*, unsigned int);
unsigned char* base64Decode(unsigned char*, unsigned int);
unsigned int getBase64Index(unsigned char);
int parseSqlStmt(unsigned char*, unsigned int, unsigned char**, unsigned char**, unsigned char*, unsigned char*);


/** Base 64 definition*/
static const unsigned char base64Alphabets[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

/**
 * Main process
 *
 * @param argc int The number of the arguments
 * @param argv char** The value of the arguments
 * @return
 */
//int main(int argc, char** argv)
//{
    // unsigned char data[] = "Hello, World!";
    // unsigned int dataLength = (unsigned int)strlen((const char*)data);
    ///** Base64 encode */
    // unsigned char* encodedData = NULL;
    // encodedData = base64Encode(data, dataLength);
    // if (encodedData != NULL) {
    //     printf("Encoded: %s\n", encodedData);
    //     /** Base64 decode*/
    //     unsigned int encodedLength = (unsigned int)strlen((char*)encodedData);
    //     unsigned char* decodedData = base64Decode(encodedData, encodedLength);
    //     if (decodedData != NULL) {
    //         printf("Decoded: %s\n", decodedData);
    //         free(decodedData);
    //     }
    //     free(encodedData);
    // }

    //unsigned char data[] = "admin@Cobra.com,127.0.0.1";
    //unsigned int dataLength = (unsigned int)strlen((const char*)data);
    /////** Base64 encode */
    //unsigned char* encodedData = NULL;
    //encodedData = base64Encode(data, dataLength);
    //fprintf(stderr, "Encoded: %s\n", encodedData);

    //free(encodedData);

    //unsigned char sqlStmtString[] = "/*#^YWRtaW5AQ29icmEuY29tLDEyNy4wLjAuMQ==^#*/ Select * from tb_select;";
    //unsigned int length = (unsigned int) strlen((char*) sqlStmtString);
    //unsigned char* userId = NULL;
    //unsigned char* ip = NULL;
//
    //int result = parseSqlStmt(
    //    sqlStmtString,
    //    length,
    //    &userId,
    //    &ip,
    //    (unsigned char*)START_END_SYMBOL,
    //    (unsigned char*)DELIMITER);
//
    //fprintf(stderr, "The userId is <%s>\n", userId);
    //fprintf(stderr, "The ip is <%s>\n", ip);
    //if(userId != NULL) {
    //    free(userId);
    //}
    //if(ip != NULL) {
    //    free(ip);
    //}
    //fprintf(stderr, "The result is <%d>", result);
    //return 0;
//}

/**
 * Base64 encode; users don't feel like knowing the length of encoded data in advance. In return,
 * users shall free encoded data memory manually. If the return value is NULL, please don't free the returned memory.
 *
 * @param plainText unsigned char* The plain text which users feel like encoding
 * @param plainTextLength unsigned int The length of the plain text which users feel like encoding
 * @return unsigned char* The encoded text; users shall free encoded data memory manually; if the return value is NULL,
 * please don't free the returned memory
 */
unsigned char* base64Encode(unsigned char* plainText, unsigned int plainTextLength)
{
    unsigned int encodedLength = 4 * ((plainTextLength + 2) / 3);
    unsigned char* encodedData = (unsigned char*)malloc(encodedLength + 1);
    if (encodedData == NULL) {
        return NULL;
    }

    /** Converting three bytes (decimal) to four base64 alphabets */
    for (unsigned int i = 0, j = 0; i < plainTextLength;) {
        /** Taking three alphabets for handling*/
        unsigned int octFirst = i < plainTextLength ? plainText[i++] : 0;
        unsigned int octSecond = i < plainTextLength ? plainText[i++] : 0;
        unsigned int octThird = i < plainTextLength ? plainText[i++] : 0;

        /** According to binary theorem, the first one shall shift 16 bits, the second one is 8 bits and the last one is occupied 0 bit;
         *  therefore, the three alphabets in binary can be displayed in the following.
         */
        unsigned int triple = (octFirst << 0x10) + (octSecond << 0x08) + octThird;

        /** Calculating the one alphabet's index of base 64 in order
         *  where `triple >> 3 * 6` implies triple will right shift 18 bits (i.e., only 6 bits remained);
         *  `0x3F` (hex) implies the significant bits `00111111` (binary); According to the theorem above,
         *  users can obtain the six bits to obtain an alphabet in base 64 encoding
         */
        encodedData[j++] = (unsigned char)base64Alphabets[(triple >> 3 * 6) & 0x3F];
        encodedData[j++] = (unsigned char)base64Alphabets[(triple >> 2 * 6) & 0x3F];
        encodedData[j++] = (unsigned char)base64Alphabets[(triple >> 1 * 6) & 0x3F];
        encodedData[j++] = (unsigned char)base64Alphabets[(triple >> 0 * 6) & 0x3F];
    }

    /** Padding with '=' characters if necessary */
    for (unsigned int i = 0; i < (3 - plainTextLength % 3) % 3; i++) {
        encodedData[encodedLength - 1 - i] = '=';
    }

    encodedData[encodedLength] = '\0';
    return encodedData;
}

/**
 * Base64 decode; users don't feel like knowing the length of decoded data (the plain text) in advance. In return,
 * users shall free decoded data memory manually. If the return value is NULL, please don't free the returned memory.
 *
 * @param encodedData unsigned char* The encoded text which users feel like decoding
 * @param encodedLength unsigned int The length of the plain text which users feel like encoding
 * @return unsigned char* The plain text; users shall free decoded data memory manually;
 * if the return value is NULL, please don't free the returned memory
 */
unsigned char* base64Decode(unsigned char* encodedData, unsigned int encodedLength)
{
    unsigned int decodedLength = encodedLength / 4 * 3;
    if (encodedData == NULL) {
        return NULL;
    }

    if (encodedLength % 4 != 0) {
        return NULL;
    }

    /** Checking the last two characters; according to the base 64 encoding,
     * the `=` notation will occur twice at most
     */
    if (encodedData[encodedLength - 1] == '=') {
        (decodedLength)--;
    }
    if (encodedData[encodedLength - 2] == '=') {
        (decodedLength)--;
    }

    unsigned char* decodedData = (unsigned char*)malloc(decodedLength + 1);
    if (decodedData == NULL) {
        return NULL;
    }

    for (unsigned int i = 0, j = 0; i < encodedLength;) {
        unsigned int sextet_a = encodedData[i] == '=' ? 0 & i++ : getBase64Index(encodedData[i++]);
        unsigned int sextet_b = encodedData[i] == '=' ? 0 & i++ : getBase64Index(encodedData[i++]);
        unsigned int sextet_c = encodedData[i] == '=' ? 0 & i++ : getBase64Index(encodedData[i++]);
        unsigned int sextet_d = encodedData[i] == '=' ? 0 & i++ : getBase64Index(encodedData[i++]);

        /** Like encoding, four alphabets are treated in each round in base64 encoding */
        unsigned int triple = (sextet_a << 3 * 6) + (sextet_b << 2 * 6) + (sextet_c << 1 * 6) + (sextet_d << 0 * 6);

        /** Like encoding, obtaining results by using significant bits */
        if (j < decodedLength) {
            decodedData[j++] = (triple >> 2 * 8) & 0xFF;
        }
        if (j < decodedLength) {
            decodedData[j++] = (triple >> 1 * 8) & 0xFF;
        }
        if (j < decodedLength) {
            decodedData[j++] = (triple >> 0 * 8) & 0xFF;
        }
    }

    decodedData[decodedLength] = '\0';
    return decodedData;
}

/**
 *  To obtain the character from the given alphabet in base 64 encoding
 *
 * @param alphabet unsigned char The alphabet in base 64 encoding
 * @return unsigned int The decimal value of the ASCII code
 */
unsigned int getBase64Index(unsigned char alphabet)
{
    int returnedValue = 0;

    if (alphabet >= (unsigned char)'A' && alphabet <= (unsigned char)'Z') {
        returnedValue = alphabet - (unsigned char)'A';
    } else if (alphabet >= (unsigned char)'a' && alphabet <= (unsigned char)'z') {
        returnedValue = alphabet - (unsigned char)'a' + 26;
    } else if (alphabet >= (unsigned char)'0' && alphabet <= (unsigned char)'9') {
        returnedValue = alphabet - (unsigned char)'0' + 52;
    } else if (alphabet == (unsigned char)'+') {
        returnedValue = 62;
    } else if (alphabet == (unsigned char)'/') {
        returnedValue = 63;
    }

    return returnedValue;
}

/**
 * Obtaining the `first` comment from the SQL statements; to use the function, there exist 2 tips which users shall follow.
 * First of all, users shall pass unsigned char pointers, `userId` and `ip` and those two pointers shall be initialized in NULL values as the arguments.
 * Second, after using the function, users shall free the memory `userId` and `ip` manually because the dynamic memory allocation affects in this function.
 *
 * @param sqlStmt unsigned char* SQL statement
 * @param sqlStmtLen unsigned int The length of the SQL statement
 * @param userId unsigned char** The user id information; users shall free the memory manually
 * @param ip unsigned char** The user ip; users shall free the memory manually
 * @param startEndSymbol unsigned char* The starting symbol of the encoded text
 * @param delimiter unsigned char* The delimiter for obtaining the values of userId and ip
 * @return int The error code; 0 means success, and -1 implies failure
 */
int parseSqlStmt(
    unsigned char* sqlStmt,
    unsigned int sqlStmtLen,
    unsigned char** userId,
    unsigned char** ip,
    unsigned char* startEndSymbol,
    unsigned char* delimiter)
{
    unsigned int start = 0;
    unsigned int end = 0;
    /** The 0 value shows the process shall search the starting notation `0x2F0x2A`; otherwise shall searching `0x2A0x2F` */
    unsigned short startFlag = 0;
    for (; end < sqlStmtLen;) {
        /** `if` section implies that users shall find the starting comment symbol `/`;
         *  `else` section implies that users shall find the end `startEndSymbol` symbol.
         */
        if (startFlag == 0) {
            if (sqlStmt[end] != (unsigned char)'/') {
                start = end = (end + 1);
                continue;
            }
            /** The `4` implies that the location of the encoded text shall be safe for accessing. */
            if ((end + 1 + (int)strlen((char*)startEndSymbol) + 1) < sqlStmtLen &&
                sqlStmt[end + 1] == (unsigned char)'*' &&
                sqlStmt[end + 2] == startEndSymbol[0] &&
                sqlStmt[end + 3] == startEndSymbol[1]) {
                start = end = (end + 4);
                startFlag++;
            } else {
                end++;
            }
        } else {
            if (sqlStmt[end] != startEndSymbol[1]) {
                end++;
                continue;
            }
            if (end + 1 + (int)strlen((char*)startEndSymbol) < sqlStmtLen &&
                    sqlStmt[end + 1] == startEndSymbol[0] &&
                    sqlStmt[end + 2] == '*' &&
                    sqlStmt[end + 3] == '/') {
                /** Hitting the end of the startEndSymbol; therefore, the end position is back to the previous character*/
                end = end - 1 ;
                break;
            } else {
                end++;
            }
        }
    }

    /** Allocating the size, the number two consists of two part, one part is for length and the other is for '\0' */
    unsigned char* encodedText = NULL;
    encodedText = (unsigned char*)malloc(sizeof(unsigned char) * (end - start + 2));
    if (encodedText == NULL) {
        return -1;
    }

    memcpy(encodedText, sqlStmt + start, (end - start + 1));
    encodedText[(end - start + 1)] = '\0';
    unsigned char* plainText = NULL;
    plainText = base64Decode (encodedText, (end - start + 1));
    if(plainText == NULL) {
        return -1;
    }

    /** Splitting the string into two tokens */
    unsigned int startPivot =0;
    unsigned int endPivot =0;
    for(short flag = 0; endPivot < (unsigned int)strlen((char*)plainText);) {
        if(plainText[endPivot]!= *delimiter && flag == 0) {
            endPivot++;
            continue;
        }
        if (endPivot < (unsigned int)strlen((char*)plainText) -1 && flag == 1) {
            endPivot++;
            continue;
        }

        if(flag == 0) {
            if(endPivot - startPivot != 0) {
                *userId = (unsigned char*)malloc(sizeof(unsigned char) * (endPivot - startPivot) + sizeof(unsigned char) );
                memcpy(*userId, plainText + startPivot, (endPivot - startPivot));
                (*userId)[(endPivot - startPivot)] = '\0';
            }
            startPivot = endPivot + 1;
            endPivot ++;
            flag ++;
        } else {
            if(endPivot - startPivot != 0) {
                *ip = (unsigned char*)malloc(sizeof(unsigned char) * (endPivot - startPivot + 1) + sizeof(unsigned char) );
                memcpy(*ip, plainText + startPivot, (endPivot - startPivot + 1));
                (*ip)[(endPivot - startPivot + 1)] = '\0';
            }
            endPivot++;
        }
    }

    free(encodedText);
    free(plainText);
    return 0;
}