#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string_view>

#include <filesystem> // does it work? TODO

// this class should read out from file and parse the input to an array of subsequent inputs.
//template <class T>
class Input
{
public:
    Input() {};
    Input(const Input &) = delete;
    Input(Input &&) = delete;
    Input& operator=(const Input &) = delete;
    Input& operator=(Input &&) = delete;
    
    Input(std::string fromFile);
    virtual ~Input();

    bool isValid() 
    {
        return (input.size() > 0);
    }

    bool fileExists()
    {
        return std::filesystem::exists(fileName); // TODO file system?
    }

    void read()
    {
        if (fileExists())
        {
            // std::ifstream ifstream(fileName);  TODO
            // std::read(std::cin, ifstream); // smth like that
        }
        else 
        {
            static const char* msg = "File Not Found"; // sv?
            throw std::runtime_error(msg); // TODO sv?
        }
    } 
private:
    std::vector<std::string> input;
    std::string fileName = "";
};
