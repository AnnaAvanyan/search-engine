#ifndef  HTML_ELEMENT_H
#define  HTML_ELEMENT_H
#include "HtmlNode.h"
#include <string>

class HtmlElement:HtmlNode
{

public:
    HtmlElement(GumboNode* node);
    
    bool isElement() override;

    //check node element's tag
    bool isTagA() const;
    
    std::string getAttribute (const std::string& name);
    
    std::string getInnerText();
    bool  isTagsforText();
    bool isTagTitle();
    bool isTagforDesctiption();
    bool isTagInput();


};







#endif 
