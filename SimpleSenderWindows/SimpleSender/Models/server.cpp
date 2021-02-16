#include "server.h"


Server::Server(std::string address)
{
    _address = new char [address.length()+1];
    strcpy (_address, address.c_str());
}


//Start a server and listens until a message arrives
void Server::listener()
{
    qInfo("Listener ready");
    SOCKET sockfd, new_socket;
    WSADATA wsa;
    struct sockaddr_in server , client;
    int c, recv_size;
    char client_message[2000];



    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        qCritical( "WSA setup failed with error code : %d" , WSAGetLastError());
    }


    if((sockfd = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        qCritical( "Socket setup failed with error code : %d" , WSAGetLastError());
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(_address);
    server.sin_port = htons( 10000 );

    if( bind(sockfd ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
        qCritical( "Bind failed with error code : %d" , WSAGetLastError());
    }
    qInfo("Server set up");


    listen(sockfd , 3);


    //qInfo("%d",sizeof(struct sockaddr_in));
    c = sizeof(struct sockaddr_in);
    qInfo("Listening finished");
    new_socket = accept(sockfd , (struct sockaddr *)&client, &c);


    if((recv_size = recv(new_socket , client_message , 2000 , 0)) == SOCKET_ERROR)
    {
        qCritical( "Receive failed with error code : %d" , WSAGetLastError());
    }
    qInfo( client_message);
    closesocket(sockfd);
    closesocket(new_socket);
    WSACleanup();

    //Send the message to the GUI
    std::string reply = client_message;
    emit(received(QString::fromStdString(reply)));


}

// Start the listner process.
std::string Server::listenForMessage()
{

        listenerThread = new std::thread([&]() {
            qInfo("Thread is ready");
            listener();
        });
}


void Server::setAddress(std::string address)
{
    _address = new char [address.length()+1];
    strcpy (_address, address.c_str());
}

Server::Server(){}
