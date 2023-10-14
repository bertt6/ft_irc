#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    // Soket oluştur
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Soket oluşturma hatası" << std::endl;
        return 1;
    }

    // Sunucu adresi ve bağlantı bilgilerini ayarla
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Port numarası
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Tüm arayüzlerden bağlantıyı kabul et

    // Soketi bağlantı noktasına bağla
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Bağlantı noktasına bağlama hatası" << std::endl;
        return 1;
    }

    // Bağlantıları dinle ve maksimum 5 bağlantı sıraya al
    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Bağlantıları dinleme hatası" << std::endl;
        return 1;
    }

    std::cout << "Sunucu başlatıldı. Bağlantı bekleniyor..." << std::endl;

    // İstemci bağlantılarını kabul et
    int clientSocket = accept(serverSocket, NULL, NULL);
    if (clientSocket == -1) {
        std::cerr << "İstemci bağlantı kabul hatası" << std::endl;
        return 1;
    }

    std::cout << "İstemci bağlandı. Mesaj bekleniyor..." << std::endl;

    char buffer[1024];
    // İstemciden gelen veriyi al
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead == -1) {
        std::cerr << "Veri alma hatası" << std::endl;
        return 1;
    }

    // Alınan veriyi ekrana yazdır
    std::cout << "Alınan veri: " << buffer << std::endl;

    // Soketleri kapat
    close(clientSocket);
    close(serverSocket);

    return 0;
}
