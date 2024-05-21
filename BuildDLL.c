/** @file BuildDll.c
 * The starting entry for exporting library
 *
 * @author Nick, Liao
 * @date 2024/05/20
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./Headers/ParseSqlStmt.h"

unsigned int ___encryptSEDecoder(unsigned char*, unsigned int, unsigned char*);
unsigned int ___decryptSEDecoder(unsigned char*, unsigned int, unsigned char*);

// Libraries exported in different types of platforms
#if defined(_WIN32) || defined(_WIN64)
#define EXPORT __declspec(dllexport)

EXPORT unsigned int ___encryptSEDecoder(unsigned char*, unsigned int, unsigned char*);
EXPORT unsigned int ___decryptSEDecoder(unsigned char*, unsigned int, unsigned char*);

#else

__attribute__((visibility("default"))) unsigned int ___encryptSEDecoder(unsigned char*, unsigned int, unsigned char*);
__attribute__((visibility("default"))) unsigned int ___decryptSEDecoder(unsigned char*, unsigned int, unsigned char*);

#endif

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

/**
 * Encrypted function for the DLL
 *
 * @param plainText [const unsigned char*] The plaintext input string
 * @param plainTextLength [unsigned int] The length of the plaintext input string
 * @param cipherText [unsigned char*] The ciphertext result string from the address of an array with a fixed size (static size)
 * @return [int] The length of the ciphertext result string
 */
unsigned int ___encryptSEDecoder(unsigned char* plainText, unsigned int plainTextLength, unsigned char* cipherText) {
    // Obtaining the cipher text with dynamic memory allocation
    unsigned char* returnedCipherText = APUDataEncrypt(plainText, plainTextLength);

    int cipherLength = 0;
    if (returnedCipherText != NULL) {
        cipherLength = (int)strlen((const char*)returnedCipherText);
        // Returning the length of the ciphertext
        if (cipherLength > 0) {
            memcpy(cipherText, returnedCipherText, cipherLength);
        }
        cipherText[cipherLength] = '\0';
        free(returnedCipherText);
    }

    return cipherLength;
}

/**
 * Decrypted function for the DLL
 *
 * @param cipherText [unsigned char] The string of the cipher text
 * @param cipherTextLength [unsigned int] The length of the cipher text
 * @param plainText [unsigned char*] The plain text result string from the address of an array with a fixed size (static size)
 * @return [unsigned int] The length of the plain text result string
 */
unsigned int ___decryptSEDecoder(unsigned char* cipherText, unsigned int cipherTextLength, unsigned char* plainText) {
    // Obtaining the plain text from the cipher text
    unsigned char* returnedPlainText = APUDataDecrypt(cipherText, cipherTextLength);
    int plainTextLength = 0;
    if (returnedPlainText != NULL) {
        plainTextLength = (int)strlen((char*)returnedPlainText);
        if (plainTextLength > 0) {
            memcpy(plainText, returnedPlainText, plainTextLength);
        }
        plainText[plainTextLength] = '\0';
        free(returnedPlainText);
    }

    return plainTextLength;
}