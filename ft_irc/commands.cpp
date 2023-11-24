#include "commands.hpp"

string Commands::cmd(std::string& wholeMsg) {
    wholeMsg.erase(remove(wholeMsg.begin(), wholeMsg.end(), '\n'), wholeMsg.end());
    return (wholeMsg.substr(0, wholeMsg.find(' ')));
}

string Commands::arg(std::string& wholeMsg) {
    wholeMsg.erase(remove(wholeMsg.begin(), wholeMsg.end(), '\n'), wholeMsg.end());
    return (wholeMsg.substr(wholeMsg.find(' ') + 1));
}

void Commands::findCommand(map<int, User> &Users, vector<Channel> &channels, int clientSocket, string msg, string password) {
    string parsedCmd = this->cmd(msg); args.begin();
    setArgs(msg);
    //cout << "Command is : [" << parsedCmd << "]" << endl;
    if (parsedCmd == "WHO\n")
        this->Who(Users[clientSocket], clientSocket);
    else if (parsedCmd == "NICK")
        this->Nick(Users, clientSocket, msg);
    else if (parsedCmd == "PASS")
        this->Pass(Users[clientSocket], clientSocket, msg, password);
    else if (parsedCmd == "EXIT")
        this->Exit();
    else if (parsedCmd == "USER")
        this->Usèr(Users[clientSocket], clientSocket, msg);
    else if (parsedCmd == "PING")  
        this->Ping(Users[clientSocket], clientSocket, parsedCmd);
    else if (parsedCmd == "JOIN")
        this->Join(Users[clientSocket], channels, clientSocket);
    else if (parsedCmd == "test")
    {
        cout << endl << endl;
        vector<Channel>::iterator it = channels.begin();
        vector<User *> admins = (*it).getAdmins();

        vector<User *>::iterator admin = admins.begin();
        //vector<User *>::iterator admin = (*it).getAdmins().begin();

        cout << (*admin)->getNickName() << endl;
        //cout << (*user)->getNickName() << endl;
        cout << (*it).getName() << endl;
        cout << (*it).userIsTheAdmin(Users[clientSocket].getNickName()) << endl;
        cout << (*it).userOnTheChannel(Users[clientSocket].getNickName()) << endl;
    }
    else
        this->UnknowCmd(Users[clientSocket], clientSocket, parsedCmd);
    args.clear();
}

void    Commands::setArgs(string msg) {
    std::istringstream iss(msg);
    string token;

    while (iss >> token)
        args.push_back(token);
}

void    Commands::UnknowCmd(User &user, int clientSocket, string msg) {
    SendToClient(clientSocket, user.getNickName() + ":" + msg + " :Unknown command\n");
}

void    SendToClient(int clientSocket, const std::string& message) {
    string sending = message;
    send(clientSocket, sending.c_str(), sending.size(), 0);
}
