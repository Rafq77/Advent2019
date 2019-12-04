#pragma once
#include "../../framework/Day.hpp"
#include <string_view>
#include <set>

namespace year2019 {

    template <class T>
    class Day05 : public Day<T>
    {
        using Day::Day;
        using Point=std::pair<int,int>;

        virtual void solvePart1() override;
        virtual void solvePart2() override;

        std::vector<int32_t> validNumbersOfPart1;
    public:
        bool isPasswordValid(int32_t value);
        bool isPasswordValidExtraCondition(int32_t value);
    };
}