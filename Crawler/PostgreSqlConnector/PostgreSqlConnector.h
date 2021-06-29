#ifndef POSTGRE_SQL_CONNECTOR
#define POSTGRE_SQL_CONNECTOR

#include <stdlib.h>
#include <postgresql/libpq-fe.h>
#include <string>

class PostgreSqlConnector 
{
private:
    
    char *conninfo;
    PGconn   *conn;

   /* std::string HostPort;
    std::string ServerPath;
    std::string Database;
    std::string LoginID;
    unsigned int ProcPID;
    */

public:
    PostgreSqlConnector ();
    PostgreSqlConnector (char *conninfo, PGconn *conn);

   // PostgreSqlConnector(const std::string& HostPort,  const std::string& ServerPath, const std::string& Database, 
     //                   const std::string& LoginID, unsigned int ProcPID);
    

    std::string getHostPort() const;
    std::string getServerPath() const;
    std::string getDatabase() const;
    std::string getLoginID() const;
    unsigned int getProcPID() const;

    /* Check to see that the backend connection was successfully made*/
    bool Connection_Ok();
   

    
};


#endif
