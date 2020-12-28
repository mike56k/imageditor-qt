cmake_minimum_required(VERSION 3.5)

project(cmakeImageEditor LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED Widgets)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)
set(BUILD_SHARED_LIBS OFF)

#set(OpenCV_DIR ${OpenCV_DIR} D:/opencv/release)
find_package(OpenCV REQUIRED )
include_directories(${OpenCV_INCLUDE_DIRS})

get_property(QT_CORE_INCLUDE_DIRS TARGET Qt5::Core PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
list(GET QT_CORE_INCLUDE_DIRS 0 QT_CORE_MAIN_INCLUDE_DIR)
get_filename_component(QT_MAIN_DIR ${QT_CORE_MAIN_INCLUDE_DIR}/.. ABSOLUTE)


#install(DIRECTORY ${OpenCV_DIR}
#           DESTINATION ${PROJECT_BINARY_DIR}/Release USE_SOURCE_PERMISSIONS
#            CONFIGURATIONS Release)
#install(DIRECTORY ${OpenCV_DIR}
#                DESTINATION ${PROJECT_BINARY_DIR}/Debug USE_SOURCE_PERMISSIONS
#                CONFIGURATIONS Debug)
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
    resource.qrc
    commands.cpp
    commands.h
    colorsize.cpp
    colorsize.h
    colorsize.ui
)
install(FILES $<TARGET_FILE:Qt5::Widgets> DESTINATION ${PROJECT_BINARY_DIR}/Release CONFIGURATIONS Release)
install(FILES $<TARGET_FILE:Qt5::Widgets> DESTINATION ${PROJECT_BINARY_DIR}/Debug CONFIGURATIONS Debug)

install(FILES $<TARGET_FILE:Qt5::Gui> DESTINATION ${PROJECT_BINARY_DIR}/Release CONFIGURATIONS Release)
install(FILES $<TARGET_FILE:Qt5::Gui> DESTINATION ${PROJECT_BINARY_DIR}/Debug CONFIGURATIONS Debug)

install(FILES $<TARGET_FILE:Qt5::Core> DESTINATION ${PROJECT_BINARY_DIR}/Release CONFIGURATIONS Release)
install(FILES $<TARGET_FILE:Qt5::Core> DESTINATION ${PROJECT_BINARY_DIR}/Debug CONFIGURATIONS Debug)

install(FILES D:/opencv/build/x64/vc15/bin/opencv_world440.dll
           DESTINATION ${PROJECT_BINARY_DIR}/Release
            CONFIGURATIONS Release)
install(FILES D:/opencv/build/x64/vc15/bin/opencv_world440d.dll
                DESTINATION ${PROJECT_BINARY_DIR}/Debug
                CONFIGURATIONS Debug)


target_link_libraries(cmakeImageEditor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${OpenCV_LIBS} PRIVATE Qt5::Gui)
