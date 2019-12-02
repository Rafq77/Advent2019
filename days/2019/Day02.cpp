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

}

template class year2019::Day02<int64_t>;