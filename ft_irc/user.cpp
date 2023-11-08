#include "user.hpp"

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

