#include "server.hpp"

void Server::setPassword(string password) {
    _password = password;
}

string Server::getPassword() {
    return _password;
}

Server::Server(int port) {
    _serverPort = port;
    _serverSocket = -1;

    memset(&_serverAddr, 0, sizeof(_serverAddr));

    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    cout << "[DEBUG]SERVER SOCKET : " << _serverSocket << endl;
    if (_serverSocket < 0) {
        perror("Error: Socket can't created");
        exit(1);
    }

    _serverAddr.sin_family = AF_INET;
    _serverAddr.sin_port = htons(_serverPort);
    _serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(_serverSocket, (struct sockaddr*)&_serverAddr, sizeof(_serverAddr)) < 0) {
        perror("Error: Connection error");
        exit(1);
    }

    cout << "Connection succesful..." << endl;

    if (listen(_serverSocket, 10) == 0) {
        cout << "Server listening..." << endl;
    } else {
        perror("Error: Listen error!");
        exit(1);
    }
}


void Server::Start() {
    fd_set readSet;
    std::vector<int> _clientSockets;
    int maxFd = _serverSocket;
    char getHostName[64];

    int res = gethostname(getHostName, 64);
    if(res == -1) {
        std::cerr << "Host error!" << endl;
    }
    string temp(getHostName);
    this->hostName = temp;
    while (true) {
        FD_ZERO(&readSet);
        FD_SET(_serverSocket, &readSet);

        for (size_t i = 0; i < _clientSockets.size(); i++) {
            int clientSocket = _clientSockets[i];
            FD_SET(clientSocket, &readSet);
            if (clientSocket > maxFd) {
                maxFd = clientSocket;
            }
        }

        int activity = select(maxFd + 1, &readSet, NULL, NULL, NULL);

        if (activity < 0) {
            perror("Error: Select error!");
            exit(1);
        }

        if (FD_ISSET(_serverSocket, &readSet)) {
            int newSocket = accept(_serverSocket, (struct sockaddr*)&_newAddr, &_addrSize);
            if (newSocket < 0) {
                perror("Error: Connection rejected!");
                exit(1);
            }

            cout << "Conntection accepted! " << newSocket << endl;
            _clientSockets.push_back(newSocket);
            this->Users.insert(std::make_pair(maxFd, User()));
            std::string welcomeMessage = this->hostName + " :Welcome to FT_IRC!\n";
            SendToClient(newSocket, welcomeMessage);

        }

        for (size_t i = 0; i < _clientSockets.size(); i++) {
            int _clientSocket = _clientSockets[i];
            if (FD_ISSET(_clientSocket, &readSet)) {
                char buffer[1024];
                memset(buffer, 0, sizeof(buffer));
                int bytesRead = recv(_clientSocket, buffer, 1024, 0);
                
                string message(buffer);
                if(message.size()) {
                    handleCmd(message, _clientSocket, _password);
                }
                if (bytesRead <= 0) {
                    cout << _clientSocket << " Connection closed..." << endl;     
                    resetServer(_clientSocket);           
                    close(_clientSocket);
                    _clientSockets.erase(_clientSockets.begin() + i);
                } 
                else {
                    cout << "Client " << _clientSocket << ": " << buffer << endl;
                    // for (size_t j = 0; j < _clientSockets.size(); j++) {
                    //     int otherSocket = _clientSockets[j];
                    //     if (otherSocket != _clientSocket) {
                    //         send(otherSocket, buffer, bytesRead, 0);
                    //     }
                    // } YAZILAN KOMUTLAR DİĞER CLİENT'LERDE GÖZÜKMESİN DİYE BURAYI YORUM SATIRINA ALDIM
                }
            }
        }
    }
    close(_serverSocket);
}

void Server::handleCmd(string msg, int clientSocket, string password) {
    this->commands.findCommand(this->Users, clientSocket, msg, password);
}

void Server::resetServer(int _clientSocket) {
    this->Users.erase(_clientSocket);
    
    //unit test
    cout << this->Users[_clientSocket].getNickName() << endl;
    
}