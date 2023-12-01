#include "../commands.hpp"

void Commands::Cap(int clientSocket)
{
    SendToClient(clientSocket, "CAP * LS :multi-refix sasl\r\n");
}
