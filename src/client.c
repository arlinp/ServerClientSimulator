#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

#define LENGTH 64
#define MAXLINE 1024 
#define MAX 80 
#define SA struct sockaddr

int TCP(int port, char* address);
void func(int sockfd);
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
    int sockfd; 
    char buffer[MAXLINE]; 
    char* hello = "Hello from client"; 
    struct sockaddr_in     servaddr; 
  
    // Creating socket file descriptor 
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("Error: 404 Not Found."); 
        exit(EXIT_FAILURE); 
    } 
  
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(port); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
      
    int n, len; 
      
    sendto(sockfd, (const char* )hello, strlen(hello), 
        MSG_CONFIRM, (const struct sockaddr*) &servaddr,  
            sizeof(servaddr)); 
    printf("Hello message sent.\n"); 
          
    n = recvfrom(sockfd, (char*)buffer, MAXLINE,  
                MSG_WAITALL, (struct sockaddr*) &servaddr, 
                &len); 
    buffer[n] = '\0'; 
    printf("Server : %s\n", buffer); 
  
    close(sockfd); 
    return 0; 
} 

void func(int sockfd) 
{ 
    char buff[MAX]; 
    int n; 
    for (;;) { 
        bzero(buff, sizeof(buff)); 
        printf("Enter the string : "); 
        n = 0; 
        while ((buff[n++] = getchar()) != '\n') 
            ; 
        write(sockfd, buff, sizeof(buff)); 
        bzero(buff, sizeof(buff)); 
        read(sockfd, buff, sizeof(buff)); 
        printf("From Server : %s", buff); 
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
        printf("Error: 404 Not Found.\n"); 
        exit(0); 
    } 
    else
        printf("Connected to the server..\n"); 
  
    // function for chat 
    func(sockfd); 
  
    // close the socket 
    close(sockfd); 

/*adsfasd
    FILE *fr = fopen("./lab2.html", "a");
    if{
        bzero(revbuf, LENGTH); 
        int fr_block_sz = 0;
        int success = 0;
        //while(success == 0){
            while(fr_block_sz = recv(sockfd, revbuf, LENGTH, 0)){
                if(fr_block_sz < 0){
                    error("Receive file error.\n");
                }
                int write_sz = fwrite(revbuf, sizeof(char), fr_block_sz, fr);
                if(write_sz < fr_block_sz){
                    error("File write failed.\n");
                }
                else if(fr_block_sz){
                    break;
                }
                bzero(revbuf, LENGTH);
            }
            printf("Ok!\n");
            success = 1;
            fclose(fr);
        //}
    }
    else(fr == NULL) printf("404 Not Found.\n");
    */
    printf("Client connection lost.\n");
    return (0);
}
