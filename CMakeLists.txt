cmake_minimum_required(VERSION 3.22)
project(gtest_template)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(main src/main.cpp)

add_executable(gtest tests/tests_main.cpp)
target_link_libraries(gtest ${GTEST_LIBRARIES})