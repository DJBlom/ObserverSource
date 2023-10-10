############################################################################
# Contents: API CMakeLists.txt file
# Author: Dawid Blom
# Date: October 2, 2023
#
# NOTE:
############################################################################
cmake_minimum_required(VERSION 3.25)
project(target-api VERSION 0.0.1 LANGUAGES CXX C)


file(GLOB RESULT ${PROJECT_SOURCE_DIR}/source)
list(LENGTH RESULT FILES_IN_DIR)
if(${FILES_IN_DIR} GREATER 0)
    add_library(api OBJECT
        ${PROJECT_SOURCE_DIR}/source/RealTimeSched.cpp
        ${PROJECT_SOURCE_DIR}/source/BinarySemaphores.cpp
    )

    target_include_directories(api PRIVATE
        ${PROJECT_SOURCE_DIR}/include/
    )
else ()
    message(STATUS "There are no files in, source/features/include or source/features/source.")
endif()



