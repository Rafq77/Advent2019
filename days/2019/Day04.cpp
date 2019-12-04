#include "Day04.hpp"

#include <algorithm>
#include <numeric>
#include <set>
#include <string>

#include <range/v3/all.hpp>

namespace year2019 {

template <class T>
void Day04<T>::solvePart1() 
{
    auto x = input.getRaw();
    if (x.size() != 2)
    {
        // error
        return;
    }

    auto min = x[0];
    auto max = x[1];
    int count = 0;

    validNumbersOfPart1.clear();
    for (int i = min; i <= max; ++i)
    {
        if (isPasswordValid(i))
        {
            validNumbersOfPart1.push_back(i);
            ++count;
        }
    }

    part1Solution = count;
}

template <class T>
bool Day04<T>::isPasswordValid(int32_t value)
{
    bool checkDoubles = false;
    bool checkMonotonic = true;

    std::string val = std::to_string(value);

    for (auto i = 0; i < val.size()-1; ++i)
    {
        if (val[i] > val[i+1])
        {
            checkMonotonic = false;
        }
        if (val[i] == val[i+1])
        {
            checkDoubles = true;
        }
    }

    return (checkDoubles && checkMonotonic) ? true : false;

}

template <class T>
void Day04<T>::solvePart2() 
{
    if (validNumbersOfPart1.empty())
    {
        return;
    }

    part2Solution = 0;
    
    for (auto i : validNumbersOfPart1)
    {
        part2Solution += isPasswordValidExtraCondition(i);
    }
}

template <class T>
bool Day04<T>::isPasswordValidExtraCondition(int32_t value)
{
    bool validCandidate = true;
    std::set<int32_t> invalidChars;
    std::string val = std::to_string(value);

    // find triples in series
    char invalidCharCandidate = val[0];
    int invalidInSeries = 1;
    for (int i = 1; i < val.size(); ++i)
    {
        if (invalidCharCandidate == val[i])
        {
            ++invalidInSeries;
        } 
        else 
        {
            if (invalidInSeries > 2)
            {
                invalidChars.insert(invalidCharCandidate);
                validCandidate = false;
            }
            invalidCharCandidate = val[i];
            invalidInSeries = 1;
        }
    }

    // check after
    if (invalidInSeries > 2)
    {
        invalidChars.insert(invalidCharCandidate);
        validCandidate = false;
    }

    // checkDouble
    for (int i = 0; i < val.size()-1; ++i)
        if (val[i] == val[i+1] 
            &&  invalidChars.end() == std::find(invalidChars.begin(), invalidChars.end(), val[i]))
            {
                validCandidate = true; // still a good value
            }
    return validCandidate;
}

}

template class year2019::Day04<int32_t>;