CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

SET(aoc AdventOfCode)

# language
PROJECT(${aoc} C CXX)

SET(CMAKE_C_STANDARD 11)
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_FLAGS "/permissive /experimental:preprocessor /EHsc /wd5105 /wd5104")
SET(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

set(BOOST_ROOT "./boost")
set(Boost_USE_STATIC_LIBS        OFF)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost 1.68.0 COMPONENTS thread graph regex system)

add_subdirectory(googletest)
add_subdirectory(range-v3)
include_directories("range-v3/include" ${Boost_INCLUDE_DIRS})

if(Boost_FOUND)
    message("===============")
    message(${Boost_INCLUDE_DIRS})
endif()

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