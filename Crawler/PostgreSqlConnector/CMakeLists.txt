project(PostgreSqlConnector)

add_library(
    PostgreSqlConnector SHARED

    PostgreSqlConnector.h
    PostgreSqlConnector.cpp

)

target_link_libraries(PostgreSqlConnector -lpq)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
