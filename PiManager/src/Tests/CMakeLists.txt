cmake_minimum_required(VERSION 3.6)
project(UnitTests)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(${GTEST_DIR} test/gtest)
enable_testing()

include_directories(${GTEST_DIR}/include)

set(SOURCES
        test_main.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCES})
add_dependencies(${PROJECT_NAME} Widgets Common PiManagerApp)
target_link_libraries(${PROJECT_NAME} gtest gtest_main)
target_link_libraries(${PROJECT_NAME} Widgets Common)