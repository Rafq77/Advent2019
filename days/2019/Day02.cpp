#include "Day02.hpp"

#include <algorithm>
#include <numeric>
#include <set>

#include <range/v3/all.hpp>

namespace year2019 {

template <class T>
Day02<T>::Day02() 
{

}

template <class T>
void Day02<T>::solvePart1() 
{
    calculate(input.getRaw());
}

template <class T>
void Day02<T>::solvePart2() 
{
    part2Solution = 2;
}

}

//template class year2019::Day02<int32_t>;
template class year2019::Day02<int64_t>;