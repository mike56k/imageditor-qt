cmake_minimum_required(VERSION 3.5)

project(cmakeImageEditor LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(OpenCV_DIR ${OpenCV_DIR} D:/opencv/release)
find_package(OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)
add_executable(cmakeImageEditor
    main.cpp
    imageviewer.cpp
    imageviewer.h
    convert.h
    convert.cpp
    effectwindow.cpp
    effectwindow.h
    effectwindow.ui
    imagelabelwithrubberband.cpp
    imagelabelwithrubberband.h
    paintwindow.cpp
    paintwindow.h

    imagelabelfordrawing.cpp
    imagelabelfordrawing.h
    paintwindow.ui
    commands.cpp
    commands.h
)


target_link_libraries(cmakeImageEditor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${OpenCV_LIBS} PRIVATE Qt5::Gui)
