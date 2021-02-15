#include "server.h"

Server::Server()
{
    SOCKET sockfd, new_socket;
        WSADATA wsa;
        struct sockaddr_in server , client;
        int c, recv_size;
        char *message , server_reply[2000];


        if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
        {

        }



        if((sockfd = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
        {

        }
        //Prepare the sockaddr_in structure
        server.sin_family = AF_INET;
        server.sin_addr.s_addr = inet_addr("192.168.1.14");
        server.sin_port = htons( 10000 );

        //Bind
        if( bind(sockfd ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
        {
            qCritical( "Bind failed with error code : %d" , WSAGetLastError());
        }


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
}
