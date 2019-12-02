#pragma once
#include "../../framework/Day.hpp"
#include <string_view>

namespace year2019 {

    template <class T>
    class Day02 : public Day<T>
    {
        using Day::Day;

        virtual void solvePart1() override;
        virtual void solvePart2() override;

        std::string_view fileName = "./input/day01.txt";
        std::vector<int64_t> _instructions;
        std::vector<int64_t> lastMemoryState;

        int calculate(std::vector<int64_t> inpInstructions);

    public:

        void override() 
        {
            _instructions[1] = 12;
            _instructions[2] = 2;
        }
        void initializeInstructions() { _instructions = input.getRaw(); }
        std::vector<int64_t> getMemory() { return lastMemoryState; }

        Day02() {};
    };
}