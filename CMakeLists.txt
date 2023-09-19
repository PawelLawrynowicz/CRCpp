 cmake_minimum_required(VERSION 3.10)

 # Set the project name and version
 project(CyclicCoder VERSION 1.0)

 # Add an executable target
 add_executable(CyclicCoder src/main.cpp)

 # Optionally, set C++ standard (e.g., C++11)
 set_target_properties(CyclicCoder PROPERTIES
         CXX_STANDARD 17
         CXX_STANDARD_REQUIRED ON
 )