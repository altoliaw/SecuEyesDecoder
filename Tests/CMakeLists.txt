add_subdirectory(Sources)

add_executable(Test
    ./Main.c
)
target_include_directories(Test PUBLIC ./Headers)

target_link_libraries(Test
    Test_Base64
    Mains
    cmocka
)