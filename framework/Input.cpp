#include "Input.hpp"

using namespace std::string_view_literals;

Input::Input() {}

Input::Input(std::initializer_list<std::string> initializerList)
: input(initializerList)
{}

Input::~Input() {}

Input Input::fromFile(std::string _fileName)
{
    Input instance;
    instance.fileName = _fileName;
    instance.read();
    return std::move(instance);
}

Input Input::fromString(std::string rawInput)
{
    Input instance;
    for (const char & character : rawInput)
    {
        instance.input.push_back({character});
    }
    return std::move(instance);
}

bool Input::isValidInputLoaded()
{
    return (input.size() > 0);
}

bool Input::fileExists()
{
    return std::filesystem::exists(fileName);
}

void Input::read()
{
    if (fileExists())
    {
        input.clear();
        std::ifstream infile(fileName);
        auto tmpInput = std::vector<std::string>(std::istream_iterator<std::string>(infile),{});

        if (tmpInput.size() == 1)
        {
            for (auto c : tmpInput.front())
            {
                input.push_back({c});
            }
        } else 
        {
            input = tmpInput;
        }

        /*
        auto input = std::ifstream("day16/input.txt", std::ios::in);
        for(std::string line; std::getline(input, line); )
            lines.push_back(line);
            */

        /*
        std::vector<YourObjectClass>    data;
        std::remove_copy_if(std::istream_iterator<YourObjectClass>(file),
                std::istream_iterator<YourObjectClass>(),
                std::back_inserter(data),
                YourFilter
                );
        */
    }
    else 
    {
        static std::string_view msg = "File Not Found"sv;
        throw std::runtime_error(std::string(msg));
    }
}

std::vector<std::string>::iterator Input::begin()
{
    return input.begin();
}

std::vector<std::string>::iterator Input::end()
{
    return input.end();
}
