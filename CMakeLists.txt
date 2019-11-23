CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

SET(This AdventOfCode)

# language
PROJECT(${This} C CXX)

SET(CMAKE_C_STANDARD 11)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "/permissive /experimental:preprocessor /EHsc /wd5105")
SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(range-v3)
include_directories("range-v3/include")

set(Headers
    framework/Day.hpp
    framework/Input.hpp
)

set(Sources
    days/2015/Day01.cpp
    framework/Input.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)