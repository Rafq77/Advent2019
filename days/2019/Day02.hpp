#pragma once
#include "../../framework/Day.hpp"

#include <string_view>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <set>

#include <range/v3/all.hpp>

namespace year2019 {

    template <class T>
    class Day02 : public Day<T>
    {
        using Day::Day;

        virtual void solvePart1() override;
        virtual void solvePart2() override;

    protected:
        std::string_view fileName = "./input/day01.txt";
        std::vector<int32_t> _instructions;
        std::vector<int32_t> backupInstructions;
        std::vector<int32_t> lastMemoryState;
        std::pair<int32_t,int32_t> part2Pair;

        int calculate(std::vector<int32_t> inpInstructions);

    public:

        void override(int x, int y)
        {
            _instructions[1] = x; 
            _instructions[2] = y; 
        }
        void initializeInstructions() { _instructions = input.getRaw(); }
        std::vector<int32_t> getMemory() { return lastMemoryState; }
        std::pair<int32_t, int32_t> getPart2Pair() { return part2Pair; }
    };
}