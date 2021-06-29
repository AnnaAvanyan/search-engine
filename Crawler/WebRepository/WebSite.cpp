#include "WebSite.h"


WebSite::WebSite(std::string domain,std::string homepage,std::time_t lastcrawlTime ):
                 domain{domain}, homepage{homepage}, lastcrawlTime{lastcrawlTime}
{}

    std::string WebSite::getDomain()  const
    {
        return domain;
    }
    std::string WebSite::getHomepage()  const
    {
        return homepage;
    }
    std::time_t WebSite::getLascrawlTime() const
    {
        return lastcrawlTime;
    }
