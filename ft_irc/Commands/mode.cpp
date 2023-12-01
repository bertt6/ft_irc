#include "../commands.hpp"

void Commands::Mode(User& user, vector<Channel> &channels, int clientSocket)
{
    (void)clientSocket;
    // if (user._isAuth)
    // {
        if(args.size() == 3)
        {
            string operation = args[2];
            Channel *channel = findChannel(channels);
            if (channel )
            {
                if(channel->userIsTheAdmin(user.getNickName()) && operation.size() == 2 && operation.find('o'))
                {
                    if (operation[0] == '+')
                    {
                        channel->addAdmin(args[3]);
                    }
                    else if (operation[0] == '-')
                        channel->removeAdmin(args[3]);
                }
            }
            else
                errorHandle(user, channel->getName(), clientSocket, ERR_NOSUCHCHANNEL);
        }
        else    
            errorHandle(user, "", clientSocket, ERR_NEEDMOREPARAMS);
}