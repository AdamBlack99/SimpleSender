#include "model.h"

Model::Model()
{
    _server = new Server();
}


void Model::send(std::string address, std::string message)
{
    Client(address, message);
}


void Model::listen(std::string address)
{
    _server->setAddress(address);
    _server->listenForMessage();
    //Notifys the UI, and gives it the message.

}

