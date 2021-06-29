#include "LoadResult.h"
#include <iostream>
#include <memory>


    LoadResult::LoadResult(std::shared_ptr<std::string> body, long status) : body{body}, status{status}
    {
 
    }

    std::shared_ptr<std::string> LoadResult::getBody()
    {
        return body;
    }
    long  LoadResult::getStatus()
    {
       return status;
    }

   
    
    