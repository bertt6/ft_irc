#include "../commands.hpp"

void    Commands::Ping(User &user, int clientSocket, string msg) {
    (void)user;
    if (msg.empty())
        SendToClient(clientSocket, std::to_string(clientSocket) + " PING :Not enough parameters");
    else
        SendToClient(clientSocket, "PONG: " + msg);
}