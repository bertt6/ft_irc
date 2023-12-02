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
    for (std::vector<User *>::iterator it = this->users.begin(); it != this->users.end() ; it++)
    {
        if ((*it)->getNickName() == user->getNickName())
            break;
    }
    this->users.push_back(user);
}

void Channel::removeUser(string name)
{
    for (std::vector<User *>::iterator it = this->users.begin(); it != this->users.end(); it++)
    {
        if ((*it)->getNickName() == name)
        {
            this->users.erase(it);
            break;
        }
    }
}

void Channel::addAdmin(string name)
{
    for (std::vector<User *>::iterator it = this->users.begin(); it != this->users.end(); it++)
    {
        if ((*it)->getNickName() == name && !this->userIsTheAdmin((*it)->getNickName()))
        {
            this->admins.push_back(*it);
            break;
        }
    }
}

void Channel::removeAdmin(string name)
{
    for (std::vector<User *>::iterator it = this->admins.begin(); it != this->admins.end(); it++)
    {
        if ((*it)->getNickName() == name)
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

User *Channel::getUser(string name)
{
    for (std::vector<User *>::iterator it = this->users.begin(); it != this->users.end(); it++)
    {
        if ((*it)->getNickName() == name)
            return *it;
    }
    return NULL;
}

vector<User *> Channel::getUsers(void)
{
    return this->users;
}

vector<User *> Channel::getAdmins(void)
{
    return this->admins;
}