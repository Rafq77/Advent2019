#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <fstream> 
#include <iterator> 

#include <filesystem> 

// this class should read out from file and parse the input to an array of subsequent inputs.
template <class T>
class Input
{
public:
    Input();
    Input(std::initializer_list<T> initializerList);
    virtual ~Input();

    static Input fromFile(std::string _fileName);
    static Input fromRaw(T rawInput);
    bool isValidInputLoaded();
    bool fileExists();
    void read();
    typename std::vector<T>::iterator begin();
    typename std::vector<T>::iterator end();
    
private:
    std::vector<T> input;
    std::string fileName = "";
};
