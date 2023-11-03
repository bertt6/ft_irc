#include "commands.hpp"

void SendToClient1(int clientSocket, const std::string& message) {
    string sending = message + "\r\n";
    send(clientSocket, sending.c_str(), sending.size(), 0);
}

void Commands::whoCmd(User& user, int clientSocket) {
    if (user.getNickName().empty()) {
        string clientReq = "Not found!\n";
        SendToClient1(clientSocket, clientReq);
    }
    else {
        string clientReq = "[NICK] : " + user.getNickName() + "\n";
        SendToClient1(clientSocket, clientReq);
    }
}