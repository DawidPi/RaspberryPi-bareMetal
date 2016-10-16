cmake_minimum_required(VERSION 3.6)
project(Common)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

CONFIGURE_QT5()

set(SOURCES
        FunctionsTreeManager.cpp
        ConnectionHandler.cpp ConnectionHandler.hpp SettingsManager.cpp SettingsManager.hpp)

add_library(${PROJECT_NAME} ${SOURCES})
qt5_use_modules(${PROJECT_NAME} Widgets Core SerialPort)
target_link_libraries(${PROJECT_NAME})