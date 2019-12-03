#pragma once
#include "../../framework/Day.hpp"
#include <string_view>

namespace year2019 {

    template <class T>
    class Day04 : public Day<T>
    {
        using Day::Day;

        using Point=std::pair<int,int>;

        virtual void solvePart1() override;
        virtual void solvePart2() override;

        std::string_view fileName = "./input/day04.txt";
    public:
    };
}