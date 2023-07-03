
/**
 * @file Main.c
 * @author Ian.Chen
 * @brief Unit test for the library.
 * @version 0.1
 * @date 2023-07-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */




#include "./Headers/Test_Base64.h"


const struct CMUnitTest tests[] = {
    cmocka_unit_test(Test_Base64Encoders_and_Decoders_Single),
    cmocka_unit_test(Test_Base64Encoders_and_Decoders_Word),
    cmocka_unit_test(Test_Base64Encoders_and_Decoders_String),
};


int main(){

    return cmocka_run_group_tests(tests, NULL, NULL);

}