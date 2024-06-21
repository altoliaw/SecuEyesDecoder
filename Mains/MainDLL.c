/** @file MainDLL.c
 * The starting entry for exporting library
 *
 * @author Nick, Liao
 * @date 2024/05/20
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/BuildDLL/BuildDLL.h"

int main() {
    // Encrypting the string
    char* demoUserId = "f12345@yaoo.com.tw";
    char* demoIp = "127.0.0.1";
    char* demoDbUser = "localhost";
    unsigned char plainText[2000];

    int length = sprintf((char*)plainText, "{\"userId\":\"%s\", \"ip\":\"%s\", \"dbUser\":\"%s\"}", demoUserId, demoIp, demoDbUser);
    fprintf(stderr, "%s \t %d\n", plainText, (int)strlen((char*)plainText));

    unsigned char cipherText[2000];
    unsigned int cipherTextLen = ___encryptSEDecoder((unsigned char*)plainText, (unsigned int)length, cipherText);
    fprintf(stderr, "%s \t %d\n", cipherText, cipherTextLen);

    // Decrypting the string
    unsigned char plainTextPrediction[2000];
    unsigned int plainTextLen = ___decryptSEDecoder((unsigned char*)cipherText, cipherTextLen, plainTextPrediction);
    fprintf(stderr, "%s \t %d\n", plainTextPrediction, plainTextLen);

    return 0;
}