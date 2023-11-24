#include "../commands.hpp"

void Commands::Join(User &user, vector<Channel> &channels, int clientSocket)
{
    //if (user._isAuth)
    //{
        (void)clientSocket;
        vector<string>::iterator itArgs = args.begin() + 1;
        if (itArgs != args.end() && (*itArgs)[0] == '#')
        {
            for (vector<Channel>::iterator itChannels = channels.begin(); itChannels != channels.end(); itChannels++)
            {
                if (itChannels->getName() == *itArgs)
                {   
                    User *userPtr = &user;
                    itChannels->addUser(userPtr);
                    //user added message
                    return;
                }
            }
            User *userPtr = &user;
            channels.push_back(Channel((*itArgs), userPtr));
            //user added message
        }
    //}
}   