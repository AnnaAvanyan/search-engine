#include <string>
#include "DocumentInfo.h"

DocumentInfo::DocumentInfo() = default;

DocumentInfo::DocumentInfo(std::string title, std::string description, std::string text): 
                           title{title}, description{description},text{text}
{
}

std::string DocumentInfo::getTitle()
{
    return title;
}
std::string DocumentInfo::getDesctription()
{
    return description;
}
std::string DocumentInfo::getText()
{
    return text;
}

