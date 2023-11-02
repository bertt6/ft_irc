#include "server.hpp"

string Server::cmd(std::string& wholeMsg) {
    return (wholeMsg.substr(0, wholeMsg.find(' ')));
}

void Server::FindCmd(string msg, int clientSocket) {
    string parsedCmd = cmd(msg);

    if(parsedCmd == "WHO\n") {
        if (this->user.getName().empty()) {
        string clientReq = "Bulunamadi\n";
        SendToClient(clientSocket, clientReq);
        } 
        else {
            string clientReq = "[Kullanici adiniz] : " + this->user.getName() + "\n";
            SendToClient(clientSocket, clientReq);
        }
    }
    if(parsedCmd == "NAME") {
        this->user.setName(msg.substr(5, msg.find(' ') + 1));
        string message = "Isim degistirildi. Güncel isim : " + user.getName() + "\n";
        SendToClient(clientSocket, message);
    }
}  

void Server::SendToClient(int clientSocket, const std::string& message) {
    string sending = message + "\r\n";
    send(clientSocket, sending.c_str(), sending.size(), 0);
}
