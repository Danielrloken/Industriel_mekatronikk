#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

//Source: https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

// Function designed for chat between client and server.
void func(int sockfd)
{
    char buff[MAX];
    int n;
    // infinite loop for chat
    for (;;)
    {
        bzero(buff, MAX); //fills the first MAX bytes of the object of buff with zero (NUL) bytes.

        // read the message from client and copy it in buffer
        read(sockfd, buff, sizeof(buff)); //read from sockfd and store it inn buff, reads amount=sizeof(buff) befor truncating
        // print buffer which contains the client contents
        printf("From client: %s\t To client : ", buff);
        bzero(buff, MAX);
        n = 0;
        // copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n')
            ;

        // and send that buffer to client
        write(sockfd, buff, sizeof(buff)); //Write buff to sockfd

        // if msg contains "Exit" then server exit and chat ended.
        if (strncmp("exit", buff, 4) == 0) //Checks if first 4 char in buff are exit
        {
            printf("Server Exit...\n");
            break;
        }
    }
}

// Driver function
int main()
{
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);// Domain=AF_INET (IPv4 protocol), communication type = SOCK_STREAM:TCP(reliable, connection oriented), protocol=Protocol(IP),which is 0.
    if (sockfd == -1)
    {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));

    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //When we don't know the IP address of our machine, use special IP address INADDR_ANY. It allows our server to receive packets that have been targeted by any of the interfaces
    servaddr.sin_port = htons(PORT); //htons() function makes sure that numbers are stored in memory in network byte order

    // Binding newly created socket to given IP and verification
    if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0)// assign a local socket address((SA *)&servaddr) to socket(sockfd) with length(sizeof(servaddr))
    {
        printf("socket bind failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully binded..\n");

    // Now server is ready to listen and verification
    if ((listen(sockfd, 5)) != 0) //Server(sockfd) is ready to listen and verification, the maximum length for the queue is 5
    {
        printf("Listen failed...\n");
        exit(0);
    }
    else
        printf("Server listening..\n");
    len = sizeof(cli);

    // Accept the data packet from client and verification
    connfd = accept(sockfd, (SA *)&cli, &len); // The server(sockfd) accept the data packet from first client in queue
    if (connfd < 0)
    {
        printf("server accept failed...\n");
        exit(0);
    }
    else
        printf("server accept the client...\n");

    // Function for chatting between client and server
    func(connfd);

    // After chatting close the socket
    close(sockfd);
}
