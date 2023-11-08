#include "../commands.hpp"

void Commands::Nick(map<int, User> &users, int clientSocket, string msg) { 
    map<int, User>::iterator it = users.begin();
    // if(!msg) {
    //     SendToClient
    // }
    while (it->first) {
        if (it->second.getNickName() == msg.substr(5, msg.find(' ') + 1)) {
            SendToClient(clientSocket, "Nick already used!\n");
            return;
        }
        it++;
    }

    users[clientSocket].setNickName(msg.substr(5, msg.find(' ') + 1));
    string message = "Nick changed! Updated nick : " + users[clientSocket].getNickName() + "\n";
    SendToClient(clientSocket, message);
    if (users[clientSocket]._isUser) {
        users[clientSocket]._isRegister = true;
        SendToClient(clientSocket, "You are registered now!\n");
    }
    users[clientSocket]._isNicked = true;
}