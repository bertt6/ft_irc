#include "user.hpp"

string User::getNickName() {
    return this->_nickName;
}

void User::setNickName(string nickname) {
    this->_nickName = nickname;
    this->haveNick = 1;
}


