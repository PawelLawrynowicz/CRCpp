cmake_minimum_required(VERSION 3.22)
project(gtest_template)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(main ${SOURCES})
target_include_directories(main PRIVATE inc)

file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
    src/binary_operations.cpp
    src/matrix_operations.cpp
    src/input_operations.cpp
    src/menu.cpp
    src/code_correction.cpp)

add_executable(gtest tests/tests_main.cpp ${TEST_SOURCES})
target_link_libraries(gtest ${GTEST_LIBRARIES})
target_include_directories(gtest PRIVATE inc)