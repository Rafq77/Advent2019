CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

SET(This ExampleTests)

SET(Sources
    ExampleTests.cpp
    Year2019Tests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Example
)

add_test(
    NAME ${This}
    COMMAND ${This}
)

SET(A2k9 Advent2009)

add_executable(${A2k9} Year2019Tests.cpp)
target_link_libraries(${A2k9} PUBLIC
    gtest_main
    Example
)

add_test(
    NAME ${A2k9}
    COMMAND ${A2k9}
)
