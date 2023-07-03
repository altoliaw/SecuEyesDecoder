#include "../Headers/Test_Base64.h"


/**
 * @brief Test One Alpha Encode and Decode
 * 
 * @param State 
 * 
 */
void Test_Base64Encoders_and_Decoders_Single(void** State){

    /**
     * @brief TestData 1 
     * @details single byte data 
     * 
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


    /** Encoding function  "A" to "QQ=="  */
    char* Source_dataSingleEncoded = base64Encode(dataSingle, dataSingleLength); 

    /** Unit Test  , expect result is   */
    assert_string_equal(Source_dataSingleEncoded, dataSingleEncoded);

    unsigned int dataSingleEncodedLength =  (unsigned int)strlen((char *)Source_dataSingleEncoded);

    for(int i = 0; i < dataSingleEncodedLength; i++){
       assert_int_equal((int)Source_dataSingleEncoded[i] ,(int)dataSingleEncoded[i]);
    }

    


    unsigned char* Source_dataSingleDecoded = base64Decode(Source_dataSingleEncoded, dataSingleEncodedLength);

    assert_string_equal(Source_dataSingleDecoded , dataSingle) ;



    for(int i = 0; i < dataSingleLength; i++){
        assert_int_equal((int)Source_dataSingleDecoded[i] , (int)dataSingle[i]);
    }

    free(Source_dataSingleEncoded);
    free(Source_dataSingleDecoded);

}

void Test_Base64Encoders_and_Decoders_Word(void** State){

      /**
     * @brief TestData 2
     * @details Word data 
     * 
     * 
     */
    char* dataWord="Man";
    unsigned int dataWordLength = 3;

    char* dataWordEncoded = "TWFu";


  /**
     * @brief Test encode 2
     * @author Ian.Chen
     * @description Test word encoder  
     */

    char* Source_dataWordEncoded = base64Encode(dataWord, dataWordLength);

    assert_string_equal(Source_dataWordEncoded, dataWordEncoded);

    unsigned int dataWordEncodedLength =  (unsigned int)strlen((char *)dataWordEncoded);

    for(int i = 0; i < dataWordEncodedLength; i++){
       assert_int_equal((int)Source_dataWordEncoded[i] ,(int) dataWordEncoded[i]);
    }



 char* Source_dataWordDecoded = base64Decode(Source_dataWordEncoded, dataWordEncodedLength);

    assert_string_equal(Source_dataWordDecoded , dataWord) ;



    for(int i = 0; i < dataWordLength; i++){
        assert_int_equal((int)Source_dataWordDecoded[i] , (int)dataWord[i]);
    }

    free(Source_dataWordEncoded);
    free(Source_dataWordDecoded);

}

void Test_Base64Encoders_and_Decoders_String(void** State){

     /**
     * @brief TestData 3
     * @details String data 
     * 
     */

    char* dataString = "Man is distinguished, not only by his reason, but by this singular passion from other animals, which is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure.";
    unsigned int dataStringLength = (unsigned int)strlen((const char*)dataString);

    char* dataStringEncoded ="TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";

   /**
     * @brief Test encode 3
     * @author Ian.Chen
     * @description Test String encoder  
     */

     char* Source_dataStringEncoded = base64Encode(dataString, dataStringLength);

    assert_string_equal(Source_dataStringEncoded, dataStringEncoded);

    unsigned int dataStringEncodedLength =  (unsigned int)strlen((char *)dataStringEncoded);

    for(int i = 0; i < dataStringEncodedLength; i++){
       assert_int_equal((int)Source_dataStringEncoded[i] ,(int) dataStringEncoded[i]);
    }


     char* Source_dataStringDecoded = base64Decode(Source_dataStringEncoded, dataStringEncodedLength);

    assert_string_equal(Source_dataStringDecoded , dataString) ;



    for(int i = 0; i < dataStringLength; i++){
        assert_int_equal((int)Source_dataStringDecoded[i] , (int)dataString[i]);
    }

    free(Source_dataStringEncoded);
    free(Source_dataStringDecoded);


}