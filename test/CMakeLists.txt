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
    ${PROJECT_SOURCE_DIR}/tests/ControlTest.cpp
    ${PROJECT_SOURCE_DIR}/tests/CameraTest.cpp
    ${PROJECT_SOURCE_DIR}/tests/BinarySemaphoreTest.cpp
    ${PROJECT_SOURCE_DIR}/tests/RealtimeThreadTest.cpp
    ${PROJECT_SOURCE_DIR}/tests/PrioInheritMutexTest.cpp
    ${PROJECT_SOURCE_DIR}/mocks/source/CameraMock.cpp
)

set(PROJECT_SOURCES
    ${CMAKE_SOURCE_DIR}/source/system/source/Control.cpp
    ${CMAKE_SOURCE_DIR}/source/system/source/Services.cpp
    ${CMAKE_SOURCE_DIR}/source/api/source/BinarySemaphore.cpp
    ${CMAKE_SOURCE_DIR}/source/api/source/RealtimeThread.cpp
    ${CMAKE_SOURCE_DIR}/source/api/source/PrioInheritMutex.cpp
)

set(PROJECT_INCLUDES
    ${CMAKE_SOURCE_DIR}/source/
    ${CMAKE_SOURCE_DIR}/source/api/include
    ${CMAKE_SOURCE_DIR}/source/system/include
    ${CMAKE_SOURCE_DIR}/source/thirdparty/include
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(DEFINED ENV{CPPUTEST_HOME})
    find_package( OpenCV REQUIRED )
    add_compile_options(
        -Wall
        -Werror
        -Wextra
        -Wconversion
        --coverage
        -fprofile-arcs
        -ftest-coverage
        $<$<CONFIG:DEBUG>:-g3>
        $<$<CONFIG:DEBUG>:-Og>
    )

    include_directories(${PROJECT_NAME}
        INTERFACE
        $ENV{CPPUTEST_HOME}/include
        PRIVATE
        ${PROJECT_SOURCE_DIR}/mocks/include
        ${PROJECT_INCLUDES}
        ${OpenCV_INCLUDE_DIRS}
    )

    link_directories(${PROJECT_NAME}
        INTERFACE
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
        pthread
        rt
        ${OpenCV_LIBS}
    )

    if (CODE_COVERAGE)
        add_custom_command(TARGET ${PROJECT_NAME}
            PRE_BUILD
            COMMAND sudo setcap cap_sys_nice+ep ${PROJECT_NAME}
            POST_BUILD
            COMMENT "Running Code Coverage..."
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
            COMMAND ./${PROJECT_NAME} -xn SuccessfullyStartTheSystem
        )
    else()
        add_custom_command(TARGET ${PROJECT_NAME}
            PRE_BUILD
            COMMAND sudo setcap cap_sys_nice+ep ${PROJECT_NAME}
            POST_BUILD
            COMMENT "Running Unit Tests..."
            WORKING_DIRECTORY ${PROJECT_BINARY_DIR}
            COMMAND ./${PROJECT_NAME} -c -v -xn SuccessfullyStartTheSystem
        )
    endif()
else()
    message(STATUS "Requires the unit testing framework, CppuTest.")
endif()
