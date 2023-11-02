#ifndef EXECUTE_HPP
# define EXECUTE_HPP

#include "server.hpp"
#include "user.hpp"
#include <ctype.h>

class Exec {
    public:
        Exec();
        std::string command;
        std::string second_part;
        string server_string;
        void parseMsg();
        std::string cmd(string&);
        User user;
};

#endif