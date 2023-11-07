#include "server.hpp"

void Server::handleCmd(string msg, int clientSocket, string password) {
    this->commands.findCommand(this->Users, clientSocket, msg, password);
}
