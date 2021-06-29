#include "DocumentRepository.h"



void DocumentRepository::save(const DocumentEntry& entry) 
 {
     bool is_found = false;
     for( DocumentEntry& elem : this->documents)
     {
         if(elem.getUrl() == entry.getUrl() && elem.getTitle() == entry.getTitle())  
         {
             elem = entry;
             is_found = true;
             break;
         }
        
     }
    if(!is_found)
    {
        documents.push_back(entry);
    }
 }