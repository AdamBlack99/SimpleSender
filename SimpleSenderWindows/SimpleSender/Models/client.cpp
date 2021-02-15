#include "client.h"

//Send the message to address, using TCP socket
//
Client::Client(std::string address, std::string message)
{
    SOCKET sockfd;
    WSADATA wsa;
    struct sockaddr_in server;



    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        qCritical("Failed. Error Code : %d",WSAGetLastError());
    }



    if((sockfd = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        qCritical("Could not create socket : %d" , WSAGetLastError());
    }

    char * addressC = new char [address.length()+1];
    strcpy (addressC, address.c_str());


    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(addressC);
    server.sin_port = htons( 10000 );


    if( connect(sockfd ,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        qCritical("Connect failed with error code : %d" , WSAGetLastError());
    }
    qInfo("Client set up");



    char * messageC = new char [message.length()+1];
    strcpy (messageC, message.c_str());

    if( send(sockfd , messageC , strlen(messageC) , 0) < 0)
    {
        qCritical("Send failed: %d", WSAGetLastError());
    }

    qInfo("Message sent");
    closesocket(sockfd);
    WSACleanup();

}
