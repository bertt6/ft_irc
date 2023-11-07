#include "commands.hpp"

string Commands::cmd(std::string& wholeMsg) {
    return (wholeMsg.substr(0, wholeMsg.find(' ')));
}

void Commands::findCommand(std::map<int, User> &Users, int clientSocket, string msg, string password) {
    string parsedCmd = cmd(msg);
    cout << "Command is : " << parsedCmd << endl;
    if (parsedCmd == "WHO\n")
        this->Who(Users[clientSocket], clientSocket);
    else if (parsedCmd == "NICK" && Users[clientSocket]._isPassed)
        this->Nick(Users, clientSocket, msg);
    else if(parsedCmd == "PASS")
        this->Pass(Users[clientSocket], clientSocket, msg, password);
    else if(parsedCmd == "EXIT")
        this->Exit();
    else if(parsedCmd == "USER")
        this->UserC(Users[clientSocket], clientSocket, msg);
}

void Commands::setArgs(string msg) {
    std::istringstream iss(msg);
    std::string token;
    
    while (iss >> token) {
        args.push_back(token);
    }
}

void SendToClient(int clientSocket, const std::string& message) {
    string sending = message;
    send(clientSocket, sending.c_str(), sending.size(), 0);
}
