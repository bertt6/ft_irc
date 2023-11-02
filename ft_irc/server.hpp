#ifndef SERVER_HPP
#define SERVER_HPP

#include <netinet/in.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <vector>
#include "execute.hpp"
#include <string>
#include <map>
#include "user.hpp"
#include "commands.hpp"

using std::endl;
using std::cout;
using std::vector;
using std::string;

class Server {
    private:
        int _serverPort;
        int _serverSocket;
        struct sockaddr_in _serverAddr;
        struct sockaddr_in _newAddr;
        socklen_t _addrSize;
        
        std::map<int, std::string> _clientNames;
    public:
        Server(int port);
        void Start();
        void FindCmd(std::string string, int clientSocket);
        void SendToClient(int clientSocket, const std::string& message);
        string cmd(std::string& wholeMsg);
        User user;
        Commands commands;

};

#endif
