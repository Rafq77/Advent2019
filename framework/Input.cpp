#include "Input.hpp"

using namespace std::string_view_literals;

template <class T>
Input<T>::Input() {}

template <class T>
Input<T>::Input(std::initializer_list<T> initializerList)
: input(initializerList)
{}

template <class T>
Input<T>::~Input() {}

template <class T>
Input<T> Input<T>::fromFile(std::string _fileName)
{
    Input instance;
    instance.fileName = _fileName;
    instance.read();
    return std::move(instance);
}
template <class T>
Input<T> Input<T>::fromRaw(T rawInput)
{
    Input instance;
    for (const char & character : rawInput)
    {
        instance.input.push_back({character});
    }
    return std::move(instance);
}

template <class T>
bool Input<T>::isValidInputLoaded()
{
    return (input.size() > 0);
}

template <class T>
bool Input<T>::fileExists()
{
    return std::filesystem::exists(fileName);
}

template <class T>
void Input<T>::read()
{
    if (fileExists())
    {
        input.clear();
        std::ifstream infile(fileName);
        auto tmpInput = std::vector<T>(std::istream_iterator<T>(infile),{});

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

template <class T>
typename std::vector<T>::iterator Input<T>::begin()
{
    return input.begin();
}

template <class T>
typename std::vector<T>::iterator Input<T>::end()
{
    return input.end();
}

template class Input<std::string>;