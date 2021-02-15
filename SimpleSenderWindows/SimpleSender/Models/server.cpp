#include "server.h"

Server::Server(std::string address)
{
    _address = new char [address.length()+1];
    strcpy (_address, address.c_str());
}

// Listens for a message, then returns it.
// TODO: Not to block the main thread
std::string Server::listenForMessage()
{
        SOCKET sockfd, new_socket;
        WSADATA wsa;
        struct sockaddr_in server , client;
        int c, recv_size;
        char *message , server_reply[2000];



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

        c = sizeof(struct sockaddr_in);
        new_socket = accept(sockfd , (struct sockaddr *)&client, &c);

        if((recv_size = recv(new_socket , server_reply , 2000 , 0)) == SOCKET_ERROR)
        {

        }
        qInfo( server_reply);
        closesocket(sockfd);
        closesocket(new_socket);
        WSACleanup();
        std::string reply = server_reply;
        return reply;
}
