#include "../Headers/Test_Base64.h"

/**
 * Testing encryption/decryption from dll
 *
 * @param State void** None
 */
void Test_Base64_dllVerificationProcess1(void** State) {
    // Encrypting the string
    unsigned char plainText[2000];

    int length = sprintf((char*)plainText, "A:admin,B:127.0.0.1,C:myadmin@192.168.125.196");
	// fprintf(stderr, "%s \t %d\n", plainText, length);
    unsigned char cipherText[2000];
    unsigned int cipherTextLen = ___encryptSEDecoder((unsigned char*)plainText, (unsigned int)length, cipherText);
	// fprintf(stderr, "%s \t %d\n", cipherText, cipherTextLen);

    // Decrypting the string
    unsigned char plainTextPrediction[2000];
    unsigned int plainTextLen = ___decryptSEDecoder((unsigned char*)cipherText, cipherTextLen, plainTextPrediction);
	// fprintf(stderr, "%s \t %d\n", plainTextPrediction, plainTextLen);

	assert_string_equal(plainText, plainTextPrediction);
	assert_int_equal((int)strlen((char*)plainText), plainTextLen);
}


/**
 * Testing encryption/decryption from dll
 *
 * @param State void** None
 */
void Test_Base64_dllVerificationProcess2(void** State) {
    // Encrypting the string
    char* demoUserId = "f12345@yaoo.com.tw";
    char* demoIp = "127.0.0.1";
    char* demoDbUser = "localhost";
    unsigned char plainText[2000];

    int length = sprintf((char*)plainText, "{\"userId\":\"%s\", \"ip\":\"%s\", \"dbUser\":\"%s\"}", demoUserId, demoIp, demoDbUser);
	// fprintf(stderr, "%s \t %d\n", plainText, length);
    unsigned char cipherText[2000];
    unsigned int cipherTextLen = ___encryptSEDecoder((unsigned char*)plainText, (unsigned int)length, cipherText);
	// fprintf(stderr, "%s \t %d\n", cipherText, cipherTextLen);

    // Decrypting the string
    unsigned char plainTextPrediction[2000];
    unsigned int plainTextLen = ___decryptSEDecoder((unsigned char*)cipherText, cipherTextLen, plainTextPrediction);
	// fprintf(stderr, "%s \t %d\n", plainTextPrediction, plainTextLen);

	assert_string_equal(plainText, plainTextPrediction);
	assert_int_equal((int)strlen((char*)plainText), plainTextLen);
}