#include "../commands.hpp"

void Commands::Kick(User &user, vector<Channel> &channels, int clientSocket)
{
    if (user._isAuth)
    {
        if(args.size() == 4)
        {
            string kickUserName = args[2];
            string reason = args[3];
            Channel *channel = findChannel(channels);
            if(!channel)
            {
                errorHandle(user, channel->getName(), clientSocket, ERR_NOSUCHCHANNEL);
                return ;
            }
            if (channel->userIsTheAdmin(user.getNickName()))
            {
                channel->removeUser(kickUserName);
                //user removed message + reason
            }
        }
        else
            errorHandle(user,  "", clientSocket, ERR_NEEDMOREPARAMS);
   }
}