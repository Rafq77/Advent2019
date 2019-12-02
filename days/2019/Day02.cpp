#include "Day02.hpp"

#include <algorithm>
#include <numeric>
#include <set>

#include <range/v3/all.hpp>

namespace year2019 {

template <class T>
void Day02<T>::solvePart1() 
{
    part1Solution = calculate(_instructions);
}

template <class T>
void Day02<T>::solvePart2() 
{
    part2Solution = 2;
}

template <class T>
int Day02<T>::calculate(std::vector<int64_t> inpInstructions)
{
    auto instructions = inpInstructions;

    auto opCodeIdx = 0;
    auto opCodeIncrement = 4;
    auto opCode = 0;

    while (opCode != 99)
    {
        opCode = instructions[opCodeIdx];

        if (opCode == 99)
        {
            break;
        }

        auto arg1 = instructions[opCodeIdx + 1];
        auto arg2 = instructions[opCodeIdx + 2];
        auto dst = instructions[opCodeIdx + 3];

        if (opCode == 1) // add
        {
            instructions[dst] = instructions[arg1] + instructions[arg2];
        }
        else if (opCode == 2) // mul
        {
            instructions[dst] = instructions[arg1] * instructions[arg2];
        }

        opCodeIdx = opCodeIdx + 4;
    }

    lastMemoryState = instructions;
    return instructions[0];
}

}

template class year2019::Day02<int64_t>;