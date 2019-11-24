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

SET(This AdventOfCodeTest)

SET(Sources
    Year2015.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Framework
    AdventOfCode
)

add_test(
    NAME ${This}
    COMMAND ${This}
)

##############################################