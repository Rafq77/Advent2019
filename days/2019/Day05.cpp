#include "Day05.hpp"

#include <algorithm>
#include <numeric>
#include <set>
#include <string>

#include <range/v3/all.hpp>

namespace year2019 {

template <class T>
void Day05<T>::solvePart1() 
{
    calculate(_instructions);
    part1Solution = outputValue;
}

template <class T>
void Day05<T>::solvePart2() 
{
    part2Solution = 0;
    
}

template <class T>
int Day05<T>::calculate(std::vector<int32_t> inpInstructions)
{
    auto instructions = inpInstructions;

    auto opCodeIdx = 0;
    auto opCode = 0;

    while (opCode != 99)
    {
        opCode = instructions[opCodeIdx];
 //1002
        std::string fullOpCode = std::to_string(opCode);
        //std::string rFullOpCode = //(fullOpCode.rbegin(), fullOpCode.end());
        std::reverse(fullOpCode.begin(), fullOpCode.end()); 
        //2 0 0 1


        int instrLen = fullOpCode.size();
        if ( instrLen < 5)
        {
            for (int i = instrLen; i < 5; ++i)
            {
                fullOpCode += '0';
            }
        }

         //   fullOpCode += ['0' for x in range(5 - instrLen)]
//std::stoi(std::string(fullOpCode[1] + fullOpCode[0]));
        auto sub = fullOpCode.substr(0,1);
        std::reverse(sub.begin(), sub.end());
        //auto tmp = ranges::reverse(sub) | ranges::to<std::string>();
        opCode = std::stoi(sub);
        std::cout << opCode << '\n';

        if (opCode == 99)
        {
            break;
        }

        auto arg1 = (fullOpCode[2] == '1') ? instructions[opCodeIdx + 1] : instructions[instructions[opCodeIdx + 1]];
        auto arg2 = 0;
        auto dst = 0;

        if (!(opCode == 3 || opCode == 4))
        {
            arg2 = (fullOpCode[3] == '1') ? instructions[opCodeIdx + 2] : instructions[instructions[opCodeIdx + 2]];
            dst = instructions[opCodeIdx + 3];
        }

        switch (opCode) {
            case 1: // add
                instructions[dst] = instructions[arg1] + instructions[arg2];
                opCodeIdx += 4;
            break;
            case 2: // mul
                instructions[dst] = instructions[arg1] * instructions[arg2];
                opCodeIdx += 4;
            break;
            case 3:
            //print("Provide input: ")
            //val = int(input())
            // TODO work on thisinstructions[instructions[opCodeIdx + 1]] = inputValue;
            instructions[instructions[opCodeIdx + 1]] = inputValue;
            opCodeIdx += 2;
            break;
            case 4: // #output
            outputValue = arg1;
            std::cout << outputValue << '\n';
            opCodeIdx += 2;
            break;
            case 5: //jump if true
            opCodeIdx = (arg1 != 0) ? arg2 : opCodeIdx + 3;
            break;
            case 6: //jump if false
            opCodeIdx = (arg1 == 0) ? arg2 : opCodeIdx + 3;
            break;
            case 7: //less than
            instructions[dst] = (arg1 < arg2) ? 1 : 0;
            opCodeIdx += 4;
            break;
            case 8: // equals
            instructions[dst] = (arg1 == arg2) ? 1 : 0;
            opCodeIdx += 4;
            break;
            default:
            break;

        }
    }

    lastMemoryState = instructions;
    return instructions[0];
}

}

template class year2019::Day05<int32_t>;