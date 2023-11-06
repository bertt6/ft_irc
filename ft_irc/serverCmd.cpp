#include "server.hpp"

void Server::handleCmd(string msg, int clientSocket, string password) {
    this->commands.findCmd(this->user, clientSocket, msg, password);
}
