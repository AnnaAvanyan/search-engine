#include "LinkEntry.h"
#include <chrono>


LinkEntry::LinkEntry() : url{""}, domain{""}, status{} , updateTime{}
{}

LinkEntry::LinkEntry(std::string url, std::string domain, LinkStatus status, time_t updateTime) :
                     url{url}, domain{domain}, status{status}, updateTime{updateTime} {}
 
  // getter functions
     std::string LinkEntry::getUrl() const
     {
         return url;
     }
     std::string LinkEntry::getDomain() 
     {
         return domain;
     }

     LinkStatus LinkEntry::getStatus()
     {
         return status;
     }

    time_t LinkEntry::getUpdateTime()
    {
        return updateTime;
    }

     /*time_t LinkEntry::getlastLoadTime()
    {
        return lastLoadTime
    }
    */