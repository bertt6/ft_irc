#include "../commands.hpp"

void Commands::Kick(User &user, vector<Channel> &channels, int clientSocket)
{
    if (user._isAuth)
    {
        if(args.size() == 4)
        {
            string kickNickName = args[2];
            string reason = args[3];
            Channel *channel = findChannel(channels);
            if(!channel)
                errorHandle(user, "", clientSocket, ERR_NOSUCHCHANNEL);
            else if (channel->userIsTheAdmin(user.getNickName()))
            {
                User *kickUser = channel->getUser(kickNickName); 
                SendToClient(kickUser->socket, kickUser->getClientName() + " KICK You're kicked for Reason: " + reason + "\n");
                channel->removeUser(kickNickName);
            }
        }
        else errorHandle(user, "", clientSocket, ERR_NEEDMOREPARAMS);
   }
}