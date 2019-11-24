#include "Day01.hpp"

#include <algorithm>
#include <numeric>

namespace year2018 {

Day01::Day01() 
{

}

void Day01::solvePart1() 
{
    resultOfDay1 = std::accumulate(input.begin(), input.end(), 0 , [] (int32_t a, std::string b) { return a + std::stoi(b); });
    part1Solution = std::to_string(resultOfDay1);
    //ranges::accumulate(lengths, 0l) / 2;
}

void Day01::solvePart2() 
{

}

}