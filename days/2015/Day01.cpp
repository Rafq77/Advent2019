#include "Day01.hpp"

#include <string_view>

using namespace std::string_view_literals;

namespace year2015 {

template <class T>
void Day01<T>::solvePart1() 
{
    zeroFloorCrossing.clear();
    uint16_t instructionIndex = 1;
    static const int16_t basementFloor = -1;
    for (const auto & c : input)
    {
        if ( c == "("sv)
        {
            ++currentFloor;
        }
        else if (c == ")"sv)
        {
            --currentFloor;
        }

        if (currentFloor == basementFloor)
        {
            zeroFloorCrossing.push_back(std::to_string(instructionIndex));
        }

        ++instructionIndex;
    }


    status = SolvedStatus::SolvedPart1;
    part1Solution = std::to_string(currentFloor);
}

template <class T>
void Day01<T>::solvePart2() 
{
    part2Solution = zeroFloorCrossing.front();
    status = SolvedStatus::SolvedBoth;
}

}

template class year2015::Day01<std::string>;