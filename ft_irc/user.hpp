#ifndef USER_HPP
# define USER_HPP

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class User {
    private: 
        string  _nickName;
        string  _realName;
        bool    _isAuth;
        bool    _isRegister;
        bool    _isPass;
    public:
        string  realName;
        string  userName;
        bool    _isPassed;  //ayni seyler niye public olarakta var???
        int     haveNick;
        string  getNickName();
        void    setNickName(string name);

};

#endif