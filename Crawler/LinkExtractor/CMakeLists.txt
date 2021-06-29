project(LinkExtractor)

add_library(
    LinkExtractor SHARED

    LinkExtractor.h
    LinkExtractor.cpp

)

target_link_libraries(LinkExtractor)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
