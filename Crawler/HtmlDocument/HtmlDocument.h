#ifndef  HTML_DOCUMENT
#define  HTML_DOCUMENT

#include <string>
#include <functional>
#include "HtmlElement.h"
#include "gumbo.h"


class HtmlDocument
{
private:
    GumboNode* node;
    GumboOutput* output;
    std::string html; 
    void visitElement(GumboNode* node, std::function<void(HtmlElement)> visitor) const;
  
public:
    HtmlDocument(const std::string& html);
    bool parse();
    void visitElements(std::function<void(HtmlElement)> visitor) const;
    ~HtmlDocument();

};







#endif 
