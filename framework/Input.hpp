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
    Input(T string);
    virtual ~Input();

    static Input fromFile(std::string _fileName);
    std::vector<T> readFromFile();
    bool isValidInputLoaded();
    bool fileExists();
    void read();
    typename std::vector<T>::iterator begin();
    typename std::vector<T>::iterator end();
    const std::vector<T>& getRaw() const { return input; };
    
private:
    std::vector<T> input;
    std::string fileName = "";
};
