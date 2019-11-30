#pragma once
#include "../../framework/Day.hpp"
#include <string_view>

namespace year2019 {

    template <class T>
    class Day01 : public Day<T>
    {
        using Day::Day;

        std::string_view fileName = "./input/day01.txt";

        // TODO this is an interface, extract to Solver?
        virtual void solvePart1() override;
        virtual void solvePart2() override;

        int32_t resultOfDay1 = 0;

    public:
        Day01();
    };
}