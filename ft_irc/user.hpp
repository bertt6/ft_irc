#ifndef USER_HPP
# define USER_HPP

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class User {
    public:
        string  realName;
        string  userName;
        bool    _isAuth;
        bool    _isRegister;

        string  getNickName();
        void    setNickName(string name);

};

#endif