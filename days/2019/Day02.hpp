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

// TODO override 
//{
//}

        int calculate(std::vector<int64_t> inpInstructions)
        {
            auto instructions = inpInstructions;
            instructions[1] = 12;
            instructions[2] = 2;

            auto opCodeIdx = 0;
            auto opCodeIncrement = 4;
            auto opCode = 0;

            while(opCode != 99)
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
            //part1Solution = instructions[0];

            return instructions[0];
        }

    public:
        Day02();
    };
}