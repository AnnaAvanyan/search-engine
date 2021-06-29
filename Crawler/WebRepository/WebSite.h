#ifndef  WEB_SITE
#define  WEB_SITE

#include <string>
#include <ctime>

class WebSite
{
private:
    std::string domain;
    std::string homepage;
    std::time_t lastcrawlTime;

public:

    WebSite(std::string domain,std::string homepage,std::time_t lastcrawlTime );

    std::string getDomain() const;
    std::string getHomepage() const;
    std::time_t getLascrawlTime() const;

    
};



#endif
