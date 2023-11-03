############################################################################
# Contents: API CMakeLists.txt file
# Author: Dawid Blom
# Date: October 2, 2023
#
# NOTE:
############################################################################
cmake_minimum_required(VERSION 3.25)
project(target-thirdparty VERSION 0.0.1 LANGUAGES CXX C)


file(GLOB RESULT ${PROJECT_SOURCE_DIR}/source)
list(LENGTH RESULT FILES_IN_DIR)
if(${FILES_IN_DIR} GREATER 0)
    find_package( OpenCV REQUIRED )
    add_library(thirdparty OBJECT
        ${PROJECT_SOURCE_DIR}/source/VideoCamera.cpp
    )

    target_include_directories(thirdparty
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include/
        ${OpenCV_INCLUDE_DIRS}
        PUBLIC
        ${PROJECT_SOURCE_DIR}/../
    )

    target_link_libraries(thirdparty PRIVATE
        ${OpenCV_LIBS}
    )
else ()
    message(STATUS "There are no files in, source/api/source.")
endif()
