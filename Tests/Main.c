/** @file Main.c
 * Unit tests for all libraries
 *
 * @author Nick Liao and Ian, Chen
 * @date 2023/07/03
 *
 * @remark (2023/07/21, edited by Nick) Aggregating some similar types of test codes into a group
 */
#include "Headers/MainHeader.h"

/**
 * The main function for the unit tests
 * @return int 0 implies success; 1 implies failure
 */
int main(){
    int isFault = 0; // default value is 0, and the value implies that there exists no error in the tests
    isFault |= cmocka_run_group_tests(Test_Base64_Group, NULL, NULL);
    isFault |= cmocka_run_group_tests(Test_Encrypt_Group, NULL, NULL);
    isFault |= cmocka_run_group_tests(Test_ParseComment_Group, NULL, NULL);
    return isFault;
}