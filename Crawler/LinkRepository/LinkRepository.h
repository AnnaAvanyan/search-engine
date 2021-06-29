#ifndef  LINK_REPOSITORY
#define  LINK_REPOSITORY

#include "../PostgreSqlConnector/PostgreSqlConnector.h"
#include "LinkEntry.h"
#include <vector>

#include <optional>

class LinkRepository
{
private:
    PostgreSqlConnector LinkRepConn;
    std::vector<LinkEntry> source;

public:

    //Constructor
    LinkRepository (const PostgreSqlConnector& obj);    
    LinkRepository();

    // push to vector and return all links
    std::vector<LinkEntry>  getAll() ;

    // return links if they exists in source
    std::vector<LinkEntry>  getBy(std::string domain, LinkStatus status, int count) ;
    
    // return link if it exists in source
    std::optional<LinkEntry> getByUrl(const std::string& url);
   
    //save link to the source
    void save (const LinkEntry& entry); 

    int getCount() ;

};

#endif  
