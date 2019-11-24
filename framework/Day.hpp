#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string_view>

#include "Input.hpp"

template <class T>
class Day
{
    protected:
    enum class SolvedStatus
    {
        NotSolved,
        SolvedPart1,
        SolvedPart2,
        SolvedBoth
    };

    SolvedStatus status = SolvedStatus::NotSolved;
    Input<T> input;
    virtual void solvePart1() = 0;
    virtual void solvePart2() = 0;
    bool wasSolved = false;
    T part1Solution = ""; //sv
    T part2Solution = ""; //sv

public:

    T getResultOfPart1() 
    {
        if (false == input.isValidInputLoaded())
        {
            throw std::runtime_error("No valid input could be loaded!");
        }

        if (false == wasSolved)
        {
            solvePart1();
        }
        return part1Solution;
    }
    T getResultOfPart2()
    {
        if (status == SolvedStatus::NotSolved)
        {
            solvePart1();
        }

        if (false == wasSolved)
        {
            solvePart2();
        }
        return part2Solution;
    }

    Day(Input<T> _input)
    : input(_input)
    {

    }

    Day() // TODO disable this
    {

    }

    Day(std::string fileName) 
    : input(Input<T>::fromFile(fileName))
    {

    } 
};