#include <gtest/gtest.h>
#include "../days/2018/Day01.hpp"
#include "../framework/Input.hpp"

#include <fstream>
#include <cstdint>
#include <string_view>

#include <range/v3/all.hpp>

using namespace std::string_view_literals;

TEST(Year2018, Day01_Test) 
{
    std::string sumResult = "540";
    std::string firstDoubleValue = "73056";

    year2018::Day01 daySolver(Input::fromFile("../../days/2018/input/day01.txt"));

    EXPECT_EQ(sumResult, daySolver.getResultOfPart1());
    //EXPECT_EQ(firstDoubleValue, daySolver.getResultOfPart2());
}

TEST(Year2018, Day01_Part1_Examples)
{
    EXPECT_EQ("3", year2018::Day01({"1", "-2", "+3", "+1"}).getResultOfPart1());
    EXPECT_EQ("3", year2018::Day01({"+1", "+1", "+1"}).getResultOfPart1());
    EXPECT_EQ("0", year2018::Day01({"+1", "+1", "-2"}).getResultOfPart1());
    EXPECT_EQ("-6", year2018::Day01({"-1", "-2", "-3"}).getResultOfPart1());
}

TEST(Year2018, Day01_Part2_Examples)
{
    /*
    +1, -1 first reaches 0 twice.
+3, +3, +4, -2, -4 first reaches 10 twice.
-6, +3, +8, +5, -6 first reaches 5 twice.
+7, +7, -2, -7, -4 first reaches 14 twice.

For example, using the same list of changes above, the device would loop as follows:

Current frequency  0, change of +1; resulting frequency  1.
Current frequency  1, change of -2; resulting frequency -1.
Current frequency -1, change of +3; resulting frequency  2.
Current frequency  2, change of +1; resulting frequency  3.
(At this point, the device continues from the start of the list.)
Current frequency  3, change of +1; resulting frequency  4.
Current frequency  4, change of -2; resulting frequency  2, which has already been seen.
*/
}