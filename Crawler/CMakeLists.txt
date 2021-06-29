cmake_minimum_required(VERSION 3.16)
project(MySearchEngine_ VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)

include_directories("DocumentExtractor")
include_directories("DocumentRepository")
include_directories("LinkExtractor")
include_directories("LinkRepository")
include_directories("HtmlDocument")
include_directories("WebRepository")

add_executable(${PROJECT_NAME} CrawlerMain.cpp)

add_subdirectory(DocumentExtractor)
add_subdirectory(DocumentRepository)
add_subdirectory(LinkExtractor)
add_subdirectory(LinkRepository)
add_subdirectory(PageLoader)
add_subdirectory(HtmlDocument)
add_subdirectory(WebRepository)


set_target_properties(DocumentExtractor PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/DocumentExtractor/libDocumentExtractor.so"
        )

set_target_properties(DocumentRepository PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/DocumentRepository/libDocumentRepository.so"
        )

set_target_properties(LinkExtractor PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/LinkExtractor/libLinkExtractor.so"
        )

set_target_properties(LinkRepository PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/LinkRepository/libLinkRepository.so"
        )

set_target_properties(PageLoader PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/PageLoader/libPageLoader.so"
        )

set_target_properties(HtmlDocument PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/HtmlDocument/libHtmlDocument.so"
    )

set_target_properties(WebRepository PROPERTIES
        IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/WebRepository/libWebRepository.so"
    )

target_link_libraries(${PROJECT_NAME} DocumentExtractor DocumentRepository LinkExtractor LinkRepository PageLoader  HtmlDocument WebRepository)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")

