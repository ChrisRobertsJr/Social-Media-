#include <iostream>

class User{
private:
    std::string username;
    std::string password;
    std::string name;

public:
    void user(std::string n,std::string u, std::string p);
    void createPost();
    void editProfile();
    void sendRequest();

};