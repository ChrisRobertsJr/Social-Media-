#include "FileHandler.hpp"

//constructor, initiailize the private variables
FileHandler::FileHandler(std::string file){
    this->file = file;
}

void FileHandler::write(std::string content){
    std::ofstream out(file);
    out << content;
    out.close();
}

//we can reuse content as an argument bc each fxn is isolated
DynamicList<std::string> FileHandler::splitString(std::string content, char c){
    std::stringstream ss(content);
    DynamicList<std::string> out;
    std::string to;
    while(getline(ss,to,c)){
        out.push_back(to);
    }

    return out;
}

DynamicList<std::string> FileHandler::readLines(){
    std::ifstream in(file);
    std::stringstream ss;
    in >> ss.rdbuf();
    std::string s = ss.str();

    return splitString(s,'\n');
}