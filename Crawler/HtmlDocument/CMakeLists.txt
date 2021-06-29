project(HtmlDocument)

add_library(
    HtmlDocument SHARED

    HtmlDocument.h
    HtmlDocument.cpp

    HtmlElement.h
    HtmlElement.cpp

    HtmlNode.h
    HtmlNode.cpp
)

target_link_libraries(HtmlDocument -lgumbo)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
