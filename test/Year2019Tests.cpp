#include <gtest/gtest.h>
#include "../days/2019/Day01.hpp"

TEST(Year2019, Day01_Test) 
{
    year2019::Day01 day;
    EXPECT_EQ("138", day.getResultOfPart1());
    //EXPECT_EQ(1771, day.getResultOfPart2());

    //EXPECT_EQ(false, ff()) << " but value " << gValue2;
}