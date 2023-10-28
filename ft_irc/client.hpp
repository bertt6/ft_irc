#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <netinet/in.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class Client {
public:
    Client(const char* serverIP, int serverPort);
    void Connect();
    void StartCommunication();

private:
    int clientSocket;
    const char* serverIP;
    int serverPort;
    struct sockaddr_in serverAddr;
};

#endif
