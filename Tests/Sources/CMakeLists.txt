add_library(Test_Lib
    Test_Base64.c
    Test_Encrypt.c
    Test_ParseComment.c
    Test_ParseJsonComment.c
)
target_include_directories(Test_Lib PUBLIC ../Headers)