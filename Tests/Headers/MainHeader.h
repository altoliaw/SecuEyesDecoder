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

#include "./Test_Encrypt.h"
const struct CMUnitTest Test_Encrypt_Group[] = {
    cmocka_unit_test(Test_Encrypt_DecryptProcess1),
    cmocka_unit_test(Test_Encrypt_DecryptProcess2),
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
    cmocka_unit_test(Test_ParseComment_normalCaseProcess12),
    cmocka_unit_test(Test_ParseComment_normalCaseProcess13),
    cmocka_unit_test(Test_ParseComment_normalCaseProcess14),
    //================================================================
    cmocka_unit_test(Test_ParseComment_userCaseProcess1),
    cmocka_unit_test(Test_ParseComment_userCaseProcess2),
    //================================================================
    cmocka_unit_test(Test_ParseComment_encodedCaseProcess),
    cmocka_unit_test(Test_ParseComment_encodedCaseProcess2),
};

#include "./Test_ParseJsonComment.h"
const struct CMUnitTest Test_ParseJsonComment_Group[] = {
    cmocka_unit_test(Test_ParseJsonComment_normalCaseProcess1),
    cmocka_unit_test(Test_ParseJsonComment_normalCaseProcess2),
    cmocka_unit_test(Test_ParseJsonComment_normalCaseProcess3),
    cmocka_unit_test(Test_ParseJsonComment_normalCaseProcess4),
    cmocka_unit_test(Test_ParseJsonComment_normalCaseProcess5),
    cmocka_unit_test(Test_ParseJsonComment_normalCaseProcess6),
    cmocka_unit_test(Test_ParseJsonComment_normalCaseProcess7),
    cmocka_unit_test(Test_ParseJsonComment_normalCaseProcess8),
    cmocka_unit_test(Test_ParseJsonComment_normalCaseProcess9),
    cmocka_unit_test(Test_ParseJsonComment_normalCaseProcess10),
    cmocka_unit_test(Test_ParseJsonComment_normalCaseProcess11),
    //=========================Custom=====================================
    cmocka_unit_test(Test_ParseJsonComment_customCaseProcess1),
    cmocka_unit_test(Test_ParseJsonComment_customCaseProcess2),
    cmocka_unit_test(Test_ParseJsonComment_customCaseProcess3),
    //=========================Json=======================================
    cmocka_unit_test(Test_ParseJsonComment_encryptCaseProcess1),
    cmocka_unit_test(Test_ParseJsonComment_encryptCaseProcess2),
};

#include "./Test_ParseAbbreviationJsonComment.h"
const struct CMUnitTest Test_ParseAbbreviationJsonComment_Group[] = {
    cmocka_unit_test(Test_ParseAbbreviationJsonComment_normalCaseProcess1),
    cmocka_unit_test(Test_ParseAbbreviationJsonComment_normalCaseProcess2),
    cmocka_unit_test(Test_ParseAbbreviationJsonComment_normalCaseProcess3),
    cmocka_unit_test(Test_ParseAbbreviationJsonComment_normalCaseProcess4),
    cmocka_unit_test(Test_ParseAbbreviationJsonComment_normalCaseProcess5),
    cmocka_unit_test(Test_ParseAbbreviationJsonComment_normalCaseProcess6),
    //=========================Encryption=================================
    cmocka_unit_test(Test_ParseAbbreviationJsonComment_encryptCaseProcess1),
    cmocka_unit_test(Test_ParseAbbreviationJsonComment_encryptCaseProcess2),
    //=========================Special====================================
    cmocka_unit_test(Test_ParseAbbreviationJsonComment_specialCaseProcess1),
    cmocka_unit_test(Test_ParseAbbreviationJsonComment_specialCaseProcess2),
    cmocka_unit_test(Test_ParseAbbreviationJsonComment_specialCaseProcess3),
};

#include "./Test_BuildDLL.h"
const struct CMUnitTest Test_DLLVerification_Group[] = {
    cmocka_unit_test(Test_Base64_dllVerificationProcess1),
    cmocka_unit_test(Test_Base64_dllVerificationProcess2),
};