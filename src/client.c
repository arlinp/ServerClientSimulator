#include <unistd.h> 
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <netinet/in.h>
#include <sys/socket.h> 

//length is the length in bytes of the buffer.
#define LENGTH 64
#define MAXLINE 1024 
#define SA struct sockaddr

char URL[20];
char connType[3];

int TCP(int port, char* address);
int helper(int sockfd);
int UDP(int port, char* address);

  
// Main accepts the input arguments and determines which function should run, 
//  either TCP or UDP.  It parses the string indicating the address and port.
int main(int argc, char *argv[]) {
    
  if((argc == 2) &&
     ( (strcmp(argv[1], "TCP") == 0) || (strcmp(argv[1], "UDP") == 0) ) ){
    strcpy(connType, argv[1]);
    printf("Please enter a URL: ");
    scanf("%s", URL);
  }
  else{
    strcpy(URL, argv[1]);
    strcpy(connType, argv[2]);
  }
    int i = 0;
    int port;
    char *p = strtok (URL, ":");
    char *array[2];

    while (p != NULL)
    {
      array[i++] = p;
      p = strtok (NULL, ":");
    }
    
    printf("%s\n", array[1]);
    port = atoi(array[1]);

    if ((strcmp(connType, "TCP") == 0)) { 
      TCP(port, array[0]);
    } else if (strcmp (connType, "UDP") == 0) { 
      UDP(port, array[0]);
    } else {
      printf("Invalid transport protocol: Expected either TCP or UDP, found %s\n", connType);
      return 0;
    }
    return 0;
}

// Function controlling UDP connection.
// It accepts the port and parsed address.
int UDP(int port, char* address) { 
    int sockfd, i; 
    char buffer[MAXLINE]; 
    char* hello = "Client is connected."; 
    struct sockaddr_in servaddr, cliaddr; 
    bzero(&servaddr, sizeof(servaddr)); 
    int n, len;
  
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(port); 
    servaddr.sin_addr.s_addr = inet_addr(address); 
 
    buffer[n] = '\0'; 
    printf("From Server : %s\n", buffer); 

    // socket() 
    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
  
    if (sockfd < 0) 
        printf("\nFile descriptor not received!\n"); 
    else
        printf("\nFile descriptor %d received\n", sockfd);

    while (1) { 

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
	    if ((strncmp(buffer, "exit", 4)) == 0) {
	      goto exit; 
	    } 
            printf("%s", buffer);
        } 
    }
    exit:
    close(sockfd);
    return 0;  
} 

// Function to print out information received from
// server (HTML file contents)

int helper(int sockfd) 
{
    char buff[LENGTH];
    char c;
    int n;
    printf("From Server : \n");
    
    for (;;) { 
      bzero(buff, LENGTH);
      
      if(!recv(sockfd, buff, sizeof(buff) - 1, 0)) {
          break;
      }	

      buff[LENGTH] = 0;
      printf("%s", buff);
	    
      if(buff[0] == 0){
        exit(0);
      }
    }
}
  
int TCP(int port, char* address) 
{ 
    printf("%s\n", address);
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli;

  
    // socket creation
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("Error: Failed to establish socket.\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 

    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign information to the struct
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
  
    // calls the handler.
    helper(sockfd); 
  
    // close the socket 
    close(sockfd); 
    printf("Client connection closed.\n");
    return (0);
}
