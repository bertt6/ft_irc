#include "../commands.hpp"

void Commands::Cap(User &user, int clientSocket)
{
    SendToClient(clientSocket, user.getClientName() +  " CAP * LS :multi-refix sasl\r\n");
}
