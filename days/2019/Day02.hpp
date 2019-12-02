#pragma once
#include "../../framework/Day.hpp"
#include <string_view>
#include <tuple>

namespace year2019 {

    template <class T>
    class Day02 : public Day<T>
    {
        using Day::Day;

        virtual void solvePart1() override;
        virtual void solvePart2() override;

        std::string_view fileName = "./input/day01.txt";
        std::vector<int64_t> _instructions;
        std::vector<int64_t> backupInstructions;
        std::vector<int64_t> lastMemoryState;
        std::pair<int64_t,int64_t> part2Pair;

        int calculate(std::vector<int64_t> inpInstructions);

    public:

        void override(int x, int y)
        {
            _instructions[1] = x; 
            _instructions[2] = y; 
        }
        void initializeInstructions() { _instructions = input.getRaw(); }
        std::vector<int64_t> getMemory() { return lastMemoryState; }
        std::pair<int64_t, int64_t> getPart2Pair() { return part2Pair; }

        Day02() {};
    };
}