#pragma once
#include "../../framework/Day.hpp"
#include <string_view>

namespace year2019 {

    template <class T>
    class Day03 : public Day<T>
    {
        using Day::Day;

        virtual void solvePart1() override;
        virtual void solvePart2() override;

        int shortestDistance;

        std::string_view fileName = "./input/day03.txt";
    public:
        std::string getDistance() { return std::to_string(shortestDistance); };
    };
}