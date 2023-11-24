#include "../commands.hpp"

void Commands::Join(User &user, vector<Channel> &channels, int clientSocket)
{
    if (user._isAuth)
    {
        (void)clientSocket;
        vector<string>::iterator itArgs = args.begin() + 1;
        cout << (*itArgs)[0] << endl;
        if (itArgs != args.end() && (*itArgs)[0] == '#')
        {
            cout << "if" << endl;
            for (vector<Channel>::iterator itChannels = channels.begin(); itChannels != channels.end(); itChannels++)
            {
                cout << "channels" << endl;
                if (itChannels->getName() == *itArgs)
                {   
                    User *userPtr = &user;
                    itChannels->addUser(userPtr);
                    //user added message
                    cout << "user added" << endl;

                    return;
                }
            }
            User *userPtr = &user;
            channels.push_back(Channel((*itArgs), userPtr));
            //user added message
        }
    }
}   