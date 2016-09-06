cmake_minimum_required(VERSION 3.6)
include(../qt_macros.cmake)
project(PiManagerApp)

set(AppName PiManager)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

CONFIGURE_QT5()

set(SOURCES
        main.cpp
        )

add_executable(${AppName} ${SOURCES})
target_link_libraries(${AppName} Qt5::Widgets)