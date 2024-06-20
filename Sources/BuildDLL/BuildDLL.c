#include "../../Headers/BuildDLL/BuildDLL.h"

/**
 * Encrypted function for the DLL
 *
 * @param plainText [const unsigned char*] The plaintext input string
 * @param plainTextLength [unsigned int] The length of the plaintext input string
 * @param cipherText [unsigned char*] The ciphertext result string from the address of an array with a fixed size (static size)
 * @param cipherSpaceLength [unsigned int*] The length of the cipher space
 * @return [int] The length of the ciphertext result string
 */
unsigned int ___encryptSEDecoder(unsigned char* plainText, unsigned int plainTextLength, unsigned char* cipherText, unsigned int* cipherSpaceLength) {
    // Obtaining the cipher text with dynamic memory allocation
    unsigned char* returnedCipherText = APUDataEncrypt(plainText, plainTextLength, cipherSpaceLength);

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
unsigned int ___decryptSEDecoder(unsigned char* cipherText, unsigned int cipherTextLength, unsigned char* plainText, unsigned int* plainSpaceLength) {
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

    *plainSpaceLength = plainTextLength; 
    return plainTextLength;
}