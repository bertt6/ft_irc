#include  "channel.hpp"

Channel::Channel(string name, User *user)
{
    this->name = name;
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
    std::vector<User *>::iterator it = this->users.begin();
    for (; it != this->users.begin() ; it++)
    {
        if ((*it)->getNickName() == user->getNickName())
            break;
    }
    this->users.push_back(user);
}

void Channel::removeUser(User *user)
{
    std::vector<User *>::iterator it = this->users.begin();
    for (; it != this->users.begin() ; it++)
    {
        if ((*it)->getNickName() == user->getNickName())
        {
            this->users.erase(it);
            break;
        }
    }
}

void Channel::addAdmin(User *user)
{
    std::vector<User *>::iterator it = this->admins.begin();
    for (; it != this->users.begin() ; it++)
    {
        if ((*it)->getNickName() == user->getNickName())
            break;
    }
    this->admins.push_back(user);
}

void Channel::removeAdmin(User *user)
{
    std::vector<User *>::iterator it = this->admins.begin();
    for (; it != this->users.begin() ; it++)
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
    std::vector<User *>::iterator it = this->users.begin();
    for (; it != this->users.begin() ; it++)
    {
        if ((*it)->getNickName() == name)
            return true;
    }
    return false;
}

bool Channel::userIsTheAdmin(string name)
{
    std::vector<User *>::iterator it = this->admins.begin();
    for (; it != this->admins.begin() ; it++)
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