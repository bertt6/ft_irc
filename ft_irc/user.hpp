#ifndef USER_HPP
# define USER_HPP

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class User {
    private: 
        string _name;
        string _surname;
        string _nickname;
        int     fd;
    public:
        string getName();
        void    setName(string name);
        string getSurName();
        void    setSurName(string name);
        string getNickName();
        void    setNickName(string name);

};

//pool 
//
#endif