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
