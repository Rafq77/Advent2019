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
    std::vector<std::pair<int, int>> pathWire1;
    std::vector<std::pair<int, int>> pathWire2;

    //std::pair<int,int> zero = std::make_pair(0,0);
    std::pair<int,int> zero = {0,0};
    std::pair<int,int> pos = zero;

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
            pathWire1.push_back(pos);
        }

        //if (direction[0] == 'D')
         //   std::cout << direction << distance << '\n';
        // struct Point { int x, int y } or std::pair (special case tuple)// std::make_pair
        //record path1, step by step (add coords to vector)
    }

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
            pathWire2.push_back(pos);
        }
    }

    std::vector<std::pair<int,int>> res;
    for (const std::pair<int,int>& p1 : pathWire1)
    {
        for (const std::pair<int,int>& p2 : pathWire2)
        {
            if (p1.first == p2.first && p1.second == p2.second)
            {
                res.push_back(p1);
            }
        }
    }

    /*
    std::set_intersection(pathWire1.begin(), pathWire1.end(),
                        pathWire2.begin(), pathWire2.end(),
                        std::back_inserter(res), [](std::pair<int,int> a, std::pair<int,int> b) 
                        {
                            return (a.first == b.first && a.second == b.second);
                        });
                        */

    //cheat
    auto p = res[0];
    shortestDistance = std::abs(p.first) + std::abs(p.second);
    for (auto p : res)
    {
        //std::cout << p.first + p.second << '\n';
    }
    

// ranges::sort(pathWire1);
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
}

}

template class year2019::Day03<std::string>;