cmake_minimum_required(VERSION 3.6)
project(PiManager)

include(options.cmake)
include(qt_macros.cmake)

add_subdirectory(Widgets)
add_subdirectory(Common)
add_subdirectory(Application)
add_subdirectory(Tests)
