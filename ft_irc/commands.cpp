#include "commands.hpp"

void SendToClient(int clientSocket, const std::string& message) {
    string sending = message + "\r\n";
    send(clientSocket, sending.c_str(), sending.size(), 0);
}

string Commands::cmd(std::string& wholeMsg) {
    return (wholeMsg.substr(0, wholeMsg.find(' ')));
}

void showAscii(string msg) {
    int i = 0;
    int cha; 
    cout << "------------------------" << endl;
    while(msg[i]) {
        cha = msg[i];
        cout << i << " " << cha << endl; 
        i++;
    }
    cha = msg[4];
    cout << "5 " << cha << endl;
    cout << endl << "------------------------" << endl;
}

void Commands::findCmd(User &user, int clientSocket, string msg, string password) {
    string parsedCmd = cmd(msg);
    cout << "Command is : " << parsedCmd << endl;
    showAscii(parsedCmd);
    if (parsedCmd == "WHO\n")
        this->whoCmd(user, clientSocket);
    else if (parsedCmd == "NICK" && user._isPassed)
        this->nickCmd(user, clientSocket, msg);
    else if(parsedCmd == "PASS")
        this->passCmd(user, clientSocket, msg, password);
    else if(parsedCmd == "EXIT")
        exit(1);
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

void Commands::passCmd(User& user, int clientSocket, string msg, string svPasswd) {
    (void)user;
    string passwd;
    string message;
    passwd = msg.substr(5, msg.find(' '));
    svPasswd = svPasswd + '\n';
    cout << "Passwd is : " << passwd << endl;
    cout << "--------------" << "ARG PASSWD " << "--------------" << endl;
    showAscii(svPasswd);    
    cout << "--------------" << "PASS PASSWD " << "--------------" << endl;
    showAscii(passwd);
    if(!passwd.empty() && passwd == svPasswd && !user._isPassed) {
        message = "You're passed now! You can use NICK command!\n";
        SendToClient(clientSocket, message);
        user._isPassed = true;
    }
    else if (passwd.empty() && passwd != svPasswd) {
        message = "Wrong password!\n";
        SendToClient(clientSocket, message);
    }
}