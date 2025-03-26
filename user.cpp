#include "user.hpp"
#include "FileHandler.hpp"
#include "Notification.hpp"

void User::user(std::string n,std::string u, std::string p){
    this->name=n;
    this->username=u;
    this->password=p;

}
void User:: createPost(){
    std::cout << "CreatePost --------------------" << std::endl;
    std::cout << "what is your username: ";
    std::string username;
    std::cin >> username;
    FileHandler checkUsers("intial_user.txt");
    DynamicList<std::string> userList = checkUsers.readLines();
    for (int i=1; i < userList.getSize(); i++){
        DynamicList<std::string> tokens = FileHandler::splitString(userList[i], ',');
       if(tokens[1]==username){
        break;
       }
       else{
        std::cout << " error: please try again" << std::endl;
        createPost();
       }
    } 
    std::cout << "Enter your post------------" << std::endl;
    std::string userpost;
    std::cin >> userpost;

    FileHandler posts("UserPosts.txt");
    DynamicList<std::string> lines = posts.readLines();
    lines.push_back(username+","+userpost);
    std::string s = "";
    for (int i=0; i <lines.getSize();i++){
        s += lines[i]+"\n";
    }
    posts.write(s);
    


}

void User:: editProfile(){
    std::cout << "Edit Profile--------------" << std::endl;
    std::cout << "What would you like to change?\n1 - name\n2 - username\n3 - password\nenter: ";
    int num;
    std::cin >> num;
    if(num==1)
    {
        std::cout << "enter your previous name: ";
        std::string oldName;
        std::cin >> oldName; 
        std::cout << "enter your current username: ";
        std::string username;
        std::cin >> username;
        std::cout << "enter your current password: ";
        std::string password;
        std::cin >> password;

        FileHandler checkUsers("intial_users.txt");
        //reads the txt and makes eachs line a string
        DynamicList<std::string> userList = checkUsers.readLines();
        for (int i = 1; i < userList.getSize(); i++) {
        //splits each line into indivitual strings at each comma
        DynamicList<std::string> tokens = FileHandler::splitString(userList[i], ',');
            if (tokens[0] == oldName) {

                std::cout << "What would you like your new name to be: ";
                std::string updatedName;
                std::cin >> updatedName;

                FileHandler addUser("intial_users.txt");
                DynamicList<std::string> lines = addUser.readLines();
                lines.push_back(updatedName+","+username+","+password);
                std::string s = "";
                for (int i=0; i <lines.getSize();i++){
                    s += lines[i]+"\n";
                }
                addUser.write(s);

                std::cout << "Updated name: " << tokens[0] << std::endl;
                break;
            }
        }
    }
    if(num==2)
    {
        std::cout << "enter your previous username: ";
        std::string oldUser;
        std::cin >> oldUser; 
        std::cout << "enter your current name: ";
        std::string name;
        std::cin >> name;
        std::cout << "enter your current password: ";
        std::string password;
        std::cin >> password;

        FileHandler checkUsers("intial_users.txt");
        //reads the txt and makes eachs line a string
        DynamicList<std::string> userList = checkUsers.readLines();
        for (int i = 1; i < userList.getSize(); i++) {
        //splits each line into indivitual strings at each comma
        DynamicList<std::string> tokens = FileHandler::splitString(userList[i], ',');
            if (tokens[1] == oldUser) {

                std::cout << "What would you like your new name to be: ";
                std::string updatedUser;
                std::cin >> updatedUser;

                FileHandler addUser("intial_users.txt");
                DynamicList<std::string> lines = addUser.readLines();
                lines.push_back(name+","+updatedUser+","+password);
                std::string s = "";
                for (int i=0; i <lines.getSize();i++){
                    s += lines[i]+"\n";
                }
                addUser.write(s);
                break;
            }
        }
    }

    if(num==3)
    {
        std::cout << "enter your previous password: ";
        std::string oldpass;
        std::cin >> oldpass; 
        std::cout << "enter your current username: ";
        std::string username;
        std::cin >> username;
        std::cout << "enter your current name: ";
        std::string name;
        std::cin >> name;

        FileHandler checkUsers("intial_users.txt");
        //reads the txt and makes eachs line a string
        DynamicList<std::string> userList = checkUsers.readLines();
        for (int i = 1; i < userList.getSize(); i++) {
        //splits each line into indivitual strings at each comma
        DynamicList<std::string> tokens = FileHandler::splitString(userList[i], ',');
            if (tokens[3] == oldpass) {

                std::cout << "What would you like your new name to be: ";
                std::string updatedpass;
                std::cin >> updatedpass;

                FileHandler addUser("intial_users.txt");
                DynamicList<std::string> lines = addUser.readLines();
                lines.push_back(name+","+username+","+updatedpass);
                std::string s = "";
                for (int i=0; i <lines.getSize();i++){
                    s += lines[i]+"\n";
                }
                addUser.write(s);
                break;
            }
        }
    }

}


void User::sendRequest(){
    std::cout << "Find Users to Follow---------------" << std::endl;
    std::cout << "what is your username: ";
    std::string username;
    std::cin >> username;

    FileHandler checkUsers("intial_users.txt");
    DynamicList<std::string> userList = checkUsers.readLines();
    for (int i=1; i < userList.getSize(); i++){
        DynamicList<std::string> tokens = FileHandler::splitString(userList[i], ',');
       if(tokens[1]==username){
        break;
       }
       else{
        std::cout << " error: please enter a valid username." << std::endl;
        sendRequest();
       }
    } 
    std::cout << "Who would you like to follow?" << std::endl;
    std::string request;
    std::cin >> request;
    FileHandler lookuser("intial_user.txt");
    DynamicList<std::string> followList = lookuser.readLines();
    for (int i=1; i < followList.getSize(); i++){
        DynamicList<std::string> tokens = FileHandler::splitString(userList[i], ',');
       if(tokens[1]==request){
        std::cout << "sent!";
        break;
       }
       else{
        std::cout << " error: please enter a valid username." << std::endl;
        sendRequest();
       }

    }
}