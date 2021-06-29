project(WebRepository)

add_library(
    WebRepository SHARED

    WebRepository.h
    WebRepository.cpp

    WebSite.h
    WebSite.cpp

)

target_link_libraries(WebRepository)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
