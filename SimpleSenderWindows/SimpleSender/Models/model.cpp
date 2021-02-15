#include "model.h"

Model::Model()
{

}


void Model::send(std::string address, std::string message)
{
    Client(address, message);
}


void Model::listen(std::string address)
{
    Server* server = new Server(address);
    std::string reply = server->listenForMessage();
    //Notifys the UI, and gives it the message.
    emit gotMessage(reply);

}
