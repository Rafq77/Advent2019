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

SET(aoc2015 AdventOfCode2015)

SET(Sources2015
    Year2015.cpp
)

add_executable(${aoc2015} ${Sources2015})
target_link_libraries(${aoc2015} PUBLIC
    gtest_main
    Framework
    AdventOfCode
)

add_test(
    NAME ${aoc2015}
    COMMAND ${aoc2015}
)


##############################################

SET(aoc2018 AdventOfCode2018)

SET(Sources2018
    Year2018.cpp
)

add_executable(${aoc2018} ${Sources2018})
target_link_libraries(${aoc2018} PUBLIC
    gtest_main
    Framework
    AdventOfCode
)

add_test(
    NAME ${aoc2018}
    COMMAND ${aoc2018}
)

