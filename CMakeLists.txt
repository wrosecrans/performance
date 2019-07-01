
cmake_minimum_required(VERSION 3.5)

SET(CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY CXX_STANDARD 14)


include_directories(${CMAKE_CURRENT_SOURCE_DIR})
project(Performance CXX)
add_custom_target(data COMMAND dir SOURCES README.md)


add_executable(${PROJECT_NAME} "main.cpp")
