#pragma once
#include "../../framework/Day.hpp"
#include <string_view>

namespace year2019 {

    template <class T>
    class Day01 : public Day<T>
    {
        using Day::Day;

        virtual void solvePart1() override;
        virtual void solvePart2() override;

        std::string_view fileName = "./input/day01.txt";
    public:
        Day01();
    };
}