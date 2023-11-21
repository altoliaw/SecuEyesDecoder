#pragma once
/** @file MainHeader.h
 * The main header file; definition of the includeed files and the testing groups
 *
 * @author Nick
 * @date 2023/11/21
 */
#include "./Test_Base64.h"
const struct CMUnitTest Test_Base64_Group[] = {
    cmocka_unit_test(Test_Base64Encoders_and_Decoders_Single),
    cmocka_unit_test(Test_Base64Encoders_and_Decoders_Word),
    cmocka_unit_test(Test_Base64Encoders_and_Decoders_String),
};


#include "./Test_PraseComment.h"
const struct CMUnitTest Test_ParseComment_Group[] = {
    cmocka_unit_test(Test_parseSqlStmt_Normal),
    cmocka_unit_test(Test_parseSqlStmt_Normal_FirstNULL),
    cmocka_unit_test(Test_parseSqlStmt_Normal_LastNULL),
    cmocka_unit_test(Test_parseSqlStmt_Normal_MultiDelimiter),
    cmocka_unit_test(Test_parseSqlStmt_Target_At_Mid_TwoDelimiter),
    cmocka_unit_test(Test_parseSqlStmt_Target_At_Mid),
    cmocka_unit_test(Test_parseSqlStmt_Multi_Target),
};