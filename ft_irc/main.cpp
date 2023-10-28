#include <iostream>
#include "server.hpp"
#include "client.hpp"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Kullanım: " << argv[0] << " <port>" << std::endl;
        return 1;
    }

    int port = std::atoi(argv[1]);

    Server server(port);
    server.Start();

    // İstemciyi başlatmak için kodu buraya ekleyebilirsiniz.

    return 0;
}
