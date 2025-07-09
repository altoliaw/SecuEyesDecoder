#include "../Headers/Test_ParseAbbreviationJsonComment.h"

static void dataGenerator(char*, char*, char*, char*, char**, short, short);

/**
 * Verifying if the comments can be parsed by the delimiter (plain text)
 *
 * @param state void** None
 */
void Test_ParseAbbreviationJsonComment_normalCaseProcess1(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "test@yahoo.com.tw";
    char* demoIp = "200.221.99.3";
    char* demoDbUser = "localhost";
    char* demoSql = "Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 0, 0);

    fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 1;
    short isSQLCommentRemoved = 0;

    parseSqlStmtInJsonFormat((unsigned char*)sqlStmt, strlen(sqlStmt),
                             (unsigned char*)START_END_SYMBOL,
                             (unsigned char*)DELIMITER, isPlainText,
                             isSQLCommentRemoved,
                             3,
                             'a', &inferredDemoUserId,
                             'b', &inferredDemoIp,
                             'c', &inferredDbUser);

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
 * Verifying if the comments can be parsed by the delimiter (plain text)
 *
 * @param state void** None
 */
void Test_ParseAbbreviationJsonComment_normalCaseProcess2(void** state) {
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

    parseSqlStmtInJsonFormat((unsigned char*)sqlStmt, strlen(sqlStmt),
                             (unsigned char*)START_END_SYMBOL,
                             (unsigned char*)DELIMITER, isPlainText,
                             isSQLCommentRemoved,
                             3,
                             'a', &inferredDemoUserId,
                             'b', &inferredDemoIp,
                             'c', &inferredDbUser);

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
 * Verifying if the comments can be parsed by the delimiter (plain text)
 *
 * @param state void** None
 */
void Test_ParseAbbreviationJsonComment_normalCaseProcess3(void** state) {
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

    parseSqlStmtInJsonFormat((unsigned char*)sqlStmt, strlen(sqlStmt),
                             (unsigned char*)START_END_SYMBOL,
                             (unsigned char*)DELIMITER, isPlainText,
                             isSQLCommentRemoved,
                             3,
                             'a', &inferredDemoUserId,
                             'b', &inferredDemoIp,
                             'c', &inferredDbUser);

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
 * Verifying if the comments can be parsed by the delimiter (plain text)
 *
 * @param state void** None
 */
void Test_ParseAbbreviationJsonComment_normalCaseProcess4(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "test@yahoo.com.tw";
    char* demoIp = "200.221.99.3";
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

    parseSqlStmtInJsonFormat((unsigned char*)sqlStmt, strlen(sqlStmt),
                             (unsigned char*)START_END_SYMBOL,
                             (unsigned char*)DELIMITER, isPlainText,
                             isSQLCommentRemoved,
                             3,
                             'a', &inferredDemoUserId,
                             'b', &inferredDemoIp,
                             'c', &inferredDbUser);

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
 * Verifying if the comments can be parsed by the delimiter (plain text)
 *
 * @param state void** None
 */
void Test_ParseAbbreviationJsonComment_normalCaseProcess5(void** state) {
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

    parseSqlStmtInJsonFormat((unsigned char*)sqlStmt, strlen(sqlStmt),
                             (unsigned char*)START_END_SYMBOL,
                             (unsigned char*)DELIMITER, isPlainText,
                             isSQLCommentRemoved,
                             3,
                             'a', &inferredDemoUserId,
                             'b', &inferredDemoIp,
                             'c', &inferredDbUser);

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
 * Verifying if the comments can be parsed by the delimiter (plain text)
 *
 * @param state void** None
 */
void Test_ParseAbbreviationJsonComment_normalCaseProcess6(void** state) {
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

    parseSqlStmtInJsonFormat((unsigned char*)sqlStmt, strlen(sqlStmt),
                             (unsigned char*)START_END_SYMBOL,
                             (unsigned char*)DELIMITER, isPlainText,
                             isSQLCommentRemoved,
                             3,
                             'a', &inferredDemoUserId,
                             'b', &inferredDemoIp,
                             'c', &inferredDbUser);

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
 * Verifying if the comments can be parsed by the delimiter (plain text)
 *
 * @param state void** None
 */
void Test_ParseAbbreviationJsonComment_encryptCaseProcess1(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "Cumming";
    char* demoIp = "127.2.1.4";
    char* demoDbUser = "thisusers";
    char* demoSql = "Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 0, 1);

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 0;
    short isSQLCommentRemoved = 0;
    return;

    parseSqlStmtInJsonFormat((unsigned char*)sqlStmt, strlen(sqlStmt),
                             (unsigned char*)START_END_SYMBOL,
                             (unsigned char*)DELIMITER, isPlainText,
                             isSQLCommentRemoved,
                             3,
                             'a', &inferredDemoUserId,
                             'b', &inferredDemoIp,
                             'c', &inferredDbUser);

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
 * Verifying if the comments can be parsed by the delimiter (plain text)
 *
 * @param state void** None
 */
void Test_ParseAbbreviationJsonComment_encryptCaseProcess2(void** state) {
    // Generation of the factors of the testing data
    char* demoUserId = "";
    char* demoIp = "127.2.1.4";
    char* demoDbUser = "this-users";
    char* demoSql = "Select * from test";
    char* sqlStmt = NULL;

    // Data generator
    dataGenerator(demoUserId, demoIp, demoDbUser, demoSql, &sqlStmt, 0, 1);

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;


    short isPlainText = 0;
    short isSQLCommentRemoved = 0;

    parseSqlStmtInJsonFormat((unsigned char*)sqlStmt, strlen(sqlStmt),
                             (unsigned char*)START_END_SYMBOL,
                             (unsigned char*)DELIMITER, isPlainText,
                             isSQLCommentRemoved,
                             3,
                             'a', &inferredDemoUserId,
                             'b', &inferredDemoIp,
                             'c', &inferredDbUser);

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
 * Verifying if the ciphertext can be parsed as the one which Leo expects
 *
 * @param state void** None
 */
void Test_ParseAbbreviationJsonComment_specialCaseProcess1(void** state) {
    char* sqlStmt = "/* mysql-connector-j-8.0.31 (Revision: 0c86fc148d567b62266c2302bdad0f1e7a7e4eba) */SELECT  @@session.auto_increment_increment AS auto_increment_increment,";

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 0;
    short isSQLCommentRemoved = 0;

    parseSqlStmtInJsonFormat((unsigned char*)sqlStmt, strlen(sqlStmt),
                             (unsigned char*)START_END_SYMBOL,
                             (unsigned char*)DELIMITER, isPlainText,
                             isSQLCommentRemoved,
                             3,
                             'a', &inferredDemoUserId,
                             'b', &inferredDemoIp,
                             'c', &inferredDbUser);

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
}

/**
 * Verifying if the ciphertext can be parsed as the one which Leo expects
 *
 * @param state void** None
 */
void Test_ParseAbbreviationJsonComment_specialCaseProcess2(void** state) {
    char* sqlStmt = "/*#^FEF185B2F9D5031B565F84B2D658ACB85659A9B85759AD38FF5EAFB9FEF10393F9E3031BD75B0E19D2DFAC37^#*/ select count(*)  from tb_blog_tag@#~!0a#@@    where is_deleted=0";

    // fprintf(stderr, "[%s] [%d]\n", sqlStmt, strlen(sqlStmt));
    // Parser verifications
    unsigned char* inferredDemoUserId = NULL;
    unsigned char* inferredDemoIp = NULL;
    unsigned char* inferredDbUser = NULL;

    short isPlainText = 0;
    short isSQLCommentRemoved = 0;

    parseSqlStmtInJsonFormat((unsigned char*)sqlStmt, strlen(sqlStmt),
                             (unsigned char*)START_END_SYMBOL,
                             (unsigned char*)DELIMITER, isPlainText,
                             isSQLCommentRemoved,
                             3,
                             'a', &inferredDemoUserId,
                             'b', &inferredDemoIp,
                             'c', &inferredDbUser);

    assert_string_equal(inferredDemoUserId, (unsigned char*)"admin");    
    assert_string_equal(inferredDemoIp, (unsigned char*)"192.168.150.254");
    assert_string_equal(inferredDbUser, (unsigned char*)"myadmin@vm203088");

    // assert_null(inferredDemoUserId);
    // assert_null(inferredDemoIp);
    // assert_null(inferredDbUser);
    // fprintf(stderr, "%s\n", inferredDemoUserId);
    // fprintf(stderr, "%s\n", inferredDemoIp);
    // fprintf(stderr, "%s\n", inferredDbUser);


    if (inferredDemoUserId != NULL) {
        free(inferredDemoUserId);
    }
    if (inferredDemoIp != NULL) {
        free(inferredDemoIp);
    }
    if (inferredDbUser != NULL) {
        free(inferredDbUser);
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
    int resultLen = strlen(demoUserId) + strlen(demoIp) + strlen(demoDbUser) + 10 + 1;  // 10 : `a:, b:, c:`, 1 for '\0'
    (*sqlDataDescription) = (char*)calloc(resultLen + 1, sizeof(char));
    resultLen = snprintf((*sqlDataDescription), resultLen, "a:%s, b:%s, c:%s\0", demoUserId, demoIp, demoDbUser);
    (*sqlDataDescription)[resultLen + 1] = '\0';

    // If encoded is necessary, ...
    if (isEncoded == 1) {
        // Encoding process
        int sqlStmtLength = (int)strlen((*sqlDataDescription));
        char* inferredEncodedDataString = (char*)base64Encode((*sqlDataDescription), sqlStmtLength);
        free((*sqlDataDescription));  // Removing the past data
        (*sqlDataDescription) = NULL;
        (*sqlDataDescription) = inferredEncodedDataString;
    } else if (isEncrypted == 1) {
        // Encryption process
        unsigned int cipherSpaceLength = 0;  // To obtain the length of the encryption
        int sqlStmtLength = (int)strlen((*sqlDataDescription));
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