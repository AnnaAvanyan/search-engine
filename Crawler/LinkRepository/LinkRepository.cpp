#include "LinkRepository.h"
#include <vector>
#include <pqxx/pqxx>
#include <string>
#include <string.h>
#include <iostream>
 #include "pqxx/compiler-public.hxx"
 #include "pqxx/compiler-internal-pre.hxx"
 
 #include "pqxx/connection_base.hxx"
 #include "pqxx/transaction.hxx"
 

LinkRepository::LinkRepository() = default;

 LinkRepository::LinkRepository (const PostgreSqlConnector& obj) : LinkRepConn{obj}
 {
     
 }

 std::vector<LinkEntry>  LinkRepository::getAll()
 {
    //PGconn *PQsetdb(char *pghost, char *pgport, char *pgoptions, char *pgtty, char *dbName);


     return this->source;
 }

 std::vector<LinkEntry>  LinkRepository::getBy(std::string domain, LinkStatus status, int count)
 {
     std::vector<LinkEntry> result;
     
     for( LinkEntry elem : this->source)
     {
         if(elem.getStatus() == status && elem.getDomain() == domain )  
         {
            result.push_back(elem);            
           
         // std::string instrument="INSERT INTO webdb.links(url,domain,status,update_time) VALUES ( '"+instnum+"', '"+insttype+"', '"+maker+"', '"+year+"')";
         }
         if(result.size()== count)
        {
            break;
        }
     }
     return result;
 }

 std::optional<LinkEntry> LinkRepository::getByUrl(const std::string& url)
 {
     for( LinkEntry& elem : this->source)
     {
         if(elem.getUrl() == url)
        {
            return std::make_optional(elem); 
        }
     }
    return {};
 }

  void LinkRepository::save(const LinkEntry& entry)
 {
     //PGconn *PQsetdbLogin(const char *pghost,  const char *pgport, const char *pgoptions, const char *pgtty,const char *dbName, const char *login,const char *pwd);
    //PostgreSqlConnector connector;
    const std::string dbstring = "dbname = firstdb user = annaavanyan password=pwdfordb hostaddr=127.0.0.1 port=5432";
    pqxx::connection C( "dbname = firstdb user = annaavanyan password=pwdfordb hostaddr=127.0.0.1 port=5432");
    pqxx::work l_work(C);

    std::string host="localhost" ;
    unsigned int port= 5432 ;
    std::string dbname= "firstdb";
    std::string password = "pwdfordb";    
    

     bool is_found = false;
     for( auto& elem : this->source)
     {
         if(elem.getUrl() == entry.getUrl() )  
         {
             elem = entry;
             is_found = true;
             break;
         }
        
     }

    if(!is_found)
    {
        source.push_back(entry);
        
        /* Create a transactional object. */
		

    }
    std::string sql1 = "insert into public.diagnosis5 ( patient_id, visit_number ) VALUES('b1 ','n2');";
    //pqxx::work W(C);
 
		/* Execute SQL query */
		//W.exec(sql1);
		//W.commit();
        l_work.exec(sql1);
        l_work.commit();
    
 }

int LinkRepository::getCount() 
{
    return source.size();
}
