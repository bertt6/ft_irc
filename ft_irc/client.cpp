#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Soket oluştur
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        std::cerr << "Soket oluşturma hatası" << std::endl;
        return 1;
    }

    // Sunucu adresi ve bağlantı bilgilerini ayarla
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Sunucu portu
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Sunucu IP adresi

    // Sunucuya bağlan
    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Sunucuya bağlanma hatası" << std::endl;
        return 1;
    }

    std::cout << "Sunucuya bağlandı. Mesaj gönderiliyor..." << std::endl;

    const char* message = "Merhaba, bu bir istemci mesajıdır.";
    // Mesajı sunucuya gönder
    ssize_t bytesSent = send(clientSocket, message, strlen(message), 0);
    if (bytesSent == -1) {
        std::cerr << "Mesaj gönderme hatası" << std::endl;
        return 1;
    }

    // Soketi kapat
    close(clientSocket);

    return 0;
}
