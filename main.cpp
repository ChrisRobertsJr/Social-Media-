#include "FileHandler.hpp"
#include "Authentication.hpp"
#include "user.hpp"
#include <fstream>

int main() {
    std::cout << "Social media App--------------" << std::endl;
    FileHandler file("intial_users.txt");
    Authentication test;
    test.displayMenu();
    // User user;
    // user.editProfile();
    return 0;
}