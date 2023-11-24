#include  "channel.hpp"

Channel::Channel(string name, User *user)
{
    this->name = name;
    users.push_back(user);
    admins.push_back(user);
}

string Channel::getName(void)
{
    return this->name;
}

void Channel::setName(string name) 
{
    this->name = name;
}

string Channel::getTopic(void)
{
    return this->topic;
}

void    Channel::setTopic(string topic) 
{
    this->topic = topic;
}

void Channel::addUser(User *user)
{
    for (std::vector<User *>::iterator it = this->users.begin(); it != this->users.begin() ; it++)
    {
        if ((*it)->getNickName() == user->getNickName())
            break;
    }
    this->users.push_back(user);
}

void Channel::removeUser(string name)
{
    for (std::vector<User *>::iterator it = this->users.begin(); it != this->users.begin(); it++)
    {
        if ((*it)->getNickName() == name)
        {
            this->users.erase(it);
            break;
        }
    }
}

void Channel::addAdmin(User *user)
{
    for (std::vector<User *>::iterator it = this->admins.begin(); it != this->users.begin() ; it++)
    {
        if ((*it)->getNickName() == user->getNickName())
            break;
    }
    this->admins.push_back(user);
}

void Channel::removeAdmin(User *user)
{
    for (std::vector<User *>::iterator it = this->admins.begin(); it != this->users.end(); it++)
    {
        if ((*it)->getNickName() == user->getNickName())
        {
            this->admins.erase(it);
            break;
        }
    }
}


bool Channel::userOnTheChannel(string name)
{
    for (std::vector<User *>::iterator it = this->users.begin(); it != this->users.end(); it++)
    {
        if ((*it)->getNickName() == name)
            return true;
    }
    return false;
}

bool Channel::userIsTheAdmin(string name)
{
    for (std::vector<User *>::iterator it = this->admins.begin(); it != this->admins.end(); it++)
    {
        if ((*it)->getNickName() == name)
            return true;
    }
    return false;
}

vector<User *> Channel::getUsers(void)
{
    return this->users;
}

vector<User *> Channel::getAdmins(void)
{
    return this->admins;
}