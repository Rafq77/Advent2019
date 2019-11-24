#include "Input.hpp"

using namespace std::string_view_literals;

template <class T>
Input<T>::Input() {}

template <class T>
Input<T>::Input(std::initializer_list<T> initializerList)
: input(initializerList)
{}

template <class T>
Input<T>::Input(T string)
{
    for (typename T::value_type item : string)
    {
        input.push_back({item});
    }
}

template <>
Input<int32_t>::Input(int32_t string)
{
    // be harmless
}

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
        input = readFromFile();
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
std::vector<T> Input<T>::readFromFile()
{
    std::vector<T> fileLines;

    std::ifstream infile(fileName);
    fileLines = std::vector<T>(std::istream_iterator<T>(infile), {});

    if (fileLines.size() == 1)
    {
        std::vector<T> tmpVector;
        // special case, need to separate by character!
        for (auto c : fileLines.front())
        {
            tmpVector.push_back({c});
        }
        fileLines = tmpVector;
    } 

    return fileLines;
}

template <>
std::vector<int32_t> Input<int32_t>::readFromFile()
{
    return std::vector<int32_t>(std::istream_iterator<int32_t>(std::ifstream{fileName}), {});
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
template class Input<int32_t>;