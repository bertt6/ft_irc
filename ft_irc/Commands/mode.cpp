#include "../commands.hpp"

void Commands::Mode(User& user, vector<Channel> &channels, int clientSocket)
{
    if (user._isAuth)
    {
        if(args.size() == 3)
        {
            string operation = args[2];
            Channel *channel = findChannel(channels);
            if (channel )
            {
                if(channel->userIsTheAdmin(user.getNickName()) && operation.size() == 2 && operation.find('o'))
                {
                    User *modifyUser = channel->getUser(args[3]);
                    if (operation[0] == '+')
                    {
                        channel->addAdmin(args[3]);
                        SendToClient(modifyUser->socket, modifyUser->getClientName() + " MODE You have been promoted admin!\n");
                        SendToClient(clientSocket, user.getClientName() + " MODE You promoted admin!\n");
                    }
                    else if (operation[0] == '-')
                    {
                        channel->removeAdmin(args[3]);
                        SendToClient(modifyUser->socket, modifyUser->getClientName() + " MODE You reduced it\n");
                        SendToClient(clientSocket, user.getClientName() + " MODE You were reduced!\n");
                    }
                }
            }
            else errorHandle(user, channel->getName(), clientSocket, ERR_NOSUCHCHANNEL);
        }
        else errorHandle(user, "", clientSocket, ERR_NEEDMOREPARAMS);
    }
}