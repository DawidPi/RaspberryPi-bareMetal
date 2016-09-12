set(QT5_PACKAGE_DIR "" CACHE FILEPATH "path to the place, where package to the QT5_Dir exists, so that cmake can find package")

if (QT5_PACKAGE_DIR STREQUAL "")
    message(FATAL_ERROR "QT5_PACKAGE_DIR empty: Please specify QT5_PACKAGE_DIR path")
else ()
    file(GLOB QT_DLLS QT5_PACKAGE_DIR "*.dll")
endif ()