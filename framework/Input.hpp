#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <fstream> 
#include <iterator> 

#include <filesystem> 

// this class should read out from file and parse the input to an array of subsequent inputs.
//template <class T>
class Input
{
public:
    Input() {};
    //Input(const Input &) = delete;
    //Input(Input &&) = delete;
    //Input& operator=(const Input &) = delete;
    //Input& operator=(Input &&) = delete;
    
    Input(std::string fromFile);
    virtual ~Input();

    static Input fromFile(std::string _fileName)
    {
        Input instance;
        instance.fileName = _fileName;
        instance.read();
        return std::move(instance);
    }

    static Input fromString(std::string rawInput)
    {
        Input instance;
        for (const char & character : rawInput)
        {
            instance.input.push_back({character});
        }
        return std::move(instance);
    }

    bool isValidInputLoaded() 
    {
        return (input.size() > 0);
    }

    bool fileExists()
    {
        return std::filesystem::exists(fileName); 
    }

    void read()
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
            static const char* msg = "File Not Found"; // sv?
            throw std::runtime_error(msg); // TODO sv?
        }
    } 

    // TODO template this vector<string>
    std::vector<std::string>::iterator begin()
    {
        return input.begin();
    }

    std::vector<std::string>::iterator end()
    {
        return input.end();
    }

private:
    std::vector<std::string> input; //TODO  template
    std::string fileName = "";
};
