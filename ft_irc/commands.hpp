#ifndef COMMANDS_HPP
# define COMMANDS_HPP

#include "server.hpp"

class Commands : public Server {
    private:
        int _clientSocket;
    public:
        void nameCmd(string, int);
        void whoCmd(string msg, int clientSocket);
};

#endif