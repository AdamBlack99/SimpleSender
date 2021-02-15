#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <winsock2.h>
#include <QDebug>


class Client
{
public:
    Client(std::string address, std::string message);
};

#endif // CLIENT_H
