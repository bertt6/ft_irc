#include "../commands.hpp"

void Commands::UserC(User& user, int clientSocket, string msg) {
    setArgs(msg);
    this->args.erase(this->args.begin());
    cout << args.size();
    if(args.size() != 4) {
        string err = user.getNickName() + " " + this->parsedCmd + " :Not enough parameters\n";
        SendToClient(clientSocket, err);
        args.clear();
        return ;
    }
    if(args[0].size() && args[1][0] == '*' && args[1][1] == '\0' && args[2][0] == '0' && args[2][1] == '\0' && args[3].size()) {
        user.userName = args[0];
        user.realName = args[3];
    }
    else {
        SendToClient(clientSocket, "User using: USER <username> 0 * <realname> \n");
        args.clear();
        return ;
    }
    cout << "USER CHECK : " << user.userName << " " << user.realName << endl;
    //USER <bs> 0 * <bsamli>
}
/*

ilk giren kisinin kullanabilecegi komutlar:
    USER
    NICK
    CAP
    PING
    QUIT

register olan birinin kullanabilecegi komutlar :
    PASS
    NICK
    USER
    CAP
    PING
    QUIT
auth olan birinin kullanabilecegi komutlar
    TOPIC 
    KICK
    PASS
    NICK
    USER
    JOIN
    PART
    PRIVMSG
    QUIT
    WHO
    MODE
    NOTICE
    PING
    names
*/