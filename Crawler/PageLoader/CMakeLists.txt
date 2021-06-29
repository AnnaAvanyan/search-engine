project(PageLoader)

add_library(
    PageLoader SHARED

    LoadResult.h
    LoadResult.cpp

    PageLoader.h
    PageLoader.cpp

)

target_link_libraries(PageLoader -lcurl)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
