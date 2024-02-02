add_library(Test_Lib
    Test_Base64.c
    Test_Encrypt.c
    Test_ParseComment.c
)
target_include_directories(Test_Lib PUBLIC ../Headers)