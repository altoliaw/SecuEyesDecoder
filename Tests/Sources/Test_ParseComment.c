#include "../Headers/Test_ParseComment.h"

static void dataGenerator(char*, char*, char*, char*, char**, short, short);

/**
 * Verifying if the comments can be parsed by the delimiter (plain text)
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "test@yahoo.com.tw";
    char* demoIp = "200.221.99.3";
    char* demoDbUser = "localhost";
    char* demoSql = "Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 0, 0);

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    assert_string_equal(inferredDemoUserId, demoUserId);
    assert_string_equal(inferredDemoIp, demoIp);
    assert_string_equal(inferredDbUser, demoDbUser);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments the factor of userId is an empty string
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess2(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "";
    char* demoIp = "200.221.99.3";
    char* demoDbUser = "localhost";
    char* demoSql = "Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 0, 0);

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);
    // Here users shall check whether the inferred column is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_null(inferredDemoUserId);
    assert_string_equal(inferredDemoIp, demoIp);
    assert_string_equal(inferredDbUser, demoDbUser);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments the factor of ip is an empty string
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess3(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "test@yahoo.com.tw";
    char* demoIp = "";
    char* demoDbUser = "localhost";
    char* demoSql = "Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 0, 0);

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    assert_string_equal(inferredDemoUserId, demoUserId);
    // Here users shall check whether the inferred column is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_null(inferredDemoIp);
    assert_string_equal(inferredDbUser, demoDbUser);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments the factor of dbUser is an empty string
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess4(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "test@yahoo.com.tw";
    char* demoIp = "127.0.0.1";
    char* demoDbUser = "";
    char* demoSql = "Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 0, 0);

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    assert_string_equal(inferredDemoUserId, demoUserId);
    assert_string_equal(inferredDemoIp, demoIp);
    // Here users shall check whether the inferred column is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_null(inferredDbUser);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments, the factors are empty strings
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess5(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "";
    char* demoIp = "";
    char* demoDbUser = "localhost";
    char* demoSql = "Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 0, 0);

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    // Here users shall check whether inferredDemoUserId is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_null(inferredDemoUserId);
    assert_null(inferredDemoIp);
    assert_string_equal(inferredDbUser, demoDbUser);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments, all factors are empty strings
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess6(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "";
    char* demoIp = "";
    char* demoDbUser = "";
    char* demoSql = "Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 0, 0);

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    // Here users shall check whether inferredDemoUserId is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_null(inferredDemoUserId);
    assert_null(inferredDemoIp);
    assert_null(inferredDbUser);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments, one factor is formed by some commas
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess7(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = ",,,,,";
    char* demoIp = "";
    char* demoDbUser = "";
    char* demoSql = "  ,,,,Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 0, 0);

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    // Here users shall check whether inferredDemoUserId is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_null(inferredDemoUserId);
    assert_null(inferredDemoIp);
    assert_null(inferredDbUser);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments, there exists no any comments and encoded contents
 * (i.e., the dataGenerator(.) function is unnecessary); in addition, the sqlStmt will not remove any comments
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess8(void** state) {
    // Generation of the factors of the testing data
    char* demoSql = "  ,,,,Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    sqlStmt = malloc(sizeof(char) * (int)strlen(demoSql) + sizeof(char));
    memcpy(sqlStmt, demoSql, (int)strlen(demoSql));
    sqlStmt[(int)strlen(demoSql)] = '\0';

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    // Here users shall check whether inferredDemoUserId is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_null(inferredDemoUserId);
    assert_null(inferredDemoIp);
    assert_null(inferredDbUser);
    assert_string_equal(sqlStmt, demoSql);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments, there exists no any comments and encoded contents
 * (i.e., the dataGenerator(.) function is unnecessary); in addition, the sqlStmt will remove the comment
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess9(void** state) {
    // Generation of the factors of the testing data
    char* demoSql = "  ,,,,Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    sqlStmt = malloc(sizeof(char) * (int)strlen(demoSql) + sizeof(char));
    memcpy(sqlStmt, demoSql, (int)strlen(demoSql));
    sqlStmt[(int)strlen(demoSql)] = '\0';

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 1;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    // Here users shall check whether inferredDemoUserId is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_null(inferredDemoUserId);
    assert_null(inferredDemoIp);
    assert_null(inferredDbUser);
    assert_string_equal(sqlStmt, demoSql);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments, there exist no any comments, encoded contents and SQL statements
 * (i.e., the dataGenerator(.) function is unnecessary); in addition, the sqlStmt will not remove any comments
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess10(void** state) {
    // Generation of the factors of the testing data
    char* demoSql = "";
    char* sqlStmt = NULL;

    // Data generator
    sqlStmt = malloc(sizeof(char) * (int)strlen(demoSql) + sizeof(char));
    memcpy(sqlStmt, demoSql, (int)strlen(demoSql));
    sqlStmt[(int)strlen(demoSql)] = '\0';

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    // Here users shall check whether inferredDemoUserId is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_null(inferredDemoUserId);
    assert_null(inferredDemoIp);
    assert_null(inferredDbUser);
    assert_string_equal(sqlStmt, demoSql);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments, there exist no any comments, encoded contents and SQL statements
 * (i.e., the dataGenerator(.) function is unnecessary); in addition, the sqlStmt will remove the comment
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess11(void** state) {
    // Generation of the factors of the testing data
    char* demoSql = "";
    char* sqlStmt = NULL;

    // Data generator
    sqlStmt = malloc(sizeof(char) * (int)strlen(demoSql) + sizeof(char));
    memcpy(sqlStmt, demoSql, (int)strlen(demoSql));
    sqlStmt[(int)strlen(demoSql)] = '\0';

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 1;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    // Here users shall check whether inferredDemoUserId is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_null(inferredDemoUserId);
    assert_null(inferredDemoIp);
    assert_null(inferredDbUser);
    assert_string_equal(sqlStmt, demoSql);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments, the factors are empty strings
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess12(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "alto";
    char* demoIp = "";
    char* demoDbUser = "localhost";
    char* demoSql = "Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 0, 0);

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    // Here users shall check whether inferredDemoUserId is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_string_equal(inferredDemoUserId, demoUserId);
    assert_null(inferredDemoIp);
    assert_string_equal(inferredDbUser, demoDbUser);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments, the factors are empty strings
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess13(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "alto";
    char* demoIp = "192.168.121.12";
    char* demoDbUser = "";
    char* demoSql = "Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 0, 0);

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    // Here users shall check whether inferredDemoUserId is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_string_equal(inferredDemoUserId, demoUserId);
    assert_string_equal(inferredDemoIp, demoIp);
    assert_null(inferredDbUser);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments, all factors are empty strings
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess14(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "阿里布達 abc";
    char* demoIp = "";
    char* demoDbUser = "";
    char* demoSql = "Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 0, 0);

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    // Here users shall check whether inferredDemoUserId is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_string_equal(inferredDemoUserId, demoUserId);
    assert_null(inferredDemoIp);
    assert_null(inferredDbUser);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments, there exists no any comments and encoded contents
 * (i.e., the dataGenerator(.) function is unnecessary); in addition, the sqlStmt will not remove any comments
 *
 * @param state void** None
 */
void Test_ParseComment_userCaseProcess1(void** state) {
    // Generation of the factors of the testing data
    char* demoSql = "/*#^,,,,^#*/Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    sqlStmt = malloc(sizeof(char) * (int)strlen(demoSql) + sizeof(char));
    memcpy(sqlStmt, demoSql, (int)strlen(demoSql));
    sqlStmt[(int)strlen(demoSql)] = '\0';

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    // Here users shall check whether inferredDemoUserId is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_null(inferredDemoUserId);
    assert_null(inferredDemoIp);
    assert_null(inferredDbUser);
    assert_string_equal(sqlStmt, demoSql);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (plain text); in the comments, there exists no any comments and encoded contents
 * (i.e., the dataGenerator(.) function is unnecessary); in addition, the sqlStmt will not remove any comments
 *
 * @param state void** None
 */
void Test_ParseComment_userCaseProcess2(void** state) {
    // Generation of the factors of the testing data
    char* demoSql = "/*#^,^#*/Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    sqlStmt = malloc(sizeof(char) * (int)strlen(demoSql) + sizeof(char));
    memcpy(sqlStmt, demoSql, (int)strlen(demoSql));
    sqlStmt[(int)strlen(demoSql)] = '\0';

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    // Here users shall check whether inferredDemoUserId is NULL because in the function "parseSqlStmt",
    // the inferredDemoUserId will be equal to NULL when the mapping column has no data
    assert_null(inferredDemoUserId);
    assert_null(inferredDemoIp);
    assert_null(inferredDbUser);
    assert_string_equal(sqlStmt, demoSql);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (encoded text); in the comments, the factors are not empty strings
 *
 * @param state void** None
 */
void Test_ParseComment_encodedCaseProcess(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "f12345@yaoo.com.tw";
    char* demoIp = "127.0.0.1";
    char* demoDbUser = "localhost";
    char* demoSql = "Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 1, 0);

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 0;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    assert_string_equal(inferredDemoUserId, demoUserId);
    assert_string_equal(inferredDemoIp, demoIp);
    assert_string_equal(inferredDbUser, demoDbUser);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * Verifying if the comments can be parsed by the delimiter (encoded text); in the comments, a factor is empty strings
 *
 * @param state void** None
 */
void Test_ParseComment_encodedCaseProcess2(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "";
    char* demoIp = "127.0.0.1";
    char* demoDbUser = "localhost";
    char* demoSql = "Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 1, 0);

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 0;
    short isSQLCommentRemoved = 0;
    parseSqlStmt((unsigned char*)sqlStmt, strlen(sqlStmt),
                 &inferredDemoUserId, &inferredDemoIp,
                 &inferredDbUser, (unsigned char*)START_END_SYMBOL,
                 (unsigned char*)DELIMITER, isPlainText,
                 isSQLCommentRemoved);

    assert_null(inferredDemoUserId);
    assert_string_equal(inferredDemoIp, demoIp);
    assert_string_equal(inferredDbUser, demoDbUser);

    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
    }
    if (sqlStmt != NULL) {
        free(sqlStmt);
    }
}

/**
 * The data generator; in the function, the testing data will be generated
 *
 * @param demoUserId char* The user identifier string
 * @param demoIp char* The ip string
 * @param demoDbUser char* The database user string
 * @param sqlDescription char* The SQL statements which users feel like concatenating to the comments
 * @param sqlDataDescription char** The contents which concatenate to the variables above with comment notations,  START_END_SYMBOL and DELIMITER
 * @param isEncoded short A flag for determining whether the data shall be encoded by using the Base64 encoding; 0: plaintext; 1: encoded
 * @param isEncrypted short A flag for determining whether the data shall be encoded by using the Base64 encoding; 0: plaintext; 1: encoded
 */
static void dataGenerator(char* demoUserId, char* demoIp, char* demoDbUser, char* sqlDescription,
                          char** sqlDataDescription, short isEncoded, short isEncrypted) {
    // Calculating the length of the final result without START_END_SYMBOL and the comment notation, "/*"
    int resultLen = strlen(demoUserId) + strlen(((char*)DELIMITER)) + strlen(demoIp) + strlen(((char*)DELIMITER)) + strlen(demoDbUser);
    (*sqlDataDescription) = malloc(sizeof(char) * resultLen + sizeof(char));
    memcpy((*sqlDataDescription), demoUserId, strlen(demoUserId));
    memcpy((*sqlDataDescription) + strlen(demoUserId), ((char*)DELIMITER), strlen(((char*)DELIMITER)));
    memcpy((*sqlDataDescription) + strlen(demoUserId) + strlen(((char*)DELIMITER)), demoIp, strlen(demoIp));
    memcpy((*sqlDataDescription) + strlen(demoUserId) + strlen(((char*)DELIMITER)) + strlen(demoIp), ((char*)DELIMITER), strlen(((char*)DELIMITER)));
    memcpy((*sqlDataDescription) + strlen(demoUserId) + strlen(((char*)DELIMITER)) + strlen(demoIp) + strlen(((char*)DELIMITER)), demoDbUser, strlen(demoDbUser));
    (*sqlDataDescription)[strlen(demoUserId) + strlen(((char*)DELIMITER)) + strlen(demoIp) + strlen(((char*)DELIMITER)) + strlen(demoDbUser)] = '\0';

    // If encoded is necessary, ...
    if (isEncoded == 1) {
        // Encoding process
        int sqlStmtLength = (int)strlen((*sqlDataDescription));
        char* inferredEncodedDataString = (char*)base64Encode((*sqlDataDescription), sqlStmtLength);
        free((*sqlDataDescription));  // Removing the past data
        (*sqlDataDescription) = NULL;
        (*sqlDataDescription) = inferredEncodedDataString;
    }else if(isEncrypted == 1){
        // Encryption process
        int sqlStmtLength = (int)strlen((*sqlDataDescription));
        unsigned int cipherSpaceLength = 0;
        char* inferredEncryptedDataString = (char*)APUDataEncrypt((unsigned char*)(*sqlDataDescription), sqlStmtLength, &cipherSpaceLength);
        free((*sqlDataDescription));  // Removing the past data
        (*sqlDataDescription) = NULL;
        (*sqlDataDescription) = inferredEncryptedDataString;
    }

    // Adding the symmetric START_END_SYMBOL & comment marks "/*"
    char* commentMark = "/*";
    int remaindedSqlLength = (int)strlen(sqlDescription);
    int sqlStmtLength = (int)strlen((*sqlDataDescription));
    int allMarksLength = 2 * ((int)strlen(commentMark) + (int)strlen((char*)START_END_SYMBOL));
    // Reallocating the memory
    (*sqlDataDescription) = realloc((*sqlDataDescription), sqlStmtLength + allMarksLength + remaindedSqlLength + 1);  // Resize the memory
    (*sqlDataDescription)[sqlStmtLength + allMarksLength + remaindedSqlLength] = '\0';

    memmove((*sqlDataDescription) + ((int)strlen(commentMark) + (int)strlen((char*)START_END_SYMBOL)), (*sqlDataDescription), sqlStmtLength);  // Moving to the accurate position
    memcpy((*sqlDataDescription), commentMark, strlen(commentMark));
    memcpy((*sqlDataDescription) + strlen(commentMark), (char*)START_END_SYMBOL, strlen((char*)START_END_SYMBOL));

    // Filling up (*sqlDataDescription) with START_END_SYMBOL in reversed direction
    for (int i = 0; i < strlen((char*)START_END_SYMBOL); i++) {
        (*sqlDataDescription)[(allMarksLength / 2) + sqlStmtLength + i] = ((char*)START_END_SYMBOL)[strlen((char*)START_END_SYMBOL) - 1 - i];
    }

    // Filling up (*sqlDataDescription) with commentMark in reversed direction
    for (int i = 0; i < strlen(commentMark); i++) {
        (*sqlDataDescription)[(allMarksLength / 2) + sqlStmtLength + strlen((char*)START_END_SYMBOL) + i] =
            commentMark[strlen(commentMark) - 1 - i];
    }
    memcpy((*sqlDataDescription) + allMarksLength + sqlStmtLength, sqlDescription, remaindedSqlLength);
}