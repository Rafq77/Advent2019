CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

SET(This AdventOfCodeTest)

SET(Sources
    Year2019Tests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    AdventOfCode
)

add_test(
    NAME ${This}
    COMMAND ${This}
)