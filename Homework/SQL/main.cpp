#include <cstdio>
#include <iostream>
#include <cstdlib>

#include "sqlite3.h"

static int callback(void * NotUsed, int argc, char ** argv, char** azColName)
{
    int i;
    for(i = 0; i < argc; i++)
        printf("%s = %s\n", azColName[i], argv[i]? argv[i] : "NULL");

    printf("\n");

    return 0;
}
int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *zErrMsg = 0;

   char* sqlApartments;
   char* sqlBuildings;
   char* sqlTenants;
   char* sqlComplexes;
   char* sqlAptTenants;
   char* sqlRequests;
   char* sql;

   int rc;

   rc = sqlite3_open("test.db", &db);

   if( rc ){
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      exit(0);
   }else{
      fprintf(stderr, "Opened database successfully\n");
   }

   sqlApartments = "CREATE TABLE APART("\
                   "APTID INT PRIMARY KEY NOT NULL," \
                   "UNITNUMBER VARCHAR," \
                   "BUILDINGID INT);";

   sqlBuildings = "CREATE TABLE BUILD("\
                  "BUILDINGID INT PRIMARY KEY NOT NULL," \
                  "COMPLEXID INT," \
                  "BUILDINGNAME VARCHAR,"
                  "ADDRESS VARCHAR);";

   sqlTenants = "CREATE TABLE TENAN("\
                "TENANTID INT PRIMARY KEY NOT NULL," \
                "TENANTNAME VARCHAR);";

   sqlComplexes = "CREATE TABLE COMPL("\
                  "COMPLEXID INT PRIMARY KEY NOT NULL, " \
                  "COMPLEXNAME VARCHAR);";

   sqlAptTenants = "CREATE TABLE APTT("\
                   "APTID INT PRIMARY KEY NOT NULL, " \
                   "TENANTID INT);";

    sqlRequests = "CREATE TABLE REQUE("\
                  "REQUESTID PRIMARY KEY NOT NULL," \
                  "STATUS VARCHAR, "
                  "APTID INT,"
                  "DESCRIPTION VARCHAR);";

    /* Create SQL statement */
   sql = "INSERT INTO APART(APTID, UNITNUMBER, BUILDINGID) "  \
         "VALUES (1, '1A', 100 ); " \
         "INSERT INTO APART(APTID, UNITNUMBER, BUILDINGID) "  \
         "VALUES (2, '2A', 200 ); " \
         "INSERT INTO APART(APTID, UNITNUMBER, BUILDINGID) "  \
         "VALUES (3, '3A', 300 ); " \
         "INSERT INTO BUILD(BUILDINGID, COMPLEXID, BUILDINGNAME, ADDRESS) "  \
         "VALUES (100, 1, 'BUILDING100', '1 LONG RD' ); " \
         "INSERT INTO BUILD(BUILDINGID, COMPLEXID, BUILDINGNAME, ADDRESS) "  \
         "VALUES (200, 2, 'BUILDING200', '2 LONG RD' ); " \
         "INSERT INTO BUILD(BUILDINGID, COMPLEXID, BUILDINGNAME, ADDRESS) "  \
         "VALUES (300, 3, 'BUILDING300', '3 LONG RD' ); " \

         "INSERT INTO TENAN(TENANTID,TENANTNAME) "  \
         "VALUES (1, 'X'); "     \
         "INSERT INTO TENAN (TENANTID,TENANTNAME) "  \
         "VALUES (2, 'Y'); "
         "INSERT INTO TENAN (TENANTID,TENANTNAME) "  \
         "VALUES (3, 'Z'); "     \
         "INSERT INTO COMPL (COMPLEXID, COMPLEXNAME) "  \
         "VALUES (1, 'A'); "     \
         "INSERT INTO COMPL (COMPLEXID, COMPLEXNAME) "  \
         "VALUES (2, 'B'); "     \
         "INSERT INTO COMPL (COMPLEXID, COMPLEXNAME) "  \
         "VALUES (3, 'C'); " \


         "INSERT INTO APTT (APTID,TENANTID) "  \
         "VALUES (100, 1); "
         "INSERT INTO APTT (APTID, TENANTID) "  \
         "VALUES (200, 1); "
         "INSERT INTO APTT (APTID, TENANTID) "  \
         "VALUES (300, 2); "

         "INSERT INTO APTT (APTID, TENANTID) "  \
         "VALUES (400, 2); "

         "INSERT INTO APTT (APTID, TENANTID) "  \
         "VALUES (500, 3); "


         "INSERT INTO REQUE(REQUESTID,STATUS,APTID,DESCRIPTION) "  \
         "VALUES (1, 'OPEN', 100, 'TENANTS'); "  \

         "INSERT INTO REQUE(REQUESTID,STATUS,APTID,DESCRIPTION) "  \
         "VALUES (2, 'OPEN', 200, 'TENANTS'); "  \

         "INSERT INTO REQUE(REQUESTID,STATUS,APTID,DESCRIPTION) "  \
         "VALUES (3, 'OPEN', 300, 'TENANTS'); "  \

         "INSERT INTO REQUE(REQUESTID,STATUS,APTID,DESCRIPTION) "  \
         "VALUES (4, 'CLOSED', 400, 'NO TENANTS'); "  \

         "INSERT INTO REQUE(REQUESTID,STATUS,APTID,DESCRIPTION) "  \
         "VALUES (5, 'CLOSED', 500, 'NO TENANTS'); ";

         char* sql1 = "select tenantid from aptt group by tenantid having count(*) > 1;";
         char* sql2 = "select aptid from reque where status = 'OPEN';";

    rc = sqlite3_exec(db, sqlApartments, callback, 0, &zErrMsg);
    rc = sqlite3_exec(db, sqlBuildings, callback, 0, &zErrMsg);
    rc = sqlite3_exec(db, sqlTenants, callback, 0, &zErrMsg);
    rc = sqlite3_exec(db, sqlComplexes, callback, 0, &zErrMsg);
    rc = sqlite3_exec(db, sqlAptTenants, callback, 0, &zErrMsg);
    rc = sqlite3_exec(db, sqlRequests, callback, 0, &zErrMsg);
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    rc = sqlite3_exec(db, sql1, callback, 0, &zErrMsg);
    rc = sqlite3_exec(db, sql2, callback, 0, &zErrMsg);

   sqlite3_close(db);
}




