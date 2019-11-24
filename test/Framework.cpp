#include <gtest/gtest.h>
#include "../days/2015/Day01.hpp"
#include "../framework/Input.hpp"

#include <fstream>
#include <cstdint>
#include <string_view>

#include <range/v3/all.hpp>

using namespace std::string_view_literals;

TEST(Framework, RangesTest)
{
        
    std::string text = "Hello|World|Ranges";
    auto splitText = text | ranges::view::split('|')
                            | ranges::view::transform([](auto &&rng) {
                            return std::string_view(&*rng.begin(), ranges::distance(rng));
                    });

    EXPECT_EQ("Hello"sv, ranges::front(splitText));
    EXPECT_NE("World"sv, ranges::front(splitText));
}

TEST(Framework, FileIO)
{
    std::fstream stream;
    stream.open("./ttt.txt", std::fstream::out);
    stream << "Hello File\n";
    stream.close();
}

TEST(Framework, FileReadInputFromRelativePath)
{
    std::ifstream stream;
    std::string filePath("../../days/2015/input/day01.txt"sv);
    stream.open(filePath);
    std::string tmp;
    stream >> tmp;
    stream.close();

    const uint16_t numberOfCharsInFile = 7000;
    const std::string_view firstTenChars = "()(((()))("sv;

    EXPECT_EQ(numberOfCharsInFile ,tmp.size());
    EXPECT_STREQ(std::string(firstTenChars).c_str(), tmp.substr(0, 10).c_str());
}

TEST(Framework, HowTestShouldLookLike)
{
    const uint16_t expectedFloor = 0;
    year2015::Day01<std::string> daySolver(Input<std::string>{"(())"});


    EXPECT_EQ(std::to_string(expectedFloor), daySolver.getResultOfPart1());
}