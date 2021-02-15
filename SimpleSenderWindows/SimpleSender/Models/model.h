#ifndef MODEL_H
#define MODEL_H

#include <string>
#include "client.h"
#include "server.h"
#include <QDebug>
#include <QObject>

class Model : public QObject
{
    Q_OBJECT

    public:
        Model();
        void send(std::string address, std::string message);
        void listen(std::string address);
        Server* _server;

   signals:
        void gotMessage(std::string message);

};

#endif // MODEL_H
