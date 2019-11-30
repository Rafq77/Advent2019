CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

SET(aoc AdventOfCode)

# language
PROJECT(${aoc} C CXX)

SET(CMAKE_C_STANDARD 11)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "/permissive /experimental:preprocessor /EHsc /wd5105")
SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(range-v3)
include_directories("range-v3/include")

file(GLOB Headers
    days/*/*.cpp
)

file (GLOB Sources
    days/*/*.cpp
)

set(FrameworkHeaders
    framework/Day.hpp
    framework/Input.hpp
)


set(FrameworkSources
    framework/Input.cpp
)


add_library(Framework STATIC ${FrameworkSources} ${FrameworkHeaders})
add_library(${aoc} STATIC ${Sources} ${Headers})
add_dependencies(${aoc} Framework)

add_subdirectory(test)