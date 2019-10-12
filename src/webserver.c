#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h>
#include <stdio.h> 
#include <unistd.h>
#include <arpa/inet.h> 
#define MAX 80
#define MAXLINE 1024
#define SA struct sockaddr 

int UDP(int port);
int TCP(int port);
void func(int sockfd);

// Driver function 
int main(int argc, char *argv[]) 
{
  if (argc == 3) {
    if (strcmp(argv[2], "TCP") == 0) { 
      TCP(atoi(argv[1]));
    } else if (strcmp(argv[2], "UDP") == 0) { 
      UDP(atoi(argv[1]));
    } else {
      printf("Invalid transport protocol: Expected either TCP or UDP, found %s\n", argv[2]);
      return 0;
    }
  } else {
    printf("Wrong number of arguments: Expected 2, found %d\n", argc - 1);
    return 0;
  }
}

int UDP(int port) { 
  int sockfd; 
  char buffer[MAXLINE]; 
  char *hello = "Hello from server"; 
  struct sockaddr_in servaddr, cliaddr; 
      
  // Creating socket file descriptor 
  if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
    perror("socket creation failed"); 
    exit(EXIT_FAILURE); 
  } 
      
  memset(&servaddr, 0, sizeof(servaddr)); 
  memset(&cliaddr, 0, sizeof(cliaddr)); 
      
  // Filling server information 
  servaddr.sin_family    = AF_INET; // IPv4 
  servaddr.sin_addr.s_addr = INADDR_ANY; 
  servaddr.sin_port = htons(port); 
      
  // Bind the socket with the server address 
  if ( bind(sockfd, (const struct sockaddr *)&servaddr,  
            sizeof(servaddr)) < 0 ) 
    { 
      perror("bind failed"); 
      exit(EXIT_FAILURE); 
    } 
      
  int len, n; 
  n = recvfrom(sockfd, (char *)buffer, MAXLINE,  
	       MSG_WAITALL, ( struct sockaddr *) &cliaddr, 
	       &len); 
  buffer[n] = '\0'; 
  printf("Client : %s\n", buffer); 
  sendto(sockfd, (const char *)hello, strlen(hello),  
	 MSG_CONFIRM, (const struct sockaddr *) &cliaddr, 
	 len); 
  printf("Hello message sent.\n");  
      
  return 0; 
}

int TCP(int port) 
{ 
  int sockfd, connfd, len; 
  struct sockaddr_in servaddr, cli; 
  
  // socket create and verification 
  sockfd = socket(AF_INET, SOCK_STREAM, 0); 
  if (sockfd == -1) { 
    printf("socket creation failed...\n"); 
    exit(0); 
  } 
  else
    printf("Socket successfully created..\n"); 
  bzero(&servaddr, sizeof(servaddr)); 
  
  // assign IP, PORT 
  servaddr.sin_family = AF_INET; 
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
  servaddr.sin_port = htons(port); 
  
  // Binding newly created socket to given IP and verification 
  if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
    printf("socket bind failed...\n"); 
    exit(0); 
  } 
  else
    printf("Socket successfully binded..\n"); 
  
  // Now server is ready to listen and verification 
  if ((listen(sockfd, 5)) != 0) { 
    printf("Listen failed...\n"); 
    exit(0); 
  } 
  else
    printf("Server listening..\n"); 
  len = sizeof(cli); 
  
  // Accept the data packet from client and verification 
  connfd = accept(sockfd, (SA*)&cli, &len); 
  if (connfd < 0) { 
    printf("server acccept failed...\n"); 
    exit(0); 
  } 
  else
    printf("server acccept the client...\n"); 
  
  // Function for chatting between client and server 
  func(connfd); 
  
  // After chatting close the socket 
  close(sockfd); 
}

void func(int sockfd) 
{ 
    char buff[MAX]; 
    int n; 
    // infinite loop for chat 
    for (;;) { 
        bzero(buff, MAX); 
  
        // read the message from client and copy it in buffer 
        read(sockfd, buff, sizeof(buff)); 
        // print buffer which contains the client contents 
        printf("From client: %s\t To client : ", buff); 
        bzero(buff, MAX); 
        n = 0; 
        // copy server message in the buffer 
        while ((buff[n++] = getchar()) != '\n') 
            ; 
  
        // and send that buffer to client 
        write(sockfd, buff, sizeof(buff)); 
  
        // if msg contains "Exit" then server exit and chat ended. 
        if (strncmp("exit", buff, 4) == 0) { 
            printf("Server Exit...\n"); 
            break; 
        } 
    } 
} 
