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

set(Headers
    days/2015/Day01.hpp
    days/2018/Day01.hpp
)

set(Sources
    days/2015/Day01.cpp
    days/2018/Day01.cpp
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