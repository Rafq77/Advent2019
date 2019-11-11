#pragma once
#include "../../framework/Day.hpp"
#include <string_view>

namespace year2019 {
    class Day01 : public Day
    {
        std::string_view fileName = "./input/day01.txt";

        virtual void solvePart1() override;
        virtual void solvePart2() override;
    public:
        Day01();
    };
}