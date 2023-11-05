#include "server.hpp"

void Server::handleCmd(string msg, int clientSocket) {
    this->commands.findCmd(this->user, msg, clientSocket);
}
