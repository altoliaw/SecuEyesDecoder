#include "../Headers/Test_ParseComment.h"

/**
 * Verifying if the comments can be parsed by the delimiter (plain text)
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess(void** state) {
    // #define START_END_SYMBOL "#^" // The synmetric tag for the comment section
    // #define DELIMITER "," // The delimiter in the comment section
    // Generation of the testing data
    char* demoUserId = "ianmina0322@gmail.com";
    char* demoIp = "200.221.99.3";
    char* demoDbUser = "localhost";
    char* sqlStmt = NULL;

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

static void dataGenerator(char* demoUserId, char* demoIp, char* demoDbUser, char* sqlDescrpition,
                          char** sqlDataDescrpition) {
    // Calculating the length of the final result without START_END_SYMBOL and the comment notation, "/*"
    int resultLen = strlen(demoUserId) + strlen(((char*)DELIMITER)) + strlen(demoIp) + strlen(((char*)DELIMITER)) + strlen(demoDbUser);
    char* sqlStmt = NULL;
    sqlStmt = malloc(sizeof(char) * resultLen + sizeof(char));
    memcpy(sqlStmt, demoUserId, strlen(demoUserId));
    memcpy(sqlStmt + strlen(demoUserId), ((char*)DELIMITER), strlen(((char*)DELIMITER)));
    memcpy(sqlStmt + strlen(demoUserId) + strlen(((char*)DELIMITER)), demoIp, strlen(demoIp));
    memcpy(sqlStmt + strlen(demoUserId) + strlen(((char*)DELIMITER)) + strlen(demoIp), ((char*)DELIMITER), strlen(((char*)DELIMITER)));
    memcpy(sqlStmt + strlen(demoUserId) + strlen(((char*)DELIMITER)) + strlen(demoIp) + strlen(((char*)DELIMITER)), demoDbUser, strlen(demoDbUser));
    sqlStmt[strlen(demoUserId) + strlen(((char*)DELIMITER)) + strlen(demoIp) + strlen(((char*)DELIMITER)) + strlen(demoDbUser)] = '\0';

    // Adding the symmetric START_END_SYMBOL & comment marks "/*"
    char* commentMark = "/*";
    int sqlStmtLength = (int)strlen(sqlStmt);
    int allMarksLength = 2 * ((int)strlen(commentMark) + (int)strlen((char*)START_END_SYMBOL));
    sqlStmt = realloc(sqlStmt, sqlStmtLength + allMarksLength + 1);  // Resize the memory
    sqlStmt[sqlStmtLength + allMarksLength] = '\0';
    memmove(sqlStmt + ((int)strlen(commentMark) + (int)strlen((char*)START_END_SYMBOL)), sqlStmt, sqlStmtLength);  // Moving to the accurate position
    memcpy(sqlStmt, commentMark, strlen(commentMark));
    memcpy(sqlStmt + strlen(commentMark), (char*)START_END_SYMBOL, strlen((char*)START_END_SYMBOL));

    // Filling up sqlStmt with START_END_SYMBOL in reversed direction
    for (int i = 0; i < strlen((char*)START_END_SYMBOL); i++) {
        sqlStmt[(allMarksLength / 2) + sqlStmtLength + i] = ((char*)START_END_SYMBOL)[strlen((char*)START_END_SYMBOL) - 1 - i];
    }

    // Filling up sqlStmt with commentMark in reversed direction
    for (int i = 0; i < strlen(commentMark); i++) {
        sqlStmt[(allMarksLength / 2) + sqlStmtLength + strlen((char*)START_END_SYMBOL) + i] =
            commentMark[strlen(commentMark) - 1 - i];
    }
}