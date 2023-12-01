#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <netinet/in.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <vector>
#include <string>
#include <map>
#include "user.hpp"


using std::endl;
using std::cout;
using std::vector;
using std::string;

class Channel
{
    private:
        string name;
        string topic;
        vector<User *> users;
        vector<User *> admins;
    public:
        Channel(string, User*);
        string getName(void);
        void setName(string);
        string getTopic(void);
        void setTopic(string);
        void addUser(User*);
        void removeUser(string);
        void addAdmin(string);
        void removeAdmin(string);
        bool userOnTheChannel(string);
        bool userIsTheAdmin(string);
        vector<User *> getUsers(void);
        vector<User *> getAdmins(void);
};

#endif