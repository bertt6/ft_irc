#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main() {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = 2000;
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if( connect(clientSocket, (struct sockaddr_in *)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Bağlantı hatası!!!";
        return 1;
    }

    std::cout << "Sunucuya bağlanıldı!!!" << std::endl;
    char *str = "SELAAAM";
    if(send(clientSocket, str, strlen(str), 0) == -1) {
        std::cerr << "Mesaj gönderim hatası!!!" << std::endl;
        return 1;
    }
    close(clientSocket);

    return 0;
}