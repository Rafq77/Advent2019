#include "Input.hpp"

using namespace std::string_view_literals;

template <class T>
Input<T>::Input() {}

template <class T>
Input<T>::Input(std::initializer_list<T> initializerList)
: input(initializerList)
{}

template <>
Input<std::string>::Input(std::string string)
{
    for (auto item : string)
    {
        input.push_back({item});
    }
}

template <class T>
Input<T>::Input(T string)
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

template <>
std::vector<std::string> Input<std::string>::readFromFile()
{
    std::vector<std::string> fileLines;

    std::ifstream infile(fileName);
    fileLines = std::vector<std::string>(std::istream_iterator<std::string>(infile), {});

    if (fileLines.size() == 1)
    {
        std::vector<std::string> tmpVector;
        // special case, need to separate by character!
        for (auto c : fileLines.front())
        {
            tmpVector.push_back({c});
        }
        fileLines = tmpVector;
    } 

    return fileLines;
}

template <class T>
std::vector<T> Input<T>::readFromFile()
{
    return std::vector<T>(std::istream_iterator<T>(std::ifstream{fileName}), {});
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
template class Input<int64_t>;