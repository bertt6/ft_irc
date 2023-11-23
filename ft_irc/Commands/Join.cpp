#include "../commands.hpp"

void Commands::Join(User &user, vector<Channel> &channels, int clientSocket)
{
    if (user._isAuth)
    {
        (void)user;
        (void)clientSocket;
        vector<string>::iterator itArgs = args.begin() + 1;
        if ((*itArgs).c_str())
        {
            vector<Channel>::iterator itChannels = channels.begin();
            for (; itChannels != channels.end(); itChannels++)
            {
                if (itChannels->getName() == (*itArgs))
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
    }
}