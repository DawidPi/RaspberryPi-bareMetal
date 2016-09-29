macro(CONFIGURE_QT5)
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ";" ${QT5_PACKAGE_DIR})

    find_package(Qt5Widgets REQUIRED)

    add_definitions(-DQT_NO_KEYWORDS)
endmacro()