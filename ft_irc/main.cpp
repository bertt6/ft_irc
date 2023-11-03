#include <iostream>
#include "server.hpp"


int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Using: " << argv[0] << " <port> <password>" << std::endl;
        return 1;
    }

    int port = std::atoi(argv[1]);

    Server server(port);
    server.setPassword(argv[2]);
    server.Start();

    return 0;
}
