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

unsigned int ___encryptSEDecoder(unsigned char*, unsigned int, unsigned char**);
unsigned int ___decryptSEDecoder(unsigned char*, unsigned int, unsigned char**);
void ___removeSEMemory(unsigned char*);

// Libraries exported in different types of platforms
#if defined(_WIN32) || defined(_WIN64)
#define EXPORT __declspec(dllexport)

EXPORT unsigned int ___encryptSEDecoder(unsigned char*, unsigned int, unsigned char**);
EXPORT unsigned int ___decryptSEDecoder(unsigned char*, unsigned int, unsigned char**);
EXPORT void ___removeSEMemory(unsigned char*);

#else

__attribute__((visibility("default"))) unsigned int ___encryptSEDecoder(const unsigned char*, unsigned int, unsigned char**);
__attribute__((visibility("default"))) unsigned int ___decryptSEDecoder(const unsigned char*, unsigned int, unsigned char**);
__attribute__((visibility("default"))) void ___removeSEMemory(unsigned char*);

#endif

int main() {
    char* demoUserId = "f12345@yaoo.com.tw";
    char* demoIp = "127.0.0.1";
    char* demoDbUser = "localhost";
	unsigned char plainText[2000];

    int length = sprintf((char*)plainText, "{\"userId\":\"%s\", \"ip\":\"%s\", \"dbUser\":\"%s\"}", demoUserId, demoIp, demoDbUser);
    printf("%s\n", plainText);

    unsigned char* cipherText = NULL;
    
    unsigned int cipherTextLen = ___encryptSEDecoder((unsigned char*)plainText, (unsigned int) length, &cipherText);
    printf("%s \t %d\n", cipherText, (int)cipherTextLen);


    if(cipherText != NULL) {
        free(cipherText);
    }

	return 0;
}


/**
 * Encrypted function for the DLL
 *
 * @param plainText [const unsigned char*] The plaintext input string
 * @param plainTextLength [unsigned int] The length of the plaintext input string
 * @param cipherText [unsigned char**] The ciphertext result string
 * @return [int] The length of the ciphertext result string
 */
unsigned int ___encryptSEDecoder(unsigned char* plainText, unsigned int plainTextLength, unsigned char** cipherText) {
    *cipherText = APUDataEncrypt(plainText, plainTextLength);
    printf("%s\n", *cipherText);
    int cipherLength = 0;
    // Returning the length of the ciphertext
    if (*cipherText != NULL) {
        cipherLength = strlen((const char*)*cipherText);
    }
    return cipherLength;
}

/**
 * Decrypted function for the DLL
 *
 * @param cipherText [unsigned char]
 * @param cipherTextLength [unsigned int]
 * @param plainText [unsigned char**]
 * @return [unsigned int]
 */
unsigned int ___decryptSEDecoder(unsigned char* cipherText, unsigned int cipherTextLength, unsigned char** plainText) {
    *plainText = APUDataDecrypt(cipherText, cipherTextLength);

    int plainTextLength = 0;
    if (*plainText != NULL) {
        plainTextLength = strlen((const char*)*plainText);
    }
    return plainTextLength;
}

/**
 * Memory releasing [unsigned char*] The memory allocated in the heap
 *
 * @param startingAddress [unsigned char*]
 */
void ___removeSEMemory(unsigned char* startingAddress) {
    free(startingAddress);
}
