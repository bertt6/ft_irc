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
#include <sstream>

using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::map;

class Commands {
    private:

    public:
        string parsedCmd;
        vector<string> args; 
        void Exit(void);
        void Who(User&, int);
        void Usèr(User&, int, string);
        void Ping(User&, int, string);
        void Pass(User&, int, string, string);
        void Nick(map<int, User> &, int, string);
        void UnknowCmd(User&, int, string);
        
        void setArgs(string);
        string cmd(string&);
        void findCommand(map<int, User> &, int, string, string);
};

void SendToClient(int, const std::string&);

#endif
