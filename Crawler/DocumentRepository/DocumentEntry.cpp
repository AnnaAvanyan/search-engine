#include "DocumentEntry.h"
#include <string>


DocumentEntry::DocumentEntry(std::string url,std::string title, std::string desctiption, std::string text,std::time_t updateTime):
                            url{url}, title{title}, desctiption{desctiption},text{text}, updateTime{updateTime}
{}

DocumentEntry::DocumentEntry() = default;

std::string DocumentEntry::getUrl() const
{
    return url;
}

 std::string DocumentEntry::getTitle() const
{
    return title;
}
