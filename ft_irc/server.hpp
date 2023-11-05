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
        string _password;
        User user;
        Commands commands;
    public:
        Server(int port);
        void Start();
        void handleCmd(std::string string, int clientSocket);
        void setPassword(string);
        string getPassword();

};

void SendToClient(int clientSocket, const std::string& message);

#endif
