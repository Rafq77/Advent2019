#pragma once
#include "../../framework/Day.hpp"
#include <string_view>
#include <map>

namespace year2019 {

    template <class T>
    class Day03 : public Day<T>
    {
        using Day::Day;

        using Point=std::pair<int,int>;

        virtual void solvePart1() override;
        virtual void solvePart2() override;

        std::vector<Point> wire1Points;
        std::vector<Point> wire2Points;
        std::map<Point, int> wire1Distance;
        std::map<Point, int> wire2Distance;
        std::vector<Point> results;
        int shortestDistance;
        int shortestCombinedDistance; 

        std::string_view fileName = "./input/day03.txt";
    public:
        std::string getManhattanDistance() { return std::to_string(shortestDistance); };
        std::string getCombinedWireDistance() { return std::to_string(shortestCombinedDistance); };
    };
}