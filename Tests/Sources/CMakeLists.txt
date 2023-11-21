add_library(Test_Base64
    Test_Base64.c
    Test_ParseComment.c
)
target_include_directories(Test_Base64 PUBLIC ../Headers)