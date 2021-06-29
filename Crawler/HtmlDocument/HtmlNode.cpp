#include "../HtmlDocument/HtmlNode.h"
//#include <mysql/jdbc.h>

   HtmlNode::HtmlNode(GumboNode* node) : node{node}
   {}
   HtmlNode::HtmlNode() = default;
   bool HtmlNode::isElement()
   {
       if(node->type != GUMBO_NODE_ELEMENT)
            return false;
        return true;
   }
