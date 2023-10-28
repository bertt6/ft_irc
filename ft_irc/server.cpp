#include "server.hpp"


Server::Server(int port) {
    serverPort = port;
    serverSocket = -1;

    memset(&serverAddr, 0, sizeof(serverAddr));

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "[DEBUG]SERVER SOCKET : " << serverSocket << std::endl;
    if (serverSocket < 0) {
        perror("Hata: Soket oluşturulamadı");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Hata: Bağlama başarısız");
        exit(1);
    }

    std::cout << "Bağlama başarılı..." << std::endl;

    if (listen(serverSocket, 10) == 0) {
        std::cout << "Sunucu dinleniyor..." << std::endl;
    } else {
        perror("Hata: Dinleme başarısız");
        exit(1);
    }
}

void Server::Start() {
    fd_set readSet;
    std::vector<int> clientSockets;
    int maxFd = serverSocket;

    while (true) {
        FD_ZERO(&readSet);
        FD_SET(serverSocket, &readSet);

        for (size_t i = 0; i < clientSockets.size(); i++) {
            int clientSocket = clientSockets[i];
            FD_SET(clientSocket, &readSet);
            if (clientSocket > maxFd) {
                maxFd = clientSocket;
            }
        }

        int activity = select(maxFd + 1, &readSet, NULL, NULL, NULL);

        if (activity < 0) {
            perror("Hata: Select hatası");
            exit(1);
        }

        if (FD_ISSET(serverSocket, &readSet)) {
            int newSocket = accept(serverSocket, (struct sockaddr*)&newAddr, &addrSize);
            if (newSocket < 0) {
                perror("Hata: Bağlantı kabul edilemedi");
                exit(1);
            }

            std::cout << "Bağlantı kabul edildi..." << std::endl;
            clientSockets.push_back(newSocket);
        }

        for (size_t i = 0; i < clientSockets.size(); i++) {
            int clientSocket = clientSockets[i];
            if (FD_ISSET(clientSocket, &readSet)) {
                char buffer[1024];
                memset(buffer, 0, sizeof(buffer));
                int bytesRead = recv(clientSocket, buffer, 1024, 0);
                if (bytesRead <= 0) {
                    std::cout << "Bağlantı kapatılıyor..." << std::endl;
                    close(clientSocket);
                    clientSockets.erase(clientSockets.begin() + i);
                } else {
                    std::cout << "Client " << clientSocket << ": " << buffer << std::endl;
                    for (size_t j = 0; j < clientSockets.size(); j++) {
                        int otherSocket = clientSockets[j];
                        if (otherSocket != clientSocket) {
                            send(otherSocket, buffer, bytesRead, 0);
                        }
                    }
                }
            }
        }
    }

    close(serverSocket);
}
