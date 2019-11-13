#include <gtest/gtest.h>
#include "../days/2019/Day01.hpp"

#include <fstream>

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
    std::string filePath("../../days/2019/input/day01.txt");
    stream.open(filePath);
    std::string tmp;
    stream >> tmp;
    stream.close();

    std::cout << tmp;
    EXPECT_EQ(1,2); // todo compare beginning
}