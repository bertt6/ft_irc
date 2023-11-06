#ifndef USER_HPP
# define USER_HPP

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class User {
    private: 
        string  _nickname;
        //bool    _isAuth;
        //int     _fd; buraya clientsocket numarasını koy (yani kaçıncı fd olduğu)
    public:
        bool    _isPassed;
        int     haveNick;
        string  getNickName();
        void    setNickName(string name);

};

#endif