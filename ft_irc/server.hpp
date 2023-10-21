#ifndef SERVER_HPP
# define SERVER_HPP

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include "user.hpp"

class Server {
    public:

    private:
        Server();
        int serverSocket;
        struct sockaddr_in serverAddr;
        int clientSocket;
        char buffer[1024];


};


#endif