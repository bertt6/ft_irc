#ifndef USER_HPP
# define USER_HPP

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class User {

    private:
        string  realName;
        string  userName;
        string  nickName;

    public:
        bool    _isAuth;
        bool    _isRegister;
        bool    _isNicked;
        bool    _isUser;

        string  getNickName();
        void    setNickName(string);

        string  getRealName();
        void    setRealName(string);

        string  getUserName();
        void    setUserName(string);
};

#endif
