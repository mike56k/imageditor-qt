cmake_minimum_required(VERSION 3.5)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

project(cmakeImageEditor LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED Widgets)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Gui REQUIRED)


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

get_property(QT_CORE_INCLUDE_DIRS TARGET Qt5::Core PROPERTY INTERFACE_INCLUDE_DIRECTORIES)
list(GET QT_CORE_INCLUDE_DIRS 0 QT_CORE_MAIN_INCLUDE_DIR)
get_filename_component(QT_MAIN_DIR ${QT_CORE_MAIN_INCLUDE_DIR}/.. ABSOLUTE)

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

find_package(Doxygen)
if (DOXYGEN_FOUND)
  set(doxyfile_cfg ${CMAKE_CURRENT_BINARY_DIR}/doxyfile.cfg)

  add_custom_target(get_doc ALL
                                        COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile_cfg}
                                        COMMENT "Generating API documentation with Doxygen"
                                        VERBATIM)
endif()

set(dir_src_doc ${CMAKE_CURRENT_BINARY_DIR}/doc/rtf/)
install(
        DIRECTORY
                "${dir_src_doc}"
        DESTINATION
                doc
)

install(FILES $<TARGET_FILE:Qt5::Widgets> DESTINATION bin)


install(FILES $<TARGET_FILE:Qt5::Gui> DESTINATION bin)


install(FILES $<TARGET_FILE:Qt5::Core> DESTINATION bin)


install(
        TARGETS
                cmakeImageEditor
        DESTINATION
                bin
)


install(FILES $<TARGET_FILE:opencv_world> DESTINATION bin)

install(DIRECTORY ${QT_MAIN_DIR}/plugins/platforms/
            DESTINATION bin/Plugins/platforms)

install(DIRECTORY ${QT_MAIN_DIR}/plugins/imageformats/
                DESTINATION bin/Plugins/imageformats)




target_link_libraries(cmakeImageEditor PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${OpenCV_LIBS} PRIVATE Qt5::Gui)
