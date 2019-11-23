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
    Input();
    virtual ~Input();

    static Input fromFile(std::string _fileName);
    static Input fromString(std::string rawInput);
    bool isValidInputLoaded();
    bool fileExists();
    void read();
    std::vector<std::string>::iterator begin();
    std::vector<std::string>::iterator end();
    
private:
    std::vector<std::string> input; //TODO  template
    std::string fileName = "";
};
