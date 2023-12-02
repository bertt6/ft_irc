#ifndef USER_HPP
# define USER_HPP

#include <iostream>
#include <string>
#include <unistd.h>

using std::string;
using std::cout;
using std::endl;

class User {

    private:
        string  realName;
        string  userName;
        string  nickName;
        string  clientName;

    public:
        int     socket; 
        bool    _isAuth;
        bool    _isRegister;
        bool    _isNicked;
        bool    _isUser;
        string  hostname;

        User();
        User(int);

        string  getNickName();
        void    setNickName(string);

        string  getRealName();
        void    setRealName(string);

        string  getUserName();
        void    setUserName(string);

        void setupClientName();
        void setClientName(string);
        string getClientName();

        void setSocket(int);
};

#endif
