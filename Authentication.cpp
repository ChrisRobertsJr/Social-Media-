#include "Authentication.hpp"
#include "menu.hpp"

void Authentication:: displayMenu(){
    std::cout << "1 - log in\n2 - sign up" << std::endl;
    std::cout << "enter your choice: ";
    int choice;
    std::cin >> choice;
    if (choice==1)
    {
        login();
    }
    else if (choice==2)
    {
       signup();
    }
    else
    {
        std::cout << "Error: Please input either 1 or 2" << std::endl;
        displayMenu();
    }
    
}

void Authentication::setNewAcc(std::string n,std::string u, std::string p) {
    name = n;
    username = u;
    password = p;
}

void Authentication:: signup(){
    std::cout << "Sign Up by entering your Name, Username, and Password" << std::endl;
    std::cout << "Please enter your name:";
    std::cin >> name;
    std::cout <<"Please enter your username: ";
    std::cin >> username;

    FileHandler checkUsers("intial_user.txt");
    DynamicList<std::string> userList = checkUsers.readLines();
    for (int i=1; i < userList.getSize(); i++){
        DynamicList<std::string> tokens = FileHandler::splitString(userList[i], ',');
       if(tokens[1]==username){
        std::cout << " Username already exist!" << std::endl;
        signup();
        break;
       }
    } 

    std::cout << "please enter your password: ";
    std::cin >> password;
    
    FileHandler addUser("intial_users.txt");
    DynamicList<std::string> lines = addUser.readLines();
    lines.push_back(name+","+username+","+password);
    std::string s = "";
    for (int i=0; i <lines.getSize();i++){
        s += lines[i]+"\n";
    }
    addUser.write(s);

    Menu m;
    m.displayMainMenu();
}

void Authentication:: login(){
    // if statement to check username
    std::cout << "Please enter your Username: ";
    std::cin >> username;
    std::cout << "Please enter your password: ";
    std::cin >> password;

    FileHandler checkUsers("intial_users.txt");
    DynamicList<std::string> userList = checkUsers.readLines();
    bool success=false;
    for (int i=1; i < userList.getSize(); i++){
        DynamicList<std::string> tokens = FileHandler::splitString(userList[i], ',');
       if(tokens[1]==username && tokens[2]==password){
        success=true;
        break;
       }
    } 
    if(success==false){
        std::cout << "wrong" << std::endl;
        login();
        return;
    }

    Menu m;
    m.displayMainMenu();
}
