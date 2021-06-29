#ifndef PAGE_LOADER
#define PAGE_LOADER
#include "LoadResult.h"


class  PageLoader{

    public: 
    // load URL and return body
   LoadResult load(const std::string& url);

};




#endif 
