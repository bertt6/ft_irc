#include "commands.hpp"

void SendToClient(int clientSocket, const std::string& message) {
    string sending = message + "\r\n";
    send(clientSocket, sending.c_str(), sending.size(), 0);
}

string Commands::cmd(std::string& wholeMsg) {
    return (wholeMsg.substr(0, wholeMsg.find(' ')));
}

void Commands::findCmd(User &user, string msg, int clientSocket) {
    string parsedCmd = cmd(msg);

    if (parsedCmd == "WHO\n")
        this->whoCmd(user, clientSocket);
    else if (parsedCmd == "NICK")
        this->nickCmd(user, clientSocket, msg);
}

void Commands::whoCmd(User& user, int clientSocket) {
    if (user.getNickName().empty()) {
        string clientReq = "Not found!\n";
        SendToClient(clientSocket, clientReq);
    }
    else {
        string clientReq = "[NICK] : " + user.getNickName() + "\n";
        SendToClient(clientSocket, clientReq);
    }
}

void Commands::nickCmd(User& user, int clientSocket, string msg) {
    user.setNickName(msg.substr(5, msg.find(' ') + 1));
    string message = "Nick changed! Updated nick : " + user.getNickName() + "\n";
    SendToClient(clientSocket, message);
}
