#include "../commands.hpp"

void Commands::Usèr(User& user, int clientSocket, string msg) {
    setArgs(msg);
    this->args.erase(this->args.begin());
    cout << args.size();
    if(args.size() != 4) {
        string err = "<client> <command> :Not enough parameters";
        SendToClient(clientSocket, err);
        args.clear();
        return ;
    }
    if(args[0].size() && args[1][0] == '0' && args[1][1] == '\0' && args[2][0] == '*' && args[2][1] == '\0' && args[3].size()) {
        if(!user.getUserName().empty() && !user.getRealName().empty()) {
             SendToClient(clientSocket, "<client> :You may not reregister");
             return ;
        }
        user.setUserName(args[0]);
        user.setRealName(args[3]);
        user._isUser = true;
        if (user._isNicked) {
            user._isRegister = true;
            SendToClient(clientSocket, "You are registered now!\n");
        }
    }
    else {
        SendToClient(clientSocket, "User using: USER <username> 0 * <realname> \n");
        args.clear();
        return ;
    }
    cout << "USER CHECK : " << user.getUserName() << " " << user.getRealName() << endl;
}


/*

ilk giren kisinin kullanabilecegi komutlar: 
    USER
    NICK
    CAP //bos
    PING
    QUIT
register olan birinin kullanabilecegi komutlar ( _isRegsiter )
    PASS
auth olan birinin kullanabilecegi komutlar ( _isAuth )
    TOPIC 
    KICK
    JOIN
    PART
    PRIVMSG
    WHO
    MODE
    NOTICE
    names
*/