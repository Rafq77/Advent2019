#include "Day01.hpp"

#include <algorithm>
#include <numeric>
#include <set>

namespace year2018 {

template <class T>
Day01<T>::Day01() 
{

}

template <class T>
void Day01<T>::solvePart1() 
{
    part1Solution = std::accumulate(input.begin(), input.end(), 0 );
    //ranges::accumulate(lengths, 0l) / 2;
}

template <class T>
void Day01<T>::solvePart2() 
{
    // std::set while double entry not applied
}

}

template class year2018::Day01<int32_t>;