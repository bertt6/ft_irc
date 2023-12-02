#include "user.hpp"

User::User() 
{
    this->_isAuth = false;
    this->_isNicked = false;
    this->_isRegister = false;
    this->_isUser = false;
}

User::User(int socket)
{
    this->socket = socket;
}

string User::getNickName() {
    return this->nickName;
}

void User::setNickName(string nickName) {
    this->nickName = nickName;
}

string User::getRealName() {
    return this->realName;
}

void User::setRealName(string realName) {
    this->realName = realName;
}

string User::getUserName() {
    return this->userName;
}

void User::setUserName(string userName) {
    this->userName = userName;
}

void User::setupClientName() {
    char getHostName[64];

    int res = gethostname(getHostName, 64);
    if(!res)
    {
        cout << "Hostname Error!!" << endl;
        exit(1);
    }
    string hostNameStr(getHostName);
    string client = "!@" + hostNameStr;
    this->clientName = client;
}

string User::getClientName() {
    return this->clientName;
}

void User::setClientName(string name) {
    this->clientName = name;
}

void User::setSocket(int socket) {
    this->socket = socket;
}
