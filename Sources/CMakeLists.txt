add_subdirectory(BuildDLL)
add_library(ParseSqlStmt
    ParseSqlStmt.c
    ArrayOfPointerOfString.c
)
target_include_directories(ParseSqlStmt PUBLIC ../Headers)