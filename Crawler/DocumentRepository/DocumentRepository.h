#ifndef  DOCUMENT_REPOSITORY
#define  DOCUMENT_REPOSITORY
#include "DocumentEntry.h"
#include <vector>

class DocumentRepository 
{
private:
    std::vector<DocumentEntry> documents;

public:

    void save(const DocumentEntry& entry) ;
         

};

#endif
