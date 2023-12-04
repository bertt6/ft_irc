#include "../commands.hpp"

void Commands::Usèr(User& user, int clientSocket) {
    if(args.size() != 5) {
        errorHandle(user, "", clientSocket, ERR_NEEDMOREPARAMS);
        return ;
    }
    if(user._isRegister) {
        errorHandle(user, "", clientSocket, ERR_ALREADYREGISTERED);
        return ;
    }
    this->args.erase(this->args.begin());
    if(args[0].size() && args[1][0] == '0' && args[1][1] == '\0' && args[3].size()) {
        user.setUserName(args[0]);
        user.setRealName(args[3]);
        user._isUser = true;
        if (user._isNicked) {
            user._isRegister = true;
            string newClientName = user.getNickName() + "!" + user.getUserName() + "@" + user.hostname;
            user.setClientName(newClientName);
            SendToClient(clientSocket, user.getClientName() + user.getUserName() + " USER You are registered now!\n");
        }
        else if (user._isUser){
            string newClientName =  "!" + user.getUserName() + "@" + user.hostname;
            user.setClientName(newClientName);
        }
    }
    else SendToClient(clientSocket, "User using: USER <username> 0 * <realname> \n");
}
