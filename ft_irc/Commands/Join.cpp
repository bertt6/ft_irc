#include "../commands.hpp"

void Commands::Join(User &user, vector<Channel> &channels, int clientSocket)
{
    if (user._isAuth)
    {
        (void)clientSocket;
        vector<string>::iterator itArgs = args.begin() + 1;
        if(args.size() == 2)
        {
            if (itArgs != args.end() && (*itArgs)[0] == '#')
            {
                for (vector<Channel>::iterator itChannels = channels.begin(); itChannels != channels.end(); itChannels++)
                    if (itChannels->getName() == *itArgs)
                {
                    {   
                        User *userPtr = &user;
                        itChannels->addUser(userPtr);
                        cout << "user added" << endl;
                        //user added message
                        return;
                    }
                }
                User *userPtr = &user;
                channels.push_back(Channel((*itArgs), userPtr));
                cout << "admin added" << endl;
                //user added message
            }
        }
        else
            errorHandle(user, "", clientSocket, ERR_NEEDMOREPARAMS);
    }
    else
        cout << "\n\n\nNOT AUTH!\n\n\n";
}