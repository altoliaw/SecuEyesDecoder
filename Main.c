/** @file Main.c
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

#include "./Headers/ParseSqlStmt.h"

/**
 * Main process
 *
 * @param argc int The number of the arguments
 * @param argv char** The value of the arguments
 * @return
 */
int main(int argc, char** argv) {
    unsigned char data[] = "Hello, World!";
    unsigned int dataLength = (unsigned int)strlen((const char*)data);
    /** Base64 encode */
    unsigned char* encodedData = NULL;
    encodedData = base64Encode(data, dataLength);
    if (encodedData != NULL) {
        printf("Encoded: %s\n", encodedData);
        /** Base64 decode*/
        unsigned int encodedLength = (unsigned int)strlen((char*)encodedData);
        unsigned char* decodedData = base64Decode(encodedData, encodedLength);
        if (decodedData != NULL) {
            printf("Decoded: %s\n", decodedData);
            free(decodedData);
        }
        free(encodedData);
    }

    //     unsigned char data[] = "admin@Cobra.com,127.0.0.1";
    //     unsigned int dataLength = (unsigned int)strlen((const char*)data);

    //    /** Base64 encode */
    //     unsigned char* encodedData = NULL;
    //     encodedData = base64Encode(data, dataLength);
    //     fprintf(stderr, "Encoded: %s\n", encodedData);
    //     free(encodedData);

    //    unsigned char sqlStmtString[] = "/*#^YWRtaW5AQ29icmEuY29tLDEyNy4wLjAuMQ==^#*/Select * from tb_select;";
    //    unsigned char sqlStmtString[] = "/*#^admin@Cobra.com,127.0.0.1^#*/Select * from tb_select;";
    //    unsigned int length = (unsigned int)strlen((char*)sqlStmtString);
    //    unsigned char* userId = NULL;
    //    unsigned char* ip = NULL;

    //    int result = parseSqlStmt(
    //        sqlStmtString,
    //        length,
    //        &userId,
    //        &ip,
    //        (unsigned char*)START_END_SYMBOL,
    //        (unsigned char*)DELIMITER,
    //        (short)1);

    //    fprintf(stderr, "The userId is <%s>\n", userId);
    //    fprintf(stderr, "The ip is <%s>\n", ip);
    //    if (userId != NULL) {
    //        free(userId);
    //    }
    //    if (ip != NULL) {
    //        free(ip);
    //    }
    //    fprintf(stderr, "The result is <%d>\n", result);
    //    fprintf(stderr, "The sqlStmt is <%s>\n", sqlStmtString);
    return 0;
}