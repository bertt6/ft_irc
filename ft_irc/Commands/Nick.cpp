#include "../commands.hpp"

void Commands::Nick(map<int, User> &users, int clientSocket) { 
    map<int, User>::iterator itUser = users.begin();
    vector<string>::iterator itArgs = args.begin() + 1;
    
    if(args.size() == 2)
    {
        while (itUser != users.end())
        {
            if (itUser->second.getNickName() == *itArgs) {
                cout << "ASD" << endl;
                errorHandle(users[clientSocket], *itArgs, clientSocket, ERR_NICKNAMEINUSE);
                return;
            }
            itUser++;
        }
        if(users[clientSocket]._isNicked)
        {
            string msg = users[clientSocket].getNickName() + " changed his nickname to " + *itArgs + "\n";
            users[clientSocket].setNickName(*itArgs);
            SendToClient(clientSocket, msg);
            return ;
        }
        else 
        {
            users[clientSocket].setNickName(*itArgs);
            string message = users[clientSocket].getClientName() + " ; Requesting the new nick \"" + users[clientSocket].getNickName() + "\".\n";
            SendToClient(clientSocket, message);
            if (users[clientSocket]._isUser) 
            {
                users[clientSocket]._isRegister = true;
                SendToClient(clientSocket, "You are registered now!\n");
                string newClientName = users[clientSocket].getNickName() + "!" + users[clientSocket].getUserName() + "@" + users[clientSocket].hostname;
                users[clientSocket].setClientName(newClientName);
            }
            else
            {
                string newClientName = users[clientSocket].getNickName() + "!" + "@" + users[clientSocket].hostname;
                users[clientSocket].setClientName(newClientName);
            }
        }
        users[clientSocket]._isNicked = true;
    }
    else 
    {
        cout << "\nCONTROL\n" << endl;
        errorHandle(users[clientSocket], "", clientSocket, ERR_NONICKNAMEGIVEN);
    }
}