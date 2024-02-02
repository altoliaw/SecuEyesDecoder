#include "../Headers/Test_Encrypt.h"

void Test_Encrypt_DecryptProcess1(void** State) {

    char* dataString = "AA";
    unsigned int dataStringLength = (unsigned int)strlen((const char*)dataString);

    // Encoding process
    char* inferredEncodedDataString = (char*) APUDataEncrypt(dataString, dataStringLength);

    // Decoding process
    char* inferredDecodedDataString = (char*) APUDataDecrypt(inferredEncodedDataString, strlen(inferredEncodedDataString));
    assert_string_equal(inferredDecodedDataString, dataString);

    // Verifying if each character is equal to the one from the other decoded result
    for (int i = 0; i < dataStringLength; i++) {
        assert_int_equal((int)inferredDecodedDataString[i], (int)dataString[i]);
    }

    // Releasing the dynamic memory
    free(inferredEncodedDataString);
    free(inferredDecodedDataString);
}

/**
 * Testing encoding/decoding long string data by using Base64 encoded/decoded functions, namely (base64Encode/base64Decode functions)
 *
 * @param State void** None
 */
void Test_Encrypt_DecryptProcess2(void** State) {

    char* dataString = "Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.";
    unsigned int dataStringLength = (unsigned int)strlen((const char*)dataString);

    // Encoding process
    char* inferredEncodedDataString = (char*) APUDataEncrypt(dataString, dataStringLength);
    
    // Decoding process
    char* inferredDecodedDataString = (char*) APUDataDecrypt(inferredEncodedDataString, strlen(inferredEncodedDataString));
    assert_string_equal(inferredDecodedDataString, dataString);

    // Verifying if each character is equal to the one from the other decoded result
    for (int i = 0; i < dataStringLength; i++) {
        assert_int_equal((int)inferredDecodedDataString[i], (int)dataString[i]);
    }

    // Releasing the dynamic memory
    free(inferredEncodedDataString);
    free(inferredDecodedDataString);
}