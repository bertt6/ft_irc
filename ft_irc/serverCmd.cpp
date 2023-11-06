#include "server.hpp"

void Server::handleCmd(string msg, int clientSocket, string password) {
    this->commands.findCmd(this->_Users, clientSocket, msg, password);
}
