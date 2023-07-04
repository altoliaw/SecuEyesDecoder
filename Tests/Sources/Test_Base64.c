#include "../Headers/Test_Base64.h"

/**
 * Test One Alpha Encode and Decode
 *
 * @param State
 */
void Test_Base64Encoders_and_Decoders_Single(void** State)
{

    /**
     * TestData 1
     * @details single byte data
     */
    char* dataSingle = "A";
    unsigned int dataSingleLength = 1;
    char* dataSingleEncoded = "QQ==";

    /** Base64 encode */
    /**
     * @brief Test encode 1
     * @author Ian.Chen
     * @description Test Single alphabet encoder
     */
    /** Encoding function, "A" to "QQ=="  */
    char* Source_dataSingleEncoded = base64Encode(dataSingle, dataSingleLength);

    /** Unit Test, expected result is  "QQ=="  */
    assert_string_equal(Source_dataSingleEncoded, dataSingleEncoded);

    /** Get Encoding data result length */
    unsigned int dataSingleEncodedLength = (unsigned int)strlen((char*)Source_dataSingleEncoded);

    /** Unit Test , char to ASCII , to Check each char */
    for (int i = 0; i < dataSingleEncodedLength; i++) {
        assert_int_equal((int)Source_dataSingleEncoded[i], (int)dataSingleEncoded[i]);
    }

    /** Decoding function "QQ==" to "A" */
    unsigned char* Source_dataSingleDecoded = base64Decode(Source_dataSingleEncoded, dataSingleEncodedLength);

    /** Unit Test, expected result is  "A" */
    assert_string_equal(Source_dataSingleDecoded, dataSingle);

    /** Unit Test, char to ASCII, to Check each char */
    for (int i = 0; i < dataSingleLength; i++) {
        assert_int_equal((int)Source_dataSingleDecoded[i], (int)dataSingle[i]);
    }

    /** Free pointers */
    free(Source_dataSingleEncoded);
    free(Source_dataSingleDecoded);
}

void Test_Base64Encoders_and_Decoders_Word(void** State)
{

    /**
     * TestData 2
     * @details Word data
     */
    char* dataWord = "Man";
    unsigned int dataWordLength = 3;
    char* dataWordEncoded = "TWFu";

    /**
     * Test encode 2
     * @author Ian.Chen
     * @description Test word encoder
     */

    /** Encoding function  "Man" to "TWFu"  */
    char* Source_dataWordEncoded = base64Encode(dataWord, dataWordLength);

    /** Unit Test, expected result is  "TWFu"  */
    assert_string_equal(Source_dataWordEncoded, dataWordEncoded);

    /** Get Encoding data result length */
    unsigned int dataWordEncodedLength = (unsigned int)strlen((char*)dataWordEncoded);

    /** Unit Test, char to ASCII, to Check each char */
    for (int i = 0; i < dataWordEncodedLength; i++) {
        assert_int_equal((int)Source_dataWordEncoded[i], (int)dataWordEncoded[i]);
    }

    /** Decoding function "TWFu" to "Man" */
    char* Source_dataWordDecoded = base64Decode(Source_dataWordEncoded, dataWordEncodedLength);

    /** Unit Test, expected result is  "Man" */
    assert_string_equal(Source_dataWordDecoded, dataWord);

    /** Unit Test, char to ASCII, to Check each char */
    for (int i = 0; i < dataWordLength; i++) {
        assert_int_equal((int)Source_dataWordDecoded[i], (int)dataWord[i]);
    }

    /** Free pointers */
    free(Source_dataWordEncoded);
    free(Source_dataWordDecoded);
}

void Test_Base64Encoders_and_Decoders_String(void** State)
{
    /**
     * TestData 3
     * @details String data
     */

    char* dataString = "Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.";
    unsigned int dataStringLength = (unsigned int)strlen((const char*)dataString);

    char* dataStringEncoded = "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";

    /**
     * Test encode 3
     * @author Ian.Chen
     * @description Test String encoder
     */

    /** Encoding function */
    char* Source_dataStringEncoded = base64Encode(dataString, dataStringLength);

    /** Unit Test   */
    assert_string_equal(Source_dataStringEncoded, dataStringEncoded);

    /** Get Encoding data result length */
    unsigned int dataStringEncodedLength = (unsigned int)strlen((char*)dataStringEncoded);

    /** Unit Test , char to ASCII , to Check each char */
    for (int i = 0; i < dataStringEncodedLength; i++) {
        assert_int_equal((int)Source_dataStringEncoded[i], (int)dataStringEncoded[i]);
    }

    /** Decoding function */
    char* Source_dataStringDecoded = base64Decode(Source_dataStringEncoded, dataStringEncodedLength);

    /** Unit Test */
    assert_string_equal(Source_dataStringDecoded, dataString);

    /** Unit Test , char to ASCII , to Check each char */
    for (int i = 0; i < dataStringLength; i++) {
        assert_int_equal((int)Source_dataStringDecoded[i], (int)dataString[i]);
    }

    /** Free pointers*/

    free(Source_dataStringEncoded);
    free(Source_dataStringDecoded);
}