#include "menu.hpp"
#include "user.hpp"
#include "Notification.hpp"

void Menu::displayMainMenu(){
 std::cout << "Select one of the following options" << std::endl;
    std::cout << "1- Edit Profile\n2- Create a Post\n3- Find users to follow\n4- View Notifications\n5- View followed users\n6- View your posts" << std::endl;
    std::cout << "enter your choice: ";
    int choice;
    std::cin >> choice;
     if (choice==1)
    {
        User u;
        u.editProfile();
    }
    else if (choice==2)
    {
    User c;
        c.createPost();
    }
        else if (choice==3)
    {
    User f;
        f.sendRequest();
    }
        else if (choice==4)
    {
    Notification v;
        v.viewNote();
    }
            else if (choice==5)
    {
    User u;
        u.editProfile();
    }
    else
    {
        std::cout << "Error: Please input either 1 or 2" << std::endl;
        Menu m;
        m.displayMainMenu();
    }
}