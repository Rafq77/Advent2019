#include "Day01.hpp"

#include <string_view>

using namespace std::string_view_literals;

namespace year2019 {

Day01::Day01() 
{
    // read from file
    //Day("day_01.txt");
}

void Day01::solvePart1() 
{
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
    }

    status = SolvedStatus::SolvedPart1;
    part1Solution = std::to_string(currentFloor);
}

void Day01::solvePart2() 
{

}

}