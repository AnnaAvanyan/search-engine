#include "PostgreSqlConnector.h"
#include <iostream>

PostgreSqlConnector::PostgreSqlConnector ()
{
    conninfo = "dbname = firstdb";
    conn = PQconnectdb(conninfo);
}


PostgreSqlConnector::PostgreSqlConnector (char *conninfo, PGconn *conn) 
{
     conninfo = "dbname = firstdb";
     conn = PQconnectdb(conninfo);

}



 /*   
 PGconn *PQsetdb(char *pghost,                char *pgport,                char *pgoptions,                char *pgtty,                char *dbName);
PostgreSqlConnector::PostgreSqlConnector(const std::string& HostPort,  const std::string& ServerPath, const std::string& Database, 
                        const std::string& LoginID, unsigned int ProcPID)
    : HostPort{HostPort}, ServerPath{ServerPath}, Database{Database}, LoginID{LoginID}, ProcPID{ProcPID}
{
}
    */
std::string PostgreSqlConnector::getHostPort() const
{
    return PQport(conn);
}

std::string PostgreSqlConnector::getServerPath() const
{
    return PQhost(conn);
}

std::string PostgreSqlConnector::getDatabase() const
{
    return PQdb(conn);
}

std::string PostgreSqlConnector::getLoginID() const
{
    return PQuser(conn);
}

unsigned int PostgreSqlConnector::getProcPID() const
{
    return PQbackendPID(conn);
}

bool PostgreSqlConnector::Connection_Ok()
{
    
    if (PQstatus(conn) != CONNECTION_OK)
    {
        std::cout<< "Connection to database failed"<<PQerrorMessage(conn)<<std::endl;
        PQfinish(conn);
        exit(1);
    }

    return true;
}

