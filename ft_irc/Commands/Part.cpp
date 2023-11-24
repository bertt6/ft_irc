#include "../commands.hpp"

void Commands::Part(User &user, vector<Channel> &channels, int clientSocket)
{
    (void)clientSocket;
    if (user._isAuth)
    {
        vector<string>::iterator itArgs = args.begin() + 1;
        if (itArgs != args.end())
        {
            for (vector<Channel>::iterator itChannels = channels.begin(); itChannels != channels.end(); itChannels++)
            {
                if (itChannels->getName() == (*itArgs) && itChannels->userOnTheChannel(user.getNickName()))
                {
                    User *userPtr = &user;
                    itChannels->removeUser(userPtr);
                    //user removecd message
                    return;
                }
            }
        }
    }
}