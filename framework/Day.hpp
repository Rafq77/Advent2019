#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string_view>

#include "Input.hpp"

class Day
{
    enum class SolvedStatus
    {
        NotSolved,
        SolvedPart1,
        SolvedPart2,
        SolvedBoth
    };

    SolvedStatus status = SolvedStatus::NotSolved;
    Input input;
    virtual void solvePart1() = 0;
    virtual void solvePart2() = 0;
    bool wasSolved = false;
    std::string part1Solution = ""; //sv
    std::string part2Solution = ""; //sv

public:

    std::string getResultOfPart1() 
    {
        if (input.isValid())
        {
            input.read(); // might throw exception?
        }

        if (false == wasSolved)
        {
            solvePart1();
        }
        return part1Solution;
    }
    std::string getResultOfPart2()
    {
        if (false == wasSolved)
        {
            solvePart2();
        }
        return part2Solution;
    }

    Day() // TODO disable this
    {

    }

    Day(std::string fileName) 
    : input(fileName)
    {

    } 
};