#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../days/2019/Day01.hpp"
#include "../days/2019/Day02.hpp"
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

TEST(Year2019, Day02_Test) 
{
    year2019::Day02<int64_t> daySolver(Input<int64_t>::fromFile("../../days/2019/input/day02.txt"));
    daySolver.initializeInstructions();
    daySolver.override();

    EXPECT_EQ(9581917, daySolver.getResultOfPart1());
}

TEST(Year2019, Day02_Part1_Examples)
{
    year2019::Day02<int64_t> daySolver(Input<int64_t>{2,3,0,3,99});
    daySolver.initializeInstructions();
    daySolver.getResultOfPart1();
    ASSERT_THAT(daySolver.getMemory(), ::testing::ContainerEq(std::vector<int64_t>({2,3,0,6,99})));

        /*
    EXPECT_EQ(2, year2019::Day02<int64_t>(Input<int64_t>{1,0,0,0,99}).getResultOfPart1()); //2,0,0,0,99
    EXPECT_EQ(2, year2019::Day02<int64_t>(Input<int64_t>{2,3,0,3,99}).getResultOfPart1());  // 2,3,0,6,99
    EXPECT_EQ(2, year2019::Day02<int64_t>(Input<int64_t>{2,4,4,5,99,0}).getResultOfPart1()); // 2,4,4,5,99,9801
    EXPECT_EQ(30, year2019::Day02<int64_t>(Input<int64_t>{1,1,1,4,99,5,6,0,99}).getResultOfPart1()); // 30,1,1,4,2,5,6,0,99
    */
}
