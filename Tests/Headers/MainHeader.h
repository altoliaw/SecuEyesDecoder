#pragma once
/** @file MainHeader.h
 * The main header file; definition of the includeed files and the testing groups
 *
 * @author Nick
 * @date 2023/11/21
 */
#include "./Test_Base64.h"
const struct CMUnitTest Test_Base64_Group[] = {
    cmocka_unit_test(Test_Base64_encodedDecodedProcess),
    cmocka_unit_test(Test_Base64_encodedDecodedProcess2),
    cmocka_unit_test(Test_Base64_encodedDecodedProcess3),
};


#include "./Test_ParseComment.h"
const struct CMUnitTest Test_ParseComment_Group[] = {
    cmocka_unit_test(Test_ParseComment_normalCaseProcess),
    cmocka_unit_test(Test_ParseComment_normalCaseProcess2),
    cmocka_unit_test(Test_ParseComment_normalCaseProcess3),
    cmocka_unit_test(Test_ParseComment_normalCaseProcess4),
    cmocka_unit_test(Test_ParseComment_normalCaseProcess5),
    cmocka_unit_test(Test_ParseComment_normalCaseProcess6),
    cmocka_unit_test(Test_ParseComment_normalCaseProcess7),
    cmocka_unit_test(Test_ParseComment_normalCaseProcess8),
    cmocka_unit_test(Test_ParseComment_normalCaseProcess9),
    cmocka_unit_test(Test_ParseComment_normalCaseProcess10),
    cmocka_unit_test(Test_ParseComment_normalCaseProcess11),
    //================================================================
    cmocka_unit_test(Test_ParseComment_encodedCaseProcess),
    cmocka_unit_test(Test_ParseComment_encodedCaseProcess2),
};