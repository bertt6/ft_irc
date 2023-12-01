#include "../commands.hpp"

void Commands::Quit(User& user, vector<Channel> &channel, int clienSocket) {
    (void)user;
    (void)channel;
    (void)clienSocket;
    vector<Channel>::iterator itChannels = channel.begin();
    for (; itChannels != channel.end(); itChannels++)
    {
        if ((*itChannels).userOnTheChannel(user.getNickName()))
            this->Part(user, channel, clienSocket);
    }
    close(clienSocket);
}