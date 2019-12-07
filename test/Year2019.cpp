#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../days/2019/Day01.hpp"
#include "../days/2019/Day02.hpp"
#include "../days/2019/Day03.hpp"
#include "../days/2019/Day04.hpp"
#include "../days/2019/Day05.hpp"
#include "../days/2019/Day06.hpp"
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
    year2019::Day02<int32_t> daySolver(Input<int32_t>::fromFile("../../days/2019/input/day02.txt"));
    daySolver.initializeInstructions();
    daySolver.override(12, 2);

    EXPECT_EQ(9581917, daySolver.getResultOfPart1());
    EXPECT_EQ(19690720, daySolver.getResultOfPart2());

    auto pair = daySolver.getPart2Pair();
    EXPECT_EQ(25, pair.first);
    EXPECT_EQ(5, pair.second);
}

TEST(Year2019, Day02_Part1_Examples)
{
    year2019::Day02<int32_t> daySolver(Input<int32_t>{2,3,0,3,99});
    daySolver.initializeInstructions();
    daySolver.getResultOfPart1();
    ASSERT_THAT(daySolver.getMemory(), ::testing::ContainerEq(std::vector<int32_t>({2,3,0,6,99})));

    daySolver = year2019::Day02<int32_t>(Input<int32_t>{1,0,0,0,99}); 
    daySolver.initializeInstructions();
    daySolver.getResultOfPart1();
    ASSERT_THAT(daySolver.getMemory(), ::testing::ContainerEq(std::vector<int32_t>({2,0,0,0,99})));

    daySolver = year2019::Day02<int32_t>(Input<int32_t>{2,4,4,5,99,0}); 
    daySolver.initializeInstructions();
    daySolver.getResultOfPart1();
    ASSERT_THAT(daySolver.getMemory(), ::testing::ContainerEq(std::vector<int32_t>({2,4,4,5,99,9801})));

    daySolver = year2019::Day02<int32_t>(Input<int32_t>{1,1,1,4,99,5,6,0,99}); 
    daySolver.initializeInstructions();
    daySolver.getResultOfPart1();
    ASSERT_THAT(daySolver.getMemory(), ::testing::ContainerEq(std::vector<int32_t>({30,1,1,4,2,5,6,0,99})));
}

TEST(Year2019, Day03_Test) 
{
    year2019::Day03<std::string> daySolver(Input<std::string>::fromFile("../../days/2019/input/day03.txt"));

    daySolver.getResultOfPart1();
    EXPECT_EQ("1519", daySolver.getManhattanDistance());
    daySolver.getResultOfPart2();
    EXPECT_EQ("14358", daySolver.getCombinedWireDistance());
}

TEST(Year2019, Day04_Test) 
{
    year2019::Day04<int32_t> daySolver(Input{278384, 824795});

    EXPECT_EQ(921, daySolver.getResultOfPart1());
    EXPECT_EQ(603, daySolver.getResultOfPart2());
}

TEST(Year2019, Day04_Part1_Examples)
{
    year2019::Day04<int32_t> daySolver(Input{0});

    EXPECT_TRUE(daySolver.isPasswordValid(111111));
    EXPECT_FALSE(daySolver.isPasswordValid(223450));
    EXPECT_FALSE(daySolver.isPasswordValid(123789));
    EXPECT_TRUE(daySolver.isPasswordValid(122345));
    EXPECT_TRUE(daySolver.isPasswordValid(111123));
    EXPECT_FALSE(daySolver.isPasswordValid(135679));
}

TEST(Year2019, Day04_Part2_Examples)
{
    year2019::Day04<int32_t> daySolver(Input{0});

    EXPECT_FALSE(daySolver.isPasswordValidExtraCondition(111243));
    EXPECT_FALSE(daySolver.isPasswordValidExtraCondition(123444));
    EXPECT_TRUE(daySolver.isPasswordValidExtraCondition(112233));
    EXPECT_TRUE(daySolver.isPasswordValidExtraCondition(111233));
    EXPECT_TRUE(daySolver.isPasswordValidExtraCondition(111122));
}

TEST(Year2019, Day05_Test) 
{
    year2019::Day05<int32_t> daySolver(Input<int32_t>::fromFile("../../days/2019/input/day05.txt"));
    daySolver.inputValue = 1;
    //daySolver.initializeInstructions();


    //EXPECT_EQ(12234644, daySolver.getResultOfPart1());

/*

tst1 = [ 3,12,6,12,15,1,13,14,13,4,13,99,-1,0,1,9 ] #1/0
tst2 = [ 3,3,1105,-1,9,1101,0,0,12,4,12,99,1] #1/0
# x <=8
tst3 = [3,21,1008,21,8,20,1005,20,22,107,8,21,20,1006,20,31,1106,0,36,98,0,0,1002,21,125,20,4,20,1105,1,46,104,999,1105,1,46,1101,1000,1,20,4,20,1105,1,46,98,99 ] 
tst4 = [3,9,8,9,10,9,4,9,99,-1,8] # x==8
tst5 = [3,3,1108,-1,8,3,4,3,99] # x<8
    daySolver = year2019::Day02<int32_t>(Input<int32_t>{1,1,1,4,99,5,6,0,99}); 
    daySolver.initializeInstructions();
    daySolver.getResultOfPart1();
    ASSERT_THAT(daySolver.getMemory(), ::testing::ContainerEq(std::vector<int32_t>({30,1,1,4,2,5,6,0,99})));

*/
    //daySolver.initializeInstructions();
    //year2019::Day05<int32_t> daySolver("../../days/2019/input/day02.txt");
    //daySolver.isPasswordValid(1234567);

    //EXPECT_EQ(921, daySolver.getResultOfPart1());
    //EXPECT_EQ(603, daySolver.getResultOfPart2());
}


TEST(Year2019, Day06_Test) 
{
    year2019::Day06<int32_t> daySolver(Input<int32_t>::fromFile("../../days/2019/input/day06.txt"));
}