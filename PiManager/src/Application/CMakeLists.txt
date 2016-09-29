cmake_minimum_required(VERSION 3.6)
include(../qt_macros.cmake)
project(PiManagerApp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

CONFIGURE_QT5()
include_directories("../")

set(SOURCES
        main.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCES})
add_dependencies(${PROJECT_NAME} Common Widgets)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Common Widgets)
