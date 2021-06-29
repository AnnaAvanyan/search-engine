#ifndef  DOCUMENT_EXTRACTOR
#define  DOCUMENT_EXTRACTOR
#include "../HtmlDocument/HtmlDocument.h"

#include "DocumentInfo.h"

class DocumentExtractor
{
public:
    DocumentInfo extractInfo(HtmlDocument& doc);

};





#endif 
