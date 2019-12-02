#pragma once
#include "../../framework/Day.hpp"
#include <string_view>

namespace year2015 {

    template <class T>
    class Day01 : public Day<T>
    {
        using Day::Day;

        std::string_view fileName = "./input/day01.txt";

        // TODO this is an interface, extract to Solver?
        virtual void solvePart1() override;
        virtual void solvePart2() override;

        const int16_t startingFloor = 0;
        int16_t currentFloor = startingFloor;
        std::vector<std::string> zeroFloorCrossing;
    };
}