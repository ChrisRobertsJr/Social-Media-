#include <iostream>
#include "FileHandler.hpp"

class Authentication {
private:
    std::string name;
    std::string username;
    std::string password;

public:
    void displayMenu();
    void setNewAcc(std::string n, std::string u, std::string p);
    void signup();
    void login();
    
};










