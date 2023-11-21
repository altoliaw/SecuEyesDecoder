#include "../Headers/Test_Base64.h"

/**
 * Testing encoding/decoding an alphabet by using Base64 encoded/decoded functions, namely (base64Encode/base64Decode functions)
 *
 * @param State void** None
 */
void Test_Base64_encodedDecodedProcess(void** State) {
    char* data = "A";
    unsigned int dataLength = strlen(data);
    char* dataEncoded = "QQ==";

    // Encoding function; the alphabet, "A", will be encoded to the string, "QQ=="
    char* inferredEncodedData = (char*)base64Encode((unsigned char*)data, dataLength);
    assert_string_equal(inferredEncodedData, dataEncoded);

    // Obtaining the length of the encoding data
    unsigned int inferredEncodedDataLength = (unsigned int)strlen(inferredEncodedData);

    // Checking if the ASCII value according to each character
    for (int i = 0; i < inferredEncodedDataLength; i++) {
        assert_int_equal((int)inferredEncodedData[i], (int)dataEncoded[i]);
    }

    // Decoding the string
    char* inferredDecodedData = base64Decode((unsigned char*)inferredEncodedData, inferredEncodedDataLength);
    assert_string_equal(inferredDecodedData, data);

    // Checking if the length of the decoded string is equal to the one of the original characters
    assert_int_equal((int)strlen(inferredDecodedData), (int)dataLength);

    // Checking if the ASCII value according to each character
    for (int i = 0; i < dataLength; i++) {
        assert_int_equal((int)inferredDecodedData[i], (int)data[i]);
    }

    // Releasing the dynamic memory
    free(inferredEncodedData);
    free(inferredDecodedData);
}

/**
 * Testing encoding/decoding multialphabets by using Base64 encoded/decoded functions, namely (base64Encode/base64Decode functions)
 *
 * @param State void** None
 */
void Test_Base64_encodedDecodedProcess2(void** State) {
    char* data = "Man";
    unsigned int dataLength = strlen(data);
    char* encodedData = "TWFu";

    // Encoding process
    char* inferredEncodedData = (char*) base64Encode(data, dataLength);
    assert_string_equal(inferredEncodedData, encodedData);

    // Obtaining encoded string
    unsigned int dataWordEncodedLength = (unsigned int)strlen((char*)encodedData);

    // Verifying each character
    for (int i = 0; i < dataWordEncodedLength; i++) {
        assert_int_equal((int)inferredEncodedData[i], (int)encodedData[i]);
    }

    // Decoding function "TWFu" to "Man"
    char* inferredDecodedData = (char*) base64Decode(inferredEncodedData, dataWordEncodedLength);

    // Verifying the length of the decoded data
    assert_int_equal((int)strlen(inferredDecodedData), (int)dataLength);

    // Verifying the string
    assert_string_equal(inferredDecodedData, data);

    // Verifying with each character
    for (int i = 0; i < dataLength; i++) {
        assert_int_equal((int)inferredDecodedData[i], (int)data[i]);
    }

    // Releasing the dynamic memory
    free(inferredEncodedData);
    free(inferredDecodedData);
}

/**
 * Testing encoding/decoding long string data by using Base64 encoded/decoded functions, namely (base64Encode/base64Decode functions)
 *
 * @param State void** None
 */
void Test_Base64_encodedDecodedProcess3(void** State) {

    char* dataString = "Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.";
    unsigned int dataStringLength = (unsigned int)strlen((const char*)dataString);
    char* encodedDataString = "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";

    // Encoding process
    char* inferredEncodedDataString = (char*) base64Encode(dataString, dataStringLength);
    assert_string_equal(inferredEncodedDataString, encodedDataString);

    // Obtaining encoding the length of the data result
    unsigned int encodedDataStringLength = (unsigned int)strlen((char*)encodedDataString);

    // Verifying if each character is equal to the one from the other encoded result
    for (int i = 0; i < encodedDataStringLength; i++) {
        assert_int_equal((int)inferredEncodedDataString[i], (int)encodedDataString[i]);
    }

    // Decoding process
    char* inferredDecodedDataString = (char*) base64Decode(inferredEncodedDataString, encodedDataStringLength);
    assert_string_equal(inferredDecodedDataString, dataString);

    // Verifying if each character is equal to the one from the other decoded result
    for (int i = 0; i < dataStringLength; i++) {
        assert_int_equal((int)inferredDecodedDataString[i], (int)dataString[i]);
    }

    // Releasing the dynamic memory
    free(inferredEncodedDataString);
    free(inferredDecodedDataString);
}