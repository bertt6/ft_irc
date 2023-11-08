#include "../commands.hpp"

void Commands::Who(User& user, int clientSocket) {
     if (user._isAuth) {
        if (user.getNickName().empty()) {
            string clientReq = "Not found!\n";
            SendToClient(clientSocket, clientReq);
        }
        else {
            string clientReq = "[NICK] : " + user.getNickName() + "\n";
            SendToClient(clientSocket, clientReq);
        }
     }
}