#include "../commands.hpp"

void Commands::Topic(User &user, vector<Channel> &channels, int clientSocket)
{
    if (user._isAuth)
    {  
        if(args.size() == 3)
        {
            Channel *channel = findChannel(channels);
            if (channel)
            {
                if(channel->userIsTheAdmin(user.getNickName()))
                {
                    vector<string>::iterator topic = args.begin() + 2;
                    channel->setTopic(*topic);
                    vector<User*> vecUser = channel->getUsers();
                    vector<User*>::iterator it = vecUser.begin();
                    for(; it != vecUser.end(); it++)
                        SendToClient((*it)->socket, (*it)->getClientName() + " TOPIC Topic has chanced: " + *topic + "!\n");
                }
            }
            else errorHandle(user, channel->getName(), clientSocket, ERR_NOSUCHCHANNEL);
        }
        else errorHandle(user, "", clientSocket, ERR_NEEDMOREPARAMS);
    }
}