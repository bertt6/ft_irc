#include "../commands.hpp"

void    Commands::Ping(User &user, int clientSocket) {
    vector<string>::iterator it = args.begin() + 1;
    if ((*it).empty())
        errorHandle(user, "", clientSocket, ERR_NEEDMOREPARAMS);
    else
        SendToClient(clientSocket, user.getClientName() + " PONG " + (*it) + "\n");
}