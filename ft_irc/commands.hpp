#ifndef COMMANDS_HPP
# define COMMANDS_HPP

#include <netinet/in.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <vector>
#include <string>
#include <map>
#include "user.hpp"

using std::endl;
using std::cout;
using std::vector;
using std::string;

class Commands {
    private:


    public:
        string parsedCmd;
        void whoCmd(User&, int);
};


#endif