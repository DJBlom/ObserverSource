############################################################################
# Contents: Unit Test CMakeLists.txt file
# Author: Dawid Blom
# Date: September 15, 2023
#
# NOTE:
# This file is the unit test CMakeLists.txt file containing the compiler
# options and definitions, the link options and libraries, the path to the
# main test runner file MainTest.cpp and all the test, mock files,
# and project source files.
############################################################################
cmake_minimum_required(VERSION 3.25)
project(${PROJECT_NAME} LANGUAGES CXX C)


set(TEST_SOURCES
    ${PROJECT_SOURCE_DIR}/tests/SystemTest.cpp
    ${PROJECT_SOURCE_DIR}/tests/CoreTest.cpp
    ${PROJECT_SOURCE_DIR}/mocks/source/
)

set(PROJECT_SOURCES
    ${PROJECT_SOURCE_DIR}/../source/system/source/System.cpp
    ${PROJECT_SOURCE_DIR}/../source/system/source/Core.cpp
    ${PROJECT_SOURCE_DIR}/../source/system/source/Asymmetric.cpp
)

set(PROJECT_INCLUDES
    ${PROJECT_SOURCE_DIR}/../source/system/include
)

if(DEFINED ENV{CPPUTEST_HOME})
    add_compile_options(
        -Wall
        -Werror
        -Wextra
        --coverage
        -fprofile-arcs
        -ftest-coverage
        $<$<CONFIG:DEBUG>:-g3>
        $<$<CONFIG:DEBUG>:-Og>
    )

    include_directories(${PROJECT_NAME} INTERFACE
        $ENV{CPPUTEST_HOME}/include
        ${PROJECT_SOURCE_DIR}/mocks/include
        ${PROJECT_INCLUDES}
    )

    link_directories(${PROJECT_NAME} INTERFACE
        $ENV{CPPUTEST_HOME}/lib
    )

    add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCE_DIR}/MainTest.cpp
        ${TEST_SOURCES}
        ${PROJECT_SOURCES}
    )

    target_link_libraries(${PROJECT_NAME}
        gcov
        CppUTest
        CppUTestExt
    )

    if (CODE_COVERAGE)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMENT "Running Code Coverage..."
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
            COMMAND ./${PROJECT_NAME}
        )
    else()
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMENT "Running Unit Tests..."
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
            COMMAND ./${PROJECT_NAME} -c -v -xn "SetupOfCoreSystem"
        )
    endif()
else()
    message(STATUS "Requires the unit testing framework, CppuTest.")
endif()
