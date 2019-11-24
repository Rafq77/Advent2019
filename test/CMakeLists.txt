CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

##############################################

SET(FrameworkTest FrameworkTest)

SET(FrameworkSources
    Framework.cpp
)

add_executable(${FrameworkTest} ${FrameworkSources})
target_link_libraries(${FrameworkTest} PUBLIC
    gtest_main
    Framework
    AdventOfCode
)

add_test(
    NAME ${FrameworkTest}
    COMMAND ${FrameworkTest}
)

##############################################

SET(aoc AdventOfCodeTests)

SET(Sources
    Year2015.cpp
    Year2018.cpp
)

add_executable(${aoc} ${Sources})
target_link_libraries(${aoc} PUBLIC
    gtest_main
    Framework
    AdventOfCode
)

add_test(
    NAME ${aoc}
    COMMAND ${aoc}
)