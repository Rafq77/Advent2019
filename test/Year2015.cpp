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

TEST(Year2015, Day01_Part1_Examples)
{
    EXPECT_EQ("0", year2015::Day01(Input::fromString("(())")).getResultOfPart1());
    EXPECT_EQ("0", year2015::Day01(Input::fromString("()()")).getResultOfPart1());
    EXPECT_EQ("3", year2015::Day01(Input::fromString("(((")).getResultOfPart1());
    EXPECT_EQ("3", year2015::Day01(Input::fromString("(()(()(")).getResultOfPart1());
    EXPECT_EQ("3", year2015::Day01(Input::fromString("))(((((")).getResultOfPart1());

    EXPECT_EQ("-1", year2015::Day01(Input::fromString("())")).getResultOfPart1());
    EXPECT_EQ("-1", year2015::Day01(Input::fromString("))(")).getResultOfPart1());

    EXPECT_EQ("-3", year2015::Day01(Input::fromString(")))")).getResultOfPart1());
    EXPECT_EQ("-3", year2015::Day01(Input::fromString(")())())")).getResultOfPart1());
}

TEST(Year2015, Day01_Part2_Examples)
{
    EXPECT_EQ("1", year2015::Day01(Input::fromString(")")).getResultOfPart2());
    EXPECT_EQ("5", year2015::Day01(Input::fromString("()())")).getResultOfPart2());
}