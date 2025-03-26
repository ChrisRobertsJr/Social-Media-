#include "Notification.hpp"
#include "FileHandler.hpp"





void Notification:: viewNote(){
    std::cout << "View Notifications---------------" << std::endl;
    std::cout << "what is your username: ";
    std::string username;
   std:: cin >> username;
    FileHandler checkUsers("intial_user.txt");
    DynamicList<std::string> userList = checkUsers.readLines();
    for (int i=1; i < userList.getSize(); i++){
        DynamicList<std::string> tokens = FileHandler::splitString(userList[i], ',');
       if(tokens[1]==username){
        break;
       }
       else{
        std::cout << " error: please enter a valid username." << std::endl;
        viewNote();
       }
    } 

     std::cout<< "you have a friend request from"<< std::endl;
    
}