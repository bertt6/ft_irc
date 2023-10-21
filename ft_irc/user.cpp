#include "user.hpp"

string User::getName() {
    return this->_name;
}

void User::setName(string surname) {
    this->_surname = surname;
}

string User::getSurName() {
    return this->_surname;
}

void User::setSurName(string surname) {
    this->_surname = surname;
}

string User::getNickName() {
    return this->_nickname;
}

void User::setNickName(string nickname) {
    this->_nickname = nickname;
}


