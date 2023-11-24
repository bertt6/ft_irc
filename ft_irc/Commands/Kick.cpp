#include "../commands.hpp"

void Commands::Kick(User &user, vector<Channel> &channels, int clientSocket)
{
    (void)clientSocket;
    //if (user._isAuth)
    //{
        string channelName = args[1];
        string kickUserName = args[2];
        for (vector<Channel>::iterator itChannels = channels.begin(); itChannels != channels.end(); itChannels++)
        {
            if ((*itChannels).getName() == channelName && (*itChannels).userIsTheAdmin(user.getNickName()))
            {
                (*itChannels).removeUser(kickUserName);
                //user removed message
            }
        }
   // }
}