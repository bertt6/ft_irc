#include "commands.hpp"
void ascii(string abc)
{
    int j = 0;
    for(int i = 0; abc[i]; i++) {
        j = abc[i];
        cout << j << endl;
    }
}

void Commands::handleCommand(map<int, User> &user, vector<Channel> &channels, int clientSocket, string msg, string password)
{
    vector<string> space_buffer;
    std::istringstream  ss(msg);
    string token;

    while (std::getline(ss, token))
    {
        token.erase(std::remove(token.begin(), token.end(), '\r'), token.end());
        space_buffer.push_back(token);
        cout << *(space_buffer.end() - 1) << endl;
        string str;
        vector<string>::iterator it = space_buffer.begin();
        if ((*it).find(':') != std::string::npos)
        {
            int where = (*it).find(':');
            string leftPart = (*it).substr(0, where);
            string rightPart = (*it).substr(where + 1);
            std::istringstream  iss(leftPart);
            while (iss >> token)
            {
                args.push_back(token);
            }
            args.push_back(rightPart);
        }
        else 
        {
            std::istringstream  iss(*it);
            while (iss >> token)
            {
                args.push_back(token);
            }
        }
        findCommand(user, channels, clientSocket, password);
        args.clear();
        space_buffer.clear();
    }
}


void Commands::findCommand(map<int, User> &user, vector<Channel> &channels, int clientSocket, string password) 
{
    if (*args.begin() == "NICK")
        this->Nick(user, clientSocket);
    else if (*args.begin() == "PASS")
        this->Pass(user[clientSocket], clientSocket, password);
    else if(*args.begin() == "CAP")
        SendToClient(clientSocket, "CAP * LS :multi-refix sasl\r\n");
    else if (*args.begin() == "USER")
        this->Usèr(user[clientSocket], clientSocket);
    else if (*args.begin() == "PING")  
        this->Ping(user[clientSocket], clientSocket);
    else if (*args.begin() == "JOIN")
        this->Join(user[clientSocket], channels, clientSocket);
    else if (*args.begin() == "KICK")
        this->Kick(user[clientSocket], channels, clientSocket);
    else if (*args.begin() == "PART")
        this->Part(user[clientSocket], channels, clientSocket);
    else if (*args.begin() == "PRIVMSG")
        this->Privmsg(user[clientSocket], channels, user, clientSocket);
    else if (*args.begin() == "TOPIC")
        this->Topic(user[clientSocket], channels, clientSocket);
    else if (*args.begin() == "MODE")
        this->Mode(user[clientSocket], channels, clientSocket);
    else if (*args.begin() == "EXIT")
        this->Exit();
    else if (*args.begin() == "test")
    {
        cout << endl << endl;
        vector<Channel>::iterator it = channels.begin();
        vector<User *> admins = (*it).getAdmins();

        vector<User *>::iterator admin = admins.begin();
        //vector<User *>::iterator admin = (*it).getAdmins().begin();

        cout << (*admin)->getNickName() << endl;
        //cout << (*user)->getNickName() << endl;
        cout << (*it).getName() << endl;
        cout << (*it).getTopic() << endl;
        cout << (*it).userIsTheAdmin(user[clientSocket].getNickName()) << endl;
        cout << (*it).userOnTheChannel(user[clientSocket].getNickName()) << endl;
    }
    else
        this->UnknowCmd(user[clientSocket], clientSocket, parsedCmd);
}

void    Commands::UnknowCmd(User &user, int clientSocket, string msg)
{
    SendToClient(clientSocket, user.getClientName() + ": " + msg + " :Unknown command\n");
}

Channel*    Commands::findChannel(vector<Channel> &channels)
{
    vector<string>::iterator itArg = args.begin() + 1; 
    for (vector<Channel>::iterator itChannel = channels.begin(); itChannel != channels.end(); itChannel++)
    {
        if (*itArg == (*itChannel).getName())
            return &(*itChannel);
    }
    return NULL;
}

void    SendToClient(int clientSocket, const std::string message)
{
    //string newMsg = message
    send(clientSocket, message.c_str(), message.size(), 0);
}

User* Commands::findUser(map<int, User> &users)
{
    vector<string>::iterator itArg = args.begin() + 1; 
    for (map<int, User>::iterator itUser = users.begin(); itUser != users.end(); itUser++)
    {
        if (*itArg == (*itUser).second.getNickName())
            return &((*itUser).second);
    }
    return NULL;
}

void Commands::errorHandle(User user, string channelName, int clientSocket, int errNum)
{
    string str;
    if(errNum == 461)
        str = user.getClientName() + " 461 " + *args.begin() +  ": Not enogh parameters\n";
    else if(errNum == 462)
        str = user.getClientName() + " :You may not reregister\n";
    else if(errNum == 464)
        str = user.getClientName() + " :Password incorrect\n";
    else if(errNum == 433)
        str = user.getClientName() + " " + channelName + " :Nickname is already in use\n";
    else if(errNum == 431)
        str = user.getClientName() + " :No nickname given\n";
    else if(errNum == 403)
        str = user.getClientName() + " " + channelName + " :No such channel\n";
    else if(errNum == 406)
        str = user.getClientName() + " :There was no such nickname\n";
    SendToClient(clientSocket, str);
}
