#include "../commands.hpp"

void Commands::Privmsg(User &user, vector<Channel> &channels, map<int, User> &users, int clientSocket)
{
    if (user._isAuth)
    {
        vector<string>::iterator msg = args.begin() + 2;
        Channel *channel = findChannel(channels);
        if (channel)
        {
            if(channel->userOnTheChannel(user.getNickName()))
            {
                vector<User *> users = channel->getUsers();
                vector<User *>::iterator itUser = users.begin();
                for (; itUser != users.end(); itUser++)
                {
                    if ((*itUser)->getNickName() != user.getNickName())
                    {
                        cout << (*itUser)->socket << endl;
                        SendToClient((*itUser)->socket, (*itUser)->getClientName() + " PRIVMSG " + user.getNickName() + ": " + *msg + "\n");
                    }
                }
                return;
            }
            else
            {
                errorHandle(user, channel->getName(), clientSocket, ERR_CANNOTSENDTOCHAN);
                return ;
            }
        }
        else if ((args.begin() + 1)[0] == "#")
        {
            errorHandle(user, args[1], clientSocket, ERR_NOSUCHCHANNEL);
            return ;
        }

        User *reciverUser = findUser(users);
        if (reciverUser)
            SendToClient(reciverUser->socket, reciverUser->getClientName() + " PRIVMSG " + *msg + "\n");
        else
          errorHandle(user, "", clientSocket, 406);  
    }
}
