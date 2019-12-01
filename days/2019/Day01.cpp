#include "Day01.hpp"

#include <algorithm>
#include <numeric>
#include <set>

#include <range/v3/all.hpp>

namespace year2019 {

template <class T>
Day01<T>::Day01() 
{

}

template <class T>
void Day01<T>::solvePart1() 
{
    // For a mass of X, divide by 3 and round down to get Y, then subtract 2 to get RESULT.
    part1Solution = std::accumulate(input.begin(), input.end(), 0 , [](int32_t sum, int32_t x){ return sum + (x/3 - 2); } );

    //ranges::accumulate(lengths, 0l) / 2;
}

template <class T>
void Day01<T>::solvePart2() 
{
    part2Solution = std::accumulate(input.begin(), input.end(), 0 , [](int32_t sum, int32_t x){ 
        int32_t fuelReq = x;
        int32_t totalFuelReq = 0;
        while (fuelReq > 0)
        {
            fuelReq = (fuelReq/3 - 2); 
            totalFuelReq += (fuelReq < 0 ) ? 0 : fuelReq;
        }
        return sum + totalFuelReq;
    });
}

}

template class year2019::Day01<int32_t>;