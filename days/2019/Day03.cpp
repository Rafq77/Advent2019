#include "Day03.hpp"

#include <algorithm>
#include <numeric>
#include <set>
#include <string>

#include <range/v3/all.hpp>

namespace year2019 {

template <class T>
void Day03<T>::solvePart1() 
{
    // we expect two lines from input
    auto wire1 = input.getRaw()[0];
    auto wire2 = input.getRaw()[1];

    auto instr1 = wire1 | ranges::view::split(',');
    auto instr2 = wire2 | ranges::view::split(',');
    std::vector<Point> pathWire1;
    std::vector<Point> pathWire2;

    //std::pair<int,int> zero = std::make_pair(0,0);
    Point zero = {0,0};
    Point pos = zero;

    int distanceSoFar = 1;

    for (auto i : instr1)
    {
        int distance = std::stoi(std::string(i[{1,ranges::end}]));
        std::string direction = i[{0,1}];

        for (int j=0; j < distance; ++j)
        {
            switch (direction[0])
            {
            case 'L':
                pos.first -= 1;
                break;
            case 'R':
                pos.first += 1;
                break;
            case 'U':
                pos.second += 1;
                break;
            case 'D':
                pos.second -= 1;
                break;
            default:
                break;
                // failure
            }

            if (wire1Distance.find(pos) == wire1Distance.end())
            {
                wire1Distance[pos] = ++distanceSoFar;
            }
            pathWire1.push_back(pos);
        }
    }

    distanceSoFar = 1;
    pos = zero;
    for (auto i : instr2)
    {
        int distance = std::stoi(std::string(i[{1,ranges::end}]));
        std::string direction = i[{0,1}];

        for (int j=0; j < distance; ++j)
        {
            switch (direction[0])
            {
            case 'L':
                pos.first -= 1;
                break;
            case 'R':
                pos.first += 1;
                break;
            case 'U':
                pos.second += 1;
                break;
            case 'D':
                pos.second -= 1;
                break;
            default:
                break;
                // failure
            }
            if (wire2Distance.find(pos) == wire2Distance.end())
            {
                wire2Distance[pos] = ++distanceSoFar;
            }

            pathWire2.push_back(pos);
        }
    }

    this->wire1Points = pathWire1;
    this->wire2Points = pathWire2;

    std::sort(pathWire1.begin(), pathWire1.end());
    std::sort(pathWire2.begin(), pathWire2.end());
    std::set_intersection(pathWire1.begin(), pathWire1.end(),
                        pathWire2.begin(), pathWire2.end(),
                        std::back_inserter(results));

    auto p = results[0]; // sorted so first one is closest
    shortestDistance = std::abs(p.first) + std::abs(p.second); 

    status = SolvedStatus::SolvedPart1;

    /*
    for (auto p : res)
    {
        //std::cout << p.first + p.second << '\n';
    }
    */
    // std::vector<std::pair<int,int>> res2;
  //auto cross = ranges::view::set_intersection(pathWire1, pathWire2, std::back_inserter(res2));// , [](const std::pair<int,int>& a, const std::pair<int,int>& b){return a.first < b.first;});
 //ranges::sort(pathWire1);
 //ranges::sort(pathWire2);
   // auto cross = ranges::view::set_intersection(pathWire1, pathWire2, [](const std::pair<int,int>& a, const std::pair<int,int>& b){return a.first < b.first;});
    // add coords to 2nd vector
    //auto instr1 = wire1 | ranges::v3::view::split(',')
    //| ranges::v3::view::slice(1, ranges::v3::end)
    //| ranges::v3::to_vector;
    /*
    for (auto each : instr1)
    {
        auto number = each | ranges::slice(1, ranges::end);
                            //| ranges::to<std::string>(); // ::transform([] (auto && x) { return std::string(x); });
        std::string tmp = std::string(each) ;
        char direction = tmp[0];
        std::cout << direction << ' '  << number << '\n';
    }
    */

//std::set_intersection
// ranges::sort(r1)
// ranges::sort(r2)
//ranges::view::set_intersection(r1, r2)
}

template <class T>
void Day03<T>::solvePart2() 
{
    
    //auto tmp = ranges::min_element(results, [&](auto p1, auto p2) // TODO this would be nice
    auto tmp = std::min_element(results.begin(), results.end(), [&](auto p1, auto p2)
    {
        int a = wire1Distance[p1] + wire2Distance[p1];
        int b = wire1Distance[p2] + wire2Distance[p2];

        return a < b;
    });

    shortestCombinedDistance = wire1Distance[*tmp] + wire2Distance[*tmp];
}

}

template class year2019::Day03<std::string>;