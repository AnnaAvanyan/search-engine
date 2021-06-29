#include "PageLoader/PageLoader.h"
#include "HtmlDocument/HtmlDocument.h"
#include "LinkRepository/LinkRepository.h"
#include "LinkExtractor/LinkExtractor.h"
#include "DocumentExtractor/DocumentExtractor.h"
#include "WebRepository/WebRepository.h"
#include "LinkRepository/LinkStatus.h"
#include "DocumentRepository/DocumentRepository.h"
#include "PostgreSqlConnector/PostgreSqlConnector.h"
#include <iostream>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>


int main()
{
/*
    const char *conninfo;
    PGconn     *conn;
    PGresult *res;
 */


/*
PQexecSubmits 
a command to the server and waits for the result.

PGresult *PQexec(PGconn *conn, const char *command);
*/
/*
    res = PQexec(conn, "BEGIN");
    if(PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        std::cout<<"BEGIN command failed"<<PQerrorMessage(conn)<<std::endl;
        PQclear(res);
        PQfinish(conn);
        exit(1);
    }

    std::cout<<"HostPort : "<<PQport(conn)<<std::endl;
    std::cout<<"ServerPath : "<<PQhost(conn)<<std::endl;
    std::cout<<"Database : "<<PQdb(conn)<<std::endl;
    std::cout<<"Login ID : "<<PQuser(conn)<<std::endl;
    std::cout<<"Proc PID : "<<PQbackendPID(conn)<<std::endl;
    
    
*/

    //PostgreSqlConnector psql;
    //psql.Connection_Ok(); // if !Connection_Ok function will aut.. finish



    
    //std::cout<<"IM HERE"<<std::endl; 
    WebRepository webrep;
    webrep.save(WebSite("stackoverflow.com", "https://stackoverflow.com/", time(nullptr)));
    //webrep.save(WebSite("rau.am", "https://rau.am/", time(nullptr)));

    //webrep.save(WebSite("txt", " txt", time(nullptr)));
    LinkRepository linkrep;
    PageLoader pageLoader;
    LinkExtractor linkExtractor;
    DocumentExtractor docExtractor;
    DocumentRepository docrep;
    for(auto& website : webrep.getAll())
    {
       linkrep.save(LinkEntry(website.getHomepage(), website.getDomain(),LinkStatus::WAITING, time(nullptr)));
       //std::cout<<"IM HERE"<<std::endl;
       while(true)
       {
        //std::cout<<"IM HERE"<<std::endl;
           std::vector<LinkEntry> links = linkrep.getBy(website.getDomain(),LinkStatus::WAITING,10);

           if(links.empty())
           {
               break;
           }
        //std::cout<<"IM HERE"<<std::endl;
           for(auto& link: links)
           {
              // std::cout<<"IM HERE"<<std::endl;
               LoadResult loadResult = pageLoader.load(link.getUrl());
               if(loadResult.getStatus()<200 || loadResult.getStatus()>300)
                 {
                    std::cout << "Status is wrong"<<"\n";
                    linkrep.save(LinkEntry(link.getUrl(), link.getDomain(), LinkStatus::ERROR, time(nullptr)));
                    continue;
                    
                 }

                 const std::string html = *loadResult.getBody().get();

                 HtmlDocument doc(html);
                 doc.parse(); 
                 
                 auto extractedLinks = linkExtractor.extract(doc);
                 for(auto& newLink : extractedLinks)
                 {
                    if(linkrep.getByUrl(newLink).has_value())
                    {
                        continue;
                    }
                    
                    linkrep.save(LinkEntry(newLink, website.getDomain(),LinkStatus::WAITING,time(nullptr)));
                 }
                 
                   auto docInfo =  docExtractor.extractInfo(doc);

                   docrep.save(DocumentEntry(link.getUrl(),docInfo.getTitle(),docInfo.getDesctription(),docInfo.getText(),time(nullptr)));

                   linkrep.save(LinkEntry(link.getUrl(), link.getDomain(), LinkStatus::SUCCESS,time(nullptr) ));

                   std::cout<< "links: "<<linkrep.getCount();
           }
       }

       webrep.save(WebSite(website.getDomain(), website.getHomepage(),time(nullptr)));
    }

}