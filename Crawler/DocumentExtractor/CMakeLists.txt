project(DocumentExtractor)

add_library(
    DocumentExtractor SHARED

    DocumentInfo.h
    DocumentInfo.cpp

    DocumentExtractor.h
    DocumentExtractor.cpp
)

target_link_libraries(DocumentExtractor)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
