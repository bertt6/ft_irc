#include "../commands.hpp"

void Commands::Part(User &user, vector<Channel> &channels, int clientSocket)
{
    (void)clientSocket;
    //if (user._isAuth)
    //{
        if(args.size() == 3)
        {
            vector<string>::iterator itArgs = args.begin() + 1;
            if (itArgs != args.end())
            {
                for (vector<Channel>::iterator itChannels = channels.begin(); itChannels != channels.end(); itChannels++)
                {
                    if (itChannels->getName() == (*itArgs) && itChannels->userOnTheChannel(user.getNickName()))
                    {
                        itChannels->removeUser(user.getNickName());
                        if (itChannels->userIsTheAdmin(user.getNickName()))
                            itChannels->removeAdmin(user.getNickName());
                        //user removed message
                        return;
                    }
                }
                errorHandle(user, "", clientSocket, ERR_NOSUCHCHANNEL);
            }
        }
        else
            errorHandle(user, "", clientSocket, ERR_NEEDMOREPARAMS);
    //}
}