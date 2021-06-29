#include "../HtmlDocument/HtmlElement.h"
#include "gumbo.h"

   HtmlElement::HtmlElement(GumboNode* node): HtmlNode{node}
    {
        
    }
   
    bool HtmlElement::isElement() 
    {
        if(node->type != GUMBO_NODE_ELEMENT)
        {
            return false;
        }
        return true;
    }
    bool HtmlElement::isTagA() const
    {
          if(node->v.element.tag != GUMBO_TAG_A)
            return false;
        return true;
    }
    std::string HtmlElement::getAttribute (const std::string& name)
    {
        GumboAttribute* attribute = gumbo_get_attribute(&node->v.element.attributes, name.c_str());
        if(!attribute)
            return "";
        return std::string{attribute->value};
    }
   
    std::string HtmlElement::getInnerText()
 {
   
      GumboVector* children = &node->v.element.children;
      std::string result = "";
      for(unsigned int i=0; i< children->length; ++i)
      {
          result = "";
          auto child = static_cast<GumboNode*>(children->data[i]);
          if(child->type != GUMBO_NODE_TEXT)
          {
              return "";
          }
        
         result.append(child->v.text.text);
      }
      return result;
 }     

  bool  HtmlElement::isTagsforText()
  {
      auto tag = node->v.element.tag;
      if(tag == GUMBO_TAG_STYLE || tag == GUMBO_TAG_SCRIPT)
      {
            return false;
      }
      
      return true;
  }
  bool HtmlElement::isTagTitle()
  {
      auto tag = node->v.element.tag;
      if(tag == GUMBO_TAG_TITLE)
      {
          return true;
      }
      
    return false;
  }

  bool HtmlElement::isTagforDesctiption()
  {
       auto tag = node->v.element.tag;
      if(tag == GUMBO_TAG_META)
      {
          return true;
      }
      
    return false;
  }
bool HtmlElement::isTagInput()
{
    auto tag = node->v.element.tag;
    
  if(tag  == GUMBO_TAG_INPUT)
     {
         return true;
     }
     return false;

}
