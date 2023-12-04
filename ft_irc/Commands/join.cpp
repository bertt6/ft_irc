#include "../commands.hpp"

void Commands::Join(User &user, vector<Channel> &channels, int clientSocket)
{
    if (user._isAuth)
    {
        vector<string>::iterator itArgs = args.begin() + 1;
        if(args.size() == 2)
        {
            if (itArgs != args.end() && (*itArgs)[0] == '#')
            {
                for (vector<Channel>::iterator itChannels = channels.begin(); itChannels != channels.end(); itChannels++)
                {
                    if (itChannels->getName() == *itArgs && !itChannels->userOnTheChannel(user.getNickName()))
                    {   
                        vector<User*> users = (*itChannels).getUsers();
                        vector<User*>::iterator itUser = users.begin();
                        for(; itUser != users.end(); itUser++)
                            SendToClient((*itUser)->socket, (*itUser)->getClientName() + " JOIN " + user.getNickName() + " has joined this channel : " + itChannels->getName() + "!\n");
                        User *userPtr = &user;
                        itChannels->addUser(userPtr);
                        SendToClient(clientSocket, user.getClientName() + " JOIN you joined the " + *itArgs + " channel!\n");
                        return;
                    }
                    else if (itChannels->getName() == *itArgs && itChannels->userOnTheChannel(user.getNickName()))
                    {
                        SendToClient(clientSocket, user.getClientName() + " JOIN You're already on this channel!\n");
                        return;
                    }
                }
                User *userPtr = &user;
                channels.push_back(Channel((*itArgs), userPtr));
                SendToClient(clientSocket, user.getClientName() + " JOIN you joined the " + *itArgs + " channel!\n");
            }
        }
        else errorHandle(user, "", clientSocket, ERR_NEEDMOREPARAMS);
    }
}