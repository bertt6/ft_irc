#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

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

    char send_string[1024];
    while (true) {
        std::cout << "Lütfen göndermek istediğiniz mesajı giriniz: ";
        std::cin.getline(send_string, sizeof(send_string));

        // Mesajı sunucuya gönder
        ssize_t bytesSent = send(clientSocket, send_string, strlen(send_string), 0);
        if (bytesSent == -1) {
            std::cerr << "Mesaj gönderme hatası" << std::endl;
            break;
        }

        if (strncmp(send_string, "EXIT", 4) == 0) {
            std::cout << "İstemci kapatılıyor..." << std::endl;
            break;
        }
    }

    // Soketi kapat
    close(clientSocket);

    return 0;
}
