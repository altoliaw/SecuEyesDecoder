#include "../Headers/Test_ParseComment.h"

/**
 * Verifying if the comments can be parsed by the delimiter (plain text)
 *
 * @param state void** None
 */
void Test_ParseComment_normalCaseProcess(void **state) {
   // Definitions of the testing data
   char* demoUserId = "ianmina0322@gmail.com";
   char* demoIp = "200.221.99.3";
   char* sqlStmt = "ianmina0322@gmail.com,200.221.99.3";

   unsigned int TargetUserIdLen = strlen(demoUserId);
   unsigned int TargetIpLen = strlen(demoIp);
   unsigned int sqlStmtLen = strlen(sqlStmt);

   /** Text */
   unsigned char *encodedprefixText = "UUUUUUUUUUUUUU I will be back online";
   unsigned char *encodedprefix = "/*#^";
   unsigned char *encodedendfix = "^#*/";
   unsigned char *encodedSqlStmt = base64Encode(sqlStmt, sqlStmtLen);

   /** Text  Len */
   unsigned int encodedprefixLen = (unsigned int)strlen((unsigned char *)encodedprefix);
   unsigned int encodedendfixLen = (unsigned int)strlen((unsigned char *)encodedendfix);
   unsigned int encodedprefixTextLen = (unsigned int)strlen((unsigned char *)encodedprefixText);
   unsigned int encodedSqlStmtLen = (unsigned int)strlen((unsigned char *)encodedSqlStmt);

   /**  Append */
   unsigned char *encodedtarget = (unsigned char *)malloc(encodedprefixTextLen + encodedprefixLen + encodedSqlStmtLen + encodedendfixLen);
   unsigned int encodedtargetLen = encodedprefixTextLen + encodedprefixLen + encodedSqlStmtLen + encodedendfixLen;

   /**  Append */
   strcpy(encodedtarget, encodedprefixText);
   strcat(encodedtarget, encodedprefix);
   strcat(encodedtarget, encodedSqlStmt);
   strcat(encodedtarget, encodedendfix);

   printf("\n\nSource: %s%s%s%s\n", encodedprefixText, encodedprefix, sqlStmt, encodedendfix);
   printf("Encode result :  %s\n\n", encodedtarget);

    /** result var*/
    unsigned char *userId = NULL;
    unsigned char *ip = NULL;

    int result = parseSqlStmt(
        encodedtarget,
        encodedtargetLen,
        &userId,
        &ip,
        (unsigned char *)START_END_SYMBOL,
        (unsigned char *)DELIMITER, 0);

    /** Unit Test  */

    if (userId != NULL) {
        assert_string_equal(userId, demoUserId);
    } else {
        printf("userId is NULL\n");
    }

    if (ip != NULL) {
        assert_string_equal(ip, demoIp);
    } else {
        printf("ip is NULL\n");
    }

    printf("\n Result : %s\n\n", encodedtarget);

    if (userId != NULL) {
        free(userId);
    }
    if (ip != NULL) {
        free(ip);
    };

    free(encodedtarget);
}
