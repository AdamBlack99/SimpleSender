#ifndef SERVER_H
#define SERVER_H

#include <winsock2.h>
#include <QDebug>
#include <string>

class Server
{
    private:
        char* _address;

    public:
        Server(std::string address);
        std::string listenForMessage();
};

#endif // SERVER_H
