#include "client.hpp"


Client::Client(const char* serverIP, int serverPort) {
    this->serverIP = serverIP;
    this->serverPort = serverPort;
    clientSocket = -1;

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);

    if (inet_pton(AF_INET, serverIP, &serverAddr.sin_addr) <= 0) {
        perror("Hata: IP adresi çözümlenemedi");
        exit(1);
    }
}

void Client::Connect() {
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    std::cout << "[DEBUG]CLIENT SOCKET : " << clientSocket << std::endl;
    if (clientSocket < 0) {
        perror("Hata: Soket oluşturulamadı");
        exit(1);
    }

    std::cout << "Sunucuya bağlanılıyor..." << std::endl;

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr) < 0)) {
        perror("Hata: Sunucuya bağlanılamadı");
        exit(1);
    }

    std::cout << "Sunucuya başarıyla bağlanıldı..." << std::endl;
}

void Client::StartCommunication() {
    char buffer[1024];

    while (true) {
        std::cout << "İstemci: ";
        char data[1024]
        std::getline(std::cin, data);
        
        if (data == "exit") {
            send(clientSocket, data, strlen(data), 0);
            std::cout << "Bağlantı kapatılıyor..." << std::endl;
            break;
        }
        
        send(clientSocket, data, strlen(data), 0);
        memset(buffer, 0, sizeof(buffer));
        recv(clientSocket, buffer, 1024, 0);
        std::cout << "Sunucu: " << buffer << std::endl;
    }

    close(clientSocket);
}
