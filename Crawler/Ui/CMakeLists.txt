project(Ui)

add_library(
    Ui SHARED

    Ui.h
    Ui.cpp

)

target_link_libraries(Ui -lcurl)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")