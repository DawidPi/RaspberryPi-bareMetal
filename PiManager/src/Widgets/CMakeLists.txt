cmake_minimum_required(VERSION 3.6)
project(Widgets)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

CONFIGURE_QT5()

set(SOURCES
        PiManagerWindow.cpp
        PiManagerWindow.hpp
        ControlButtons.cpp
        ControlButtons.hpp
        FunctionsWidget.cpp
        FunctionsWidget.hpp
        LogsWidget.cpp
        LogsWidget.hpp)

include_directories(../)

add_library(${PROJECT_NAME} ${SOURCES})
add_dependencies(${PROJECT_NAME} Common)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Common)