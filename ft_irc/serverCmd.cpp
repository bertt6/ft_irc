#include "server.hpp"

string Server::cmd(std::string& wholeMsg) {
    return (wholeMsg.substr(0, wholeMsg.find(' ')));
}

void learnAscii(string str) {
    int i = 0;
    int a = 0;
    while(str[i]) {
        a = str[i];
        cout << "[DEBUG] : " << a << endl;
        i++;
    }
}

void Server::FindCmd(string msg, int clientSocket) {
    string parsedCmd = cmd(msg);
    learnAscii(parsedCmd);

    if(parsedCmd == "WHO\n")
        commands.whoCmd(msg, clientSocket);
    if(parsedCmd == "NAME")
        commands.nameCmd(msg, clientSocket);

}  

void Server::SendToClient(int clientSocket, const std::string& message) {
    string sending = message + "\r\n";
    send(clientSocket, sending.c_str(), sending.size(), 0);
}
