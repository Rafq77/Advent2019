#include <gtest/gtest.h>
#include "../days/2019/Day01.hpp"
#include "../framework/Input.hpp"

#include <fstream>
#include <cstdint>
#include <string_view>

#include <range/v3/all.hpp>

using namespace std::string_view_literals;

TEST(Year2019, Day01_Test) 
{
    year2019::Day01<int32_t> daySolver(Input<int32_t>::fromFile("../../days/2019/input/day01.txt"));

    EXPECT_EQ(3159380, daySolver.getResultOfPart1());
    EXPECT_EQ(4736213, daySolver.getResultOfPart2());
}

TEST(Year2019, Day01_Part1_Examples)
{
    EXPECT_EQ(2, year2019::Day01<int32_t>(Input{12}).getResultOfPart1());
    EXPECT_EQ(2, year2019::Day01<int32_t>(Input{14}).getResultOfPart1());
    EXPECT_EQ(654, year2019::Day01<int32_t>(Input{1969}).getResultOfPart1());
    EXPECT_EQ(33583, year2019::Day01<int32_t>(Input{100756}).getResultOfPart1());
}

TEST(Year2019, Day01_Part2_Examples)
{
    EXPECT_EQ(2, year2019::Day01<int32_t>(Input{14}).getResultOfPart2());
    EXPECT_EQ(966, year2019::Day01<int32_t>(Input{1969}).getResultOfPart2());
    EXPECT_EQ(50346, year2019::Day01<int32_t>(Input{100756}).getResultOfPart2());
}