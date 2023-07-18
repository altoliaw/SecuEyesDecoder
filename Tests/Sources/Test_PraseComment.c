/**
 * @file Test_PraseComment.c
 * @author your name (you@domain.com)
 * @brief Test_PraseComment
 * @version 0.1
 * @date 2023-07-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include "../Headers/Test_PraseComment.h"
#include "Test_PraseComment.h"

void Test_parseSqlStmt_Normal(void **state){

     /** data*/
    unsigned char *TargetUserId = "ianmina0322@gmail.com";
    unsigned char *TargetIp = "200.221.99.3";
    unsigned char *sqlStmt = "ianmina0322@gmail.com,200.221.99.3";

    /** Len*/
    unsigned int TargetUserIdLen = (unsigned int)strlen(( unsigned char*)TargetUserId);
    unsigned int TargetIpLen = (unsigned int)strlen(( unsigned char*)TargetIp);
    unsigned int sqlStmtLen = (unsigned int)strlen(( unsigned char*)sqlStmt);


    /** Text */
    unsigned char *encodedprefixText= "UUUUUUUUUUUUUU I will be back online";
    unsigned char *encodedprefix = "/*#^";
    unsigned char *encodedendfix = "^#*/";
    unsigned char *encodedSqlStmt = base64Encode(sqlStmt, sqlStmtLen);

     /** Text  Len */
    unsigned int encodedprefixLen = (unsigned int)strlen(( unsigned char*)encodedprefix);
    unsigned int encodedendfixLen = (unsigned int)strlen(( unsigned char*)encodedendfix);
    unsigned int encodedprefixTextLen = (unsigned int)strlen(( unsigned char*)encodedprefixText);
    unsigned int encodedSqlStmtLen = (unsigned int)strlen(( unsigned char*)encodedSqlStmt);

    /**  Append */
    unsigned char *encodedtarget = (unsigned char*)malloc(encodedprefixTextLen +encodedprefixLen + encodedSqlStmtLen + encodedendfixLen);
    unsigned int encodedtargetLen = encodedprefixTextLen + encodedprefixLen + encodedSqlStmtLen + encodedendfixLen;

    /**  Append */
    strcpy(encodedtarget,encodedprefixText);
    strcat(encodedtarget, encodedprefix);
    strcat(encodedtarget, encodedSqlStmt);
    strcat(encodedtarget, encodedendfix);
    
    printf("\n\nSource: %s%s%s%s\n", encodedprefixText, encodedprefix, sqlStmt, encodedendfix);
    printf("Encode result :  %s\n\n",encodedtarget);

    /** result var*/

    unsigned char* userId = NULL;
    unsigned char* ip = NULL;


    int result = parseSqlStmt(
       encodedtarget,
       encodedtargetLen,
       &userId,
       &ip,
       (unsigned char*)START_END_SYMBOL,
       (unsigned char*)DELIMITER);

    /** Unit Test  */
   
    if(userId != NULL) {
        assert_string_equal(userId , TargetUserId);
    }
    else{
      printf("userId is NULL\n");
    }

    if(ip != NULL) {
       assert_string_equal(ip , TargetIp);
    }
     else{
      printf("ip is NULL\n");
    }

    

    if(userId != NULL) {
       free(userId);
    }
    if(ip != NULL) {
       free(ip);
    };


    free(encodedtarget);

}

void Test_parseSqlStmt_Normal_FirstNULL(void **state)
{
  /** data*/
    unsigned char *TargetUserId = "ianmina0322@gmail.com";
    unsigned char *TargetIp = "200.221.99.3";
    unsigned char *sqlStmt = ",200.221.99.3";

    /** Len*/
    unsigned int TargetUserIdLen = (unsigned int)strlen(( unsigned char*)TargetUserId);
    unsigned int TargetIpLen = (unsigned int)strlen(( unsigned char*)TargetIp);
    unsigned int sqlStmtLen = (unsigned int)strlen(( unsigned char*)sqlStmt);


    /** Text */
    unsigned char *encodedprefixText= "UUUUUUUUUUUUUU I will be back online";
    unsigned char *encodedprefix = "/*#^";
    unsigned char *encodedendfix = "^#*/";
    unsigned char *encodedSqlStmt = base64Encode(sqlStmt, sqlStmtLen);

     /** Text  Len */
    unsigned int encodedprefixLen = (unsigned int)strlen(( unsigned char*)encodedprefix);
    unsigned int encodedendfixLen = (unsigned int)strlen(( unsigned char*)encodedendfix);
    unsigned int encodedprefixTextLen = (unsigned int)strlen(( unsigned char*)encodedprefixText);
    unsigned int encodedSqlStmtLen = (unsigned int)strlen(( unsigned char*)encodedSqlStmt);

    /**  Append */
    unsigned char *encodedtarget = (unsigned char*)malloc(encodedprefixTextLen +encodedprefixLen + encodedSqlStmtLen + encodedendfixLen);
    unsigned int encodedtargetLen = encodedprefixTextLen + encodedprefixLen + encodedSqlStmtLen + encodedendfixLen;

    /**  Append */
    strcpy(encodedtarget,encodedprefixText);
    strcat(encodedtarget, encodedprefix);
    strcat(encodedtarget, encodedSqlStmt);
    strcat(encodedtarget, encodedendfix);

    printf("\n\nSource: %s%s%s%s\n", encodedprefixText, encodedprefix, sqlStmt, encodedendfix);
    printf("Encode result :  %s\n\n",encodedtarget);

    /** result var*/

    unsigned char* userId = NULL;
    unsigned char* ip = NULL;


    int result = parseSqlStmt(
       encodedtarget,
       encodedtargetLen,
       &userId,
       &ip,
       (unsigned char*)START_END_SYMBOL,
       (unsigned char*)DELIMITER);

    /** Unit Test  */
   
    if(userId != NULL) {
        assert_string_equal(userId , TargetUserId);
    }
    else{
      printf("userId is NULL\n");
    }

    if(ip != NULL) {
       assert_string_equal(ip , TargetIp);
    }
     else{
      printf("ip is NULL\n");
    }

    

    if(userId != NULL) {
       free(userId);
    }
    if(ip != NULL) {
       free(ip);
    };


    free(encodedtarget);

}
void Test_parseSqlStmt_Normal_LastNULL(void **state)
{
  /** data*/
    unsigned char *TargetUserId = "ianmina0322@gmail.com";
    unsigned char *TargetIp = "200.221.99.3";
    unsigned char *sqlStmt = "ianmina0322@gmail.com,";

    /** Len*/
    unsigned int TargetUserIdLen = (unsigned int)strlen(( unsigned char*)TargetUserId);
    unsigned int TargetIpLen = (unsigned int)strlen(( unsigned char*)TargetIp);
    unsigned int sqlStmtLen = (unsigned int)strlen(( unsigned char*)sqlStmt);


    /** Text */
    unsigned char *encodedprefixText= "UUUUUUUUUUUUUU I will be back online";
    unsigned char *encodedprefix = "/*#^";
    unsigned char *encodedendfix = "^#*/";
    unsigned char *encodedSqlStmt = base64Encode(sqlStmt, sqlStmtLen);

     /** Text  Len */
    unsigned int encodedprefixLen = (unsigned int)strlen(( unsigned char*)encodedprefix);
    unsigned int encodedendfixLen = (unsigned int)strlen(( unsigned char*)encodedendfix);
    unsigned int encodedprefixTextLen = (unsigned int)strlen(( unsigned char*)encodedprefixText);
    unsigned int encodedSqlStmtLen = (unsigned int)strlen(( unsigned char*)encodedSqlStmt);

    /**  Append */
    unsigned char *encodedtarget = (unsigned char*)malloc(encodedprefixTextLen +encodedprefixLen + encodedSqlStmtLen + encodedendfixLen);
    unsigned int encodedtargetLen = encodedprefixTextLen + encodedprefixLen + encodedSqlStmtLen + encodedendfixLen;

    /**  Append */
    strcpy(encodedtarget,encodedprefixText);
    strcat(encodedtarget, encodedprefix);
    strcat(encodedtarget, encodedSqlStmt);
    strcat(encodedtarget, encodedendfix);
    printf("\n\nSource: %s%s%s%s\n", encodedprefixText, encodedprefix, sqlStmt, encodedendfix);
    printf("Encode result :  %s\n\n",encodedtarget);

    /** result var*/

    unsigned char* userId = NULL;
    unsigned char* ip = NULL;


    int result = parseSqlStmt(
       encodedtarget,
       encodedtargetLen,
       &userId,
       &ip,
       (unsigned char*)START_END_SYMBOL,
       (unsigned char*)DELIMITER);

    /** Unit Test  */
   
    if(userId != NULL) {
        assert_string_equal(userId , TargetUserId);
    }
    else{
      printf("userId is NULL\n");
    }

    if(ip != NULL) {
       assert_string_equal(ip , TargetIp);
    }
     else{
      printf("ip is NULL\n");
    }

    

    if(userId != NULL) {
       free(userId);
    }
    if(ip != NULL) {
       free(ip);
    };


    free(encodedtarget);

}
void Test_parseSqlStmt_Normal_MultiDelimiter(void **state)
{

 /** data*/
    unsigned char *TargetUserId = "ianmina0322@gmail.com";
    unsigned char *TargetIp = "200.221.99.3";
    unsigned char *sqlStmt = "ianmina0322@gmail.com,,,,200.221.99.3";

    /** Len*/
    unsigned int TargetUserIdLen = (unsigned int)strlen(( unsigned char*)TargetUserId);
    unsigned int TargetIpLen = (unsigned int)strlen(( unsigned char*)TargetIp);
    unsigned int sqlStmtLen = (unsigned int)strlen(( unsigned char*)sqlStmt);


    /** Text */
    unsigned char *encodedprefixText= "UUUUUUUUUUUUUU I will be back online";
    unsigned char *encodedprefix = "/*#^";
    unsigned char *encodedendfix = "^#*/";
    unsigned char *encodedSqlStmt = base64Encode(sqlStmt, sqlStmtLen);

     /** Text  Len */
    unsigned int encodedprefixLen = (unsigned int)strlen(( unsigned char*)encodedprefix);
    unsigned int encodedendfixLen = (unsigned int)strlen(( unsigned char*)encodedendfix);
    unsigned int encodedprefixTextLen = (unsigned int)strlen(( unsigned char*)encodedprefixText);
    unsigned int encodedSqlStmtLen = (unsigned int)strlen(( unsigned char*)encodedSqlStmt);

    /**  Append */
    unsigned char *encodedtarget = (unsigned char*)malloc(encodedprefixTextLen +encodedprefixLen + encodedSqlStmtLen + encodedendfixLen);
    unsigned int encodedtargetLen = encodedprefixTextLen + encodedprefixLen + encodedSqlStmtLen + encodedendfixLen;

    /**  Append */
    strcpy(encodedtarget,encodedprefixText);
    strcat(encodedtarget, encodedprefix);
    strcat(encodedtarget, encodedSqlStmt);
    strcat(encodedtarget, encodedendfix);

    printf("\n\nSource: %s%s%s%s\n", encodedprefixText, encodedprefix, sqlStmt, encodedendfix);
    printf("\nEncode result :  %s\n\n",encodedtarget);

    /** result var*/

    unsigned char* userId = NULL;
    unsigned char* ip = NULL;


    int result = parseSqlStmt(
       encodedtarget,
       encodedtargetLen,
       &userId,
       &ip,
       (unsigned char*)START_END_SYMBOL,
       (unsigned char*)DELIMITER);

    /** Unit Test  */
   
    if(userId != NULL) {
        assert_string_equal(userId , TargetUserId);
    }
    else{
      printf("userId is NULL\n");
    }

    if(ip != NULL) {
       assert_string_equal(ip , TargetIp);
    }
     else{
      printf("ip is NULL\n");
    }

    

    if(userId != NULL) {
       free(userId);
    }
    if(ip != NULL) {
       free(ip);
    };


    free(encodedtarget);


}
void Test_parseSqlStmt_Target_At_Mid_TwoDelimiter(void **state)
{
   /** data*/
    unsigned char *TargetUserId = "ianmina0322@gmail.com";
    unsigned char *TargetIp = "200.221.99.3";
    unsigned char *sqlStmt = "ianmina0322@gmail.com,,200.221.99.3";

    /** Len*/
    unsigned int TargetUserIdLen = (unsigned int)strlen(( unsigned char*)TargetUserId);
    unsigned int TargetIpLen = (unsigned int)strlen(( unsigned char*)TargetIp);
    unsigned int sqlStmtLen = (unsigned int)strlen(( unsigned char*)sqlStmt);


    /** Text*/
    unsigned char *encodedprefixText= "UUUUUUUUUUUUUU I will be back online";
    unsigned char *encodedendfixText = "Haha I will be back Now";

    /** Text Len*/
    unsigned char *encodedprefix = "/*#^";
    unsigned char *encodedendfix = "^#*/";

    /** Encode*/
    unsigned char *encodedSqlStmt = base64Encode(sqlStmt, sqlStmtLen);

    unsigned int encodedprefixLen = (unsigned int)strlen(( unsigned char*)encodedprefix);
    unsigned int encodedendfixLen = (unsigned int)strlen(( unsigned char*)encodedendfix);
    unsigned int encodedprefixTextLen = (unsigned int)strlen(( unsigned char*)encodedprefixText);
    unsigned int encodedendfixTextLen = (unsigned int)strlen(( unsigned char*)encodedendfixText);
    unsigned int encodedSqlStmtLen = (unsigned int)strlen(( unsigned char*)encodedSqlStmt);

    /**  Append */
    unsigned char *encodedtarget = (unsigned char*)malloc(encodedprefixTextLen + encodedprefixLen + encodedSqlStmtLen + encodedendfixLen +encodedendfixTextLen ) ;
    unsigned int encodedtargetLen = encodedprefixTextLen + encodedprefixLen + encodedSqlStmtLen + encodedendfixLen +encodedendfixTextLen;

    /**  Append */
    strcpy(encodedtarget,encodedprefixText);
    strcat(encodedtarget, encodedprefix);
    strcat(encodedtarget, encodedSqlStmt);
    strcat(encodedtarget, encodedendfix);
    strcat(encodedtarget, encodedendfixText);

    printf("\n\nSource: %s%s%s%s%s\n", encodedprefixText, encodedprefix, sqlStmt, encodedendfix, encodedendfixText);
    printf("Encode result :  %s\n\n",encodedtarget);

    /** result var*/

    unsigned char* userId = NULL;
    unsigned char* ip = NULL;


    int result = parseSqlStmt(
       encodedtarget,
       encodedtargetLen,
       &userId,
       &ip,
       (unsigned char*)START_END_SYMBOL,
       (unsigned char*)DELIMITER);

    /** Unit Test  */
    if(userId != NULL) {
        assert_string_equal(userId , TargetUserId);
    }
    else{
      printf("userId is NULL\n");
    }
    
    if(ip != NULL) {
       assert_string_equal(ip , TargetIp);
    }
     else{
      printf("ip is NULL\n");
    }

   
    if(userId != NULL) {
       free(userId);
    }
    if(ip != NULL) {
       free(ip);
    }

    free(encodedtarget);

}
void Test_parseSqlStmt_Target_At_Mid(void **state)
{

    /** data*/
    unsigned char *TargetUserId = "ianmina0322@gmail.com";
    unsigned char *TargetIp = "200.221.99.3";
    unsigned char *sqlStmt = "ianmina0322@gmail.com,200.221.99.3";

    /** Len*/
    unsigned int TargetUserIdLen = (unsigned int)strlen(( unsigned char*)TargetUserId);
    unsigned int TargetIpLen = (unsigned int)strlen(( unsigned char*)TargetIp);
    unsigned int sqlStmtLen = (unsigned int)strlen(( unsigned char*)sqlStmt);


    /** Text*/
    unsigned char *encodedprefixText= "UUUUUUUUUUUUUU I will be back online";
    unsigned char *encodedendfixText = "Haha I will be back Now";

    /** Text Len*/
    unsigned char *encodedprefix = "/*#^";
    unsigned char *encodedendfix = "^#*/";

    /** Encode*/
    unsigned char *encodedSqlStmt = base64Encode(sqlStmt, sqlStmtLen);

    unsigned int encodedprefixLen = (unsigned int)strlen(( unsigned char*)encodedprefix);
    unsigned int encodedendfixLen = (unsigned int)strlen(( unsigned char*)encodedendfix);
    unsigned int encodedprefixTextLen = (unsigned int)strlen(( unsigned char*)encodedprefixText);
    unsigned int encodedendfixTextLen = (unsigned int)strlen(( unsigned char*)encodedendfixText);
    unsigned int encodedSqlStmtLen = (unsigned int)strlen(( unsigned char*)encodedSqlStmt);

    /**  Append */
    unsigned char *encodedtarget = (unsigned char*)malloc(encodedprefixTextLen + encodedprefixLen + encodedSqlStmtLen + encodedendfixLen +encodedendfixTextLen ) ;
    unsigned int encodedtargetLen = encodedprefixTextLen + encodedprefixLen + encodedSqlStmtLen + encodedendfixLen +encodedendfixTextLen;

    /**  Append */
    strcpy(encodedtarget,encodedprefixText);
    strcat(encodedtarget, encodedprefix);
    strcat(encodedtarget, encodedSqlStmt);
    strcat(encodedtarget, encodedendfix);
    strcat(encodedtarget, encodedendfixText);

    printf("\n\nSource: %s%s%s%s%s\n", encodedprefixText, encodedprefix, sqlStmt, encodedendfix, encodedendfixText);
    printf("Encode result :  %s\n\n",encodedtarget);

    /** result var*/

    unsigned char* userId = NULL;
    unsigned char* ip = NULL;


    int result = parseSqlStmt(
       encodedtarget,
       encodedtargetLen,
       &userId,
       &ip,
       (unsigned char*)START_END_SYMBOL,
       (unsigned char*)DELIMITER);

    /** Unit Test  */
    if(userId != NULL) {
        assert_string_equal(userId , TargetUserId);
    }
    else{
      printf("userId is NULL\n");
    }
    
    if(ip != NULL) {
       assert_string_equal(ip , TargetIp);
    }
     else{
      printf("ip is NULL\n");
    }

   
    if(userId != NULL) {
       free(userId);
    }
    if(ip != NULL) {
       free(ip);
    }

    free(encodedtarget);
}

void Test_parseSqlStmt_Multi_Target(void **state){


    /** data*/
    unsigned char *TargetUserId = "ianmina0322@gmail.com";
    unsigned char *TargetIp = "200.221.99.3";
    unsigned char *sqlStmt = "ianmina0322@gmail.com,200.221.99.3";

    /** Len*/
    unsigned int TargetUserIdLen = (unsigned int)strlen(( unsigned char*)TargetUserId);
    unsigned int TargetIpLen = (unsigned int)strlen(( unsigned char*)TargetIp);
    unsigned int sqlStmtLen = (unsigned int)strlen(( unsigned char*)sqlStmt);

    

    /** Text*/
    unsigned char *encodedprefixText= "UUUUUUUUUUUUUU I will be back online";
    unsigned char *encodedendfixText = "Haha I will be back Now";
    unsigned char *encodedprefix = "/*#^";
    unsigned char *encodedendfix = "^#*/";

    /** Text len*/
    unsigned int encodedprefixLen = (unsigned int)strlen(( unsigned char*)encodedprefix);
    unsigned int encodedendfixLen = (unsigned int)strlen(( unsigned char*)encodedendfix);
    unsigned int encodedprefixTextLen = (unsigned int)strlen(( unsigned char*)encodedprefixText);
    unsigned int encodedendfixTextLen = (unsigned int)strlen(( unsigned char*)encodedendfixText);


    /** Encoding first*/
    unsigned char *encodedSqlStmt = base64Encode(sqlStmt, sqlStmtLen);

    unsigned int encodedSqlStmtLen = (unsigned int)strlen(( unsigned char*)encodedSqlStmt);


    /** Encoding Second*/


     /** not Include Data*/
    unsigned char *NotIncludeUserId = "iskdnskx@gmail.com";
    unsigned char *NotIncludeIp = "199.33.22.1";
    unsigned char *NotIncludesqlStmt = "iskdnskx@gmail.com,199.33.22.1";

    /** Not Include data Len*/
    unsigned int NotIncludeUserIdLen = (unsigned int)strlen(( unsigned char*)NotIncludeUserId);
    unsigned int NotIncludeIpLen = (unsigned int)strlen(( unsigned char*)NotIncludeIp);
    unsigned int NotIncludesqlStmtLen = (unsigned int)strlen(( unsigned char*)NotIncludesqlStmt);

    /* Not Include Encoding*/
    unsigned char *NotIncludeencodedSqlStmt = base64Encode(NotIncludesqlStmt, NotIncludesqlStmtLen);

    unsigned int NotIncludeencodedSqlStmtLen = (unsigned int)strlen(( unsigned char*)NotIncludeencodedSqlStmt);


    /**  Append */
    unsigned char *encodedtarget = (unsigned char*)malloc(encodedprefixTextLen + encodedprefixLen + encodedSqlStmtLen + encodedendfixLen +encodedendfixTextLen + encodedprefixLen + NotIncludesqlStmtLen + encodedendfixLen);
    unsigned int encodedtargetLen = encodedprefixTextLen + encodedprefixLen + encodedSqlStmtLen + encodedendfixLen +encodedendfixTextLen + encodedprefixLen + NotIncludesqlStmtLen + encodedendfixLen;



    strcpy(encodedtarget,encodedprefixText);
    strcat(encodedtarget, encodedprefix);
    strcat(encodedtarget, encodedSqlStmt);
    strcat(encodedtarget, encodedendfix);
    strcat(encodedtarget, encodedendfixText);

    strcat(encodedtarget, encodedprefix);
    strcat(encodedtarget, NotIncludeencodedSqlStmt);
    strcat(encodedtarget , encodedendfix);

    printf("\n\nSource: %s%s%s%s%s%s%s%s\n", encodedprefixText, encodedprefix, sqlStmt, encodedendfix, encodedendfixText, encodedprefix, NotIncludesqlStmt, encodedendfix);
    printf("Encode result :  %s\n\n",encodedtarget);

    /** result var*/

    unsigned char* userId = NULL;
    unsigned char* ip = NULL;


    int result = parseSqlStmt(
       encodedtarget,
       encodedtargetLen,
       &userId,
       &ip,
       (unsigned char*)START_END_SYMBOL,
       (unsigned char*)DELIMITER);

    /** Unit Test  */
   
    if(userId != NULL) {
        assert_string_equal(userId , TargetUserId);
    }
    else{
      printf("userId is NULL\n");
    }
    
    if(ip != NULL) {
       assert_string_equal(ip , TargetIp);
    }
     else{
      printf("ip is NULL\n");
    }


    if(userId != NULL) {
       free(userId);
    }
    if(ip != NULL) {
       free(ip);
    }


    free(encodedtarget);
}