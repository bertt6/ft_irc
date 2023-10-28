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

class Server {
public:
    Server(int port);
    void Start();

private:
    int serverPort;
    int serverSocket;
    struct sockaddr_in serverAddr;
    struct sockaddr_in newAddr;
    socklen_t addrSize;
};

#endif
