#ifndef LOAD_RESULT
#define LOAD_RESULT
#include <memory>
#include <string>
#include <tr1/memory>



class LoadResult{
    private: 
    /**
     *  STORES THE RESPONSE BODY
     */
    std::shared_ptr<std::string> body;
    /**
     *  STORES THE RESPONSE STATUS
     */
    long status;

    public:
    //constructor
    LoadResult() = default;
   LoadResult(std::shared_ptr<std::string> body, long status);
   
   std::shared_ptr<std::string> getBody();
   
   long getStatus();

};




#endif
