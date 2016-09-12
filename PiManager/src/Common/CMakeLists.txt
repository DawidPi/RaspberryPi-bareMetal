cmake_minimum_required(VERSION 3.6)
project(Common)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

CONFIGURE_QT5()

set(SOURCES
        FunctionRepresentation.cpp
        )

add_library(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)