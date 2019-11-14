#include <gtest/gtest.h>
#include "../days/2019/Day01.hpp"

#include <fstream>
#include <cstdint>
#include <string_view>

using namespace std::string_view_literals;

TEST(Year2019, Day01_Test) 
{
    year2019::Day01 day;
    //day(Input::fromRaw("(())()")); // return this

    EXPECT_EQ("137", day.getResultOfPart1());
    //EXPECT_EQ(1771, day.getResultOfPart2());

    //EXPECT_EQ(false, ff()) << " but value " << gValue2;
}

TEST(Year2019, FileIO)
{
    std::fstream stream;
    stream.open("./ttt.txt", std::fstream::out);
    stream << "Hello File\n";
    stream.close();
}

TEST(Year2019, FileReadInputFromRelativePath)
{
    std::ifstream stream;
    std::string filePath("../../days/2019/input/day01.txt"sv);
    stream.open(filePath);
    std::string tmp;
    stream >> tmp;
    stream.close();

    const uint16_t numberOfCharsInFile = 7000;
    const std::string_view firstTenChars = "()(((()))("sv;

    EXPECT_EQ(numberOfCharsInFile ,tmp.size());
    EXPECT_STREQ(std::string(firstTenChars).c_str(), tmp.substr(0, 10).c_str());
}