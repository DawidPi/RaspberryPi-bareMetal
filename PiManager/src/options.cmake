set(QT5_PACKAGE_DIR "" CACHE FILEPATH "path to the place, where package to the QT5_Dir exists")

if (QT5_PACKAGE_DIR STREQUAL "")
    message(FATAL_ERROR "QT5_PACKAGE_DIR empty: Please specify QT5_PACKAGE_DIR path")
else ()
    file(GLOB QT_DLLS QT5_PACKAGE_DIR "*.dll")
endif ()


set(GTEST_DIR "" CACHE FILEPATH "path to the downloaded gtest library")
if (GTEST_DIR STREQUAL "")
    message(STATUS "GTEST_DIR empty: Configuring project without Tests")
    set(USE_TESTS BOOL OFF)
else ()
    set(USE_TESTS BOOL ON)
endif ()
