
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
#include "./Headers/Test_PraseComment.h"

const struct CMUnitTest tests[] = {
    cmocka_unit_test(Test_Base64Encoders_and_Decoders_Single),
    cmocka_unit_test(Test_Base64Encoders_and_Decoders_Word),
    cmocka_unit_test(Test_Base64Encoders_and_Decoders_String),

    cmocka_unit_test(Test_parseSqlStmt_Normal),
    cmocka_unit_test(Test_parseSqlStmt_Normal_FirstNULL),
    cmocka_unit_test(Test_parseSqlStmt_Normal_LastNULL),
    cmocka_unit_test(Test_parseSqlStmt_Normal_MultiDelimiter),


    cmocka_unit_test(Test_parseSqlStmt_Target_At_Mid_TwoDelimiter),
    cmocka_unit_test(Test_parseSqlStmt_Target_At_Mid),

    cmocka_unit_test(Test_parseSqlStmt_Multi_Target),
    

    

};

int main(){

    return cmocka_run_group_tests(tests, NULL, NULL);

}