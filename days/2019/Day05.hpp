#pragma once
#include "../../framework/Day.hpp"
#include "Day02.hpp"
#include <string_view>
#include <set>

namespace year2019 {

    template <class T>
    class Day05 : public Day02<T>
    {
        using Day02::Day02;
        using Point=std::pair<int,int>;

        virtual void solvePart1() override;
        virtual void solvePart2() override;

        int calculate(std::vector<int32_t> inpInstructions);
        
        int32_t outputValue = 0;

        std::vector<int32_t> validNumbersOfPart1;
    public:
        int32_t inputValue = 0;
    };
}

