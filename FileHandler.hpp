#pragma once
#include <iostream>
#include "DynamicList.hpp"
#include <fstream>
#include<sstream>
#include <vector>


//reading and writting to files in gen.

class FileHandler {
private:
    std::string file;
public:
    FileHandler(std::string file);
    DynamicList<std::string> readLines();
    void write(std::string content);
    static DynamicList<std::string> splitString(std::string content, char c);
};