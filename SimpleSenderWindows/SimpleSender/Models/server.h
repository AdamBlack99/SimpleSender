#ifndef SERVER_H
#define SERVER_H

#include <winsock2.h>
#include <QDebug>
#include <string>
#include <thread>
#include <future>

class Server : public QObject
{
    Q_OBJECT

    private:
        char* _address;
        std::thread *listenerThread;
        void listener();


    public:
        Server();
        Server(std::string address);
        std::string listenForMessage();
        void setAddress(std::string address);
    signals:
        void received(QString);

};

#endif // SERVER_H
