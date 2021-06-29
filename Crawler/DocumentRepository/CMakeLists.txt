project(DocumentRepository)

add_library(
    DocumentRepository SHARED

    DocumentEntry.h
    DocumentEntry.cpp

    DocumentRepository.h
    DocumentRepository.cpp
)

target_link_libraries(DocumentRepository)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
