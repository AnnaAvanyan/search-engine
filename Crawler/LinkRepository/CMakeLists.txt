project(LinkRepository)

add_library(
    LinkRepository SHARED

    LinkEntry.h
    LinkEntry.cpp

    LinkRepository.h
    LinkRepository.cpp

    LinkStatus.h
)

target_link_libraries(LinkRepository -lpqxx)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
	