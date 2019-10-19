#include <unistd.h> 
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <sys/socket.h> 

#define LENGTH 64
#define MAXLINE 1024 
#define SA struct sockaddr

int TCP(int port, char* address);
int func(int sockfd);
int UDP(int port, char* address);
  
// Driver code 
int main(int argc, char *argv[]) {
  if (argc == 3) {
    int i = 0;
    int port;
    char *p = strtok (argv[1], ":");
    char *array[2];

    while (p != NULL)
    {
        array[i++] = p;
        p = strtok (NULL, ":");
    }
    
    printf("%s\n", array[1]);
    port = atoi(array[1]);

    if (strcmp(argv[2], "TCP") == 0) { 
      TCP(port, array[0]);
    } else if (strcmp(argv[2], "UDP") == 0) { 
      UDP(port, array[0]);
    } else {
      printf("Invalid transport protocol: Expected either TCP or UDP, found %s\n", argv[2]);
      return 0;
    }
  } else {
    printf("Wrong number of arguments: Expected 2, found %d\n", argc - 1);
    return 0;
  }
}

int UDP(int port, char* address) { 
    int sockfd, i; 
    char buffer[MAXLINE]; 
    char* hello = "Client is connected."; 
    struct sockaddr_in     servaddr, cliaddr; 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // Creating socket file descriptor 
   // if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
    //    perror("Error: 404 Not Found."); 
    //    exit(EXIT_FAILURE); 
    //} 
  
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(port); 
    servaddr.sin_addr.s_addr = inet_addr(address); 
      
    int n, len; 
      
          
    //n = recvfrom(sockfd, (char*)buffer, MAXLINE,  
    //            MSG_WAITALL, (struct sockaddr*) &servaddr, 
    //            &len); 
    buffer[n] = '\0'; 
    printf("From Server : %s\n", buffer); 

        // socket() 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
  
    if (sockfd < 0) 
        printf("\nfile descriptor not received!!\n"); 
    else
        printf("\nfile descriptor %d received\n", sockfd);

    exit:
    while (1) { 
        printf("\n---------Data Received---------\n"); 

        sendto(sockfd, (const char* )hello, strlen(hello), 
        0, (const struct sockaddr*) &servaddr,  
            sizeof(servaddr)); 

        while (1) { 
            // receive 
            for (i = 0; i < MAXLINE; i++) 
                buffer[i] = '\0'; 
            int n = recvfrom(sockfd, (char*)buffer, MAXLINE,  
                MSG_WAITALL, (struct sockaddr*) &servaddr, 
                &len); 
            if (n == 0){
                goto exit;
            }
            printf("%s", buffer);
        } 
        printf("\n-------------------------------\n"); 
    }
    exit:
    close(sockfd);
    return 0;  
} 

int func(int sockfd) 
{ 
    char buff[LENGTH];
    char c;
    int n;
    printf("From Server : \n");
    // bzero(buff, sizeof(buff));
    for (;;) { 
      bzero(buff, LENGTH); 
        //printf("Enter the string : "); 
        //n = 0; 
        //while ((buff[n++] = getchar()) != '\n') 
        //     ; 
        //write(sockfd, buff, sizeof(buff)); 
        
        read(sockfd, buff, LENGTH);
	
	 
        //fwrite(buff, sizeof(buff), 1, temp);
        buff[LENGTH] = 0;
	    printf("%s", buff);
        if ((strncmp(buff, "exit", 4)) == 0) { 
            printf("Client Exit...\n"); 
            break; 
        } 
    }
    
}
  
int TCP(int port, char* address) 
{ 
    printf("%s\n", address);
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli;

  
    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("Error: Failed to establish socket.\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 

    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr(address); 
    servaddr.sin_port = htons(port); 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("Error: Failed to connect to server.\n"); 
        exit(0); 
    } 
    else
        printf("Connected to the server..\n"); 
  
    // function for chat 
    func(sockfd); 
  
    // close the socket 
    close(sockfd); 
    printf("Client connection lost.\n");
    return (0);
}
