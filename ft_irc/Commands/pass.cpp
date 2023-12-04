#include "../commands.hpp"

void Commands::Pass(User& user, int clientSocket, string svPasswd) {
    if(args.size() == 2)
    {
        if(user._isAuth) 
            errorHandle(user, "", clientSocket, 462);
        else if (user._isRegister) {
            (void)user;
            string message;
            vector<string>::iterator it = args.begin() + 1;
            if(!(*it).empty() && *it == svPasswd) {
                SendToClient(clientSocket, user.getClientName() + " PASS You're auth now!\n");
                user._isAuth = true;
            }
            else if (*it != svPasswd)
                errorHandle(user, "", clientSocket, ERR_PASSWDMISMATCH);
        }
    }
    else errorHandle(user, "", clientSocket, ERR_PASSWDMISMATCH);
}