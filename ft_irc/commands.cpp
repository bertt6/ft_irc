#include "commands.hpp"

string Commands::cmd(std::string& wholeMsg) {
    wholeMsg.erase(remove(wholeMsg.begin(), wholeMsg.end(), '\n'), wholeMsg.end());
    wholeMsg.erase(remove(wholeMsg.begin(), wholeMsg.end(), '\r'), wholeMsg.end());
    return (wholeMsg.substr(0, wholeMsg.find(' ')));
}

void checkAscii(string str) {
    int chk = 0;
    for(int i = 0; str[i]; i++) {
        chk = str[i];
        cout << "[CHECK][" << i << "]" << chk << endl;
    }
}

void Commands::findCommand(std::map<int, User> &Users, int clientSocket, string msg, string password) {
    string parsedCmd = cmd(msg);
    //cout << "Command is : [" << parsedCmd << "]" << endl;
    checkAscii(parsedCmd);
    if (parsedCmd == "WHO")
        this->Who(Users[clientSocket], clientSocket);
    else if (parsedCmd == "NICK")
        this->Nick(Users, clientSocket, msg);
    else if (parsedCmd == "PASS")
        this->Pass(Users[clientSocket], clientSocket, msg, password);
    else if (parsedCmd == "USER")
        this->Usèr(Users[clientSocket], clientSocket, msg);
    else if (parsedCmd == "PING")  
        this->Ping(Users[clientSocket], clientSocket, parsedCmd);
    else if (parsedCmd == "QUIT")
        this->Quit(Users[clientSocket], clientSocket, msg);
    else
        this->UnknowCmd(Users[clientSocket], clientSocket, parsedCmd);
}

void    Commands::setArgs(string msg) {
    std::istringstream iss(msg);
    std::string token;

    while (iss >> token) {
        args.push_back(token);
    }
}

void    Commands::UnknowCmd(User &user, int clientSocket, string msg) {
    SendToClient(clientSocket, user.getNickName() + ":" + msg + " :Unknown command\n");
}

void    SendToClient(int clientSocket, const std::string& message) {
    string sending = message;
    send(clientSocket, sending.c_str(), sending.size(), 0);
}
