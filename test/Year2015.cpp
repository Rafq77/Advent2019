#include <gtest/gtest.h>
#include "../days/2015/Day01.hpp"
#include "../framework/Input.hpp"

#include <fstream>
#include <cstdint>
#include <string_view>

#include <range/v3/all.hpp>

using namespace std::string_view_literals;

TEST(Year2015, Day01_Test) 
{
    const uint16_t expectedFloor = 138;
    const uint16_t expectedFloorWithBasement = 1771;
    year2015::Day01 daySolver(Input::fromFile("../../days/2015/input/day01.txt"));

    EXPECT_EQ(std::to_string(expectedFloor), daySolver.getResultOfPart1());
    EXPECT_EQ(std::to_string(expectedFloorWithBasement), daySolver.getResultOfPart2());
}

/* 
TEST(Year2015, Part2Warmup)
{
    const uint16_t enteredBasementAtPosition = 1;
    year2015::Day01 daySolver(Input::fromString(")"));

    EXPECT_EQ(enteredBasementAtPosition , daySolver.solve_part2());
}
*/

/*
or example:
(()) and ()() both result in floor 0.
((( and (()(()( both result in floor 3.
))((((( also results in floor 3.
()) and ))( both result in floor -1 (the first basement level).
))) and )())()) both result in floor -3.
To what floor do the instructions take Santa?

Your puzzle answer was 138.

--- Part Two ---
Now, given the same instructions, find the position of the first character that causes him to enter the basement (floor -1). The first character in the instructions has position 1, the second character has position 2, and so on.

For example:

) causes him to enter the basement at character position 1.
()()) causes him to enter the basement at character position 5.
What is the position of the character that causes Santa to first enter the basement?

*/