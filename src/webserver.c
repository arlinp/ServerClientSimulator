#include <arpa/inet.h>
#include <ctype.h> 
#include <netdb.h> 
#include <netinet/in.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
 
#define LENGTH 64
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

  int sockfd, nBytes; 
  struct sockaddr_in addr_con; 
  int addrlen = sizeof(addr_con); 
  addr_con.sin_family = AF_INET; 
  addr_con.sin_port = htons(port); 
  addr_con.sin_addr.s_addr = INADDR_ANY; 
  char sdbuf[LENGTH]; 
  FILE* fp; 
  
  // socket() 
  sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
  
  if (sockfd < 0) 
    printf("\nfile descriptor not received!!\n"); 
  else
    printf("\nfile descriptor %d received\n", sockfd); 
  
  // bind() 
  if (bind(sockfd, (struct sockaddr*)&addr_con, sizeof(addr_con)) == 0) 
    printf("\nSuccessfully binded!\n"); 
  else
    printf("\nBinding Failed!\n"); 
  
  while (1) { 
    printf("\nWaiting for file name...\n"); 
  
    // receive file name 
    bzero(sdbuf, LENGTH);
  
    nBytes = recvfrom(sockfd, sdbuf, 
		      LENGTH, 0, 
		      (struct sockaddr*)&addr_con, &addrlen); 
  
    //fp = fopen(sdbuf, "r");
    char* fs_name = "lab2.html";
    printf("\nFile Name Received: %s\n", sdbuf);
    FILE *fs = fopen(fs_name, "r");
    if (fp == NULL) 
      printf("\nFile open failed!\n"); 
    else
      printf("\nFile Successfully opened!\n"); 
  
    /*while (1) { 
  
    // process 
    if (sendFile(fp, sdbuf, LENGTH)) { 
    sendto(sockfd, sdbuf, LENGTH, 
    sendrecvflag,  
    (struct sockaddr*)&addr_con, addrlen); 
    break; 
    } 
  
    // send 
    sendto(sockfd, sdbuf, LENGTH, 
    sendrecvflag, 
    (struct sockaddr*)&addr_con, addrlen); 
    clearBuf(sdbuf); 
    } */
    int fs_block_sz; 
    while((fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs))>0){
      if(sendto(sockfd, sdbuf, LENGTH, 
		0,  
		(struct sockaddr*)&addr_con, addrlen) < 0){
	printf("ERROR: Failed to send file %s.\n", fs_name);
      }
      if (fp != NULL) 
	fclose(fp); 
    }
  }
  
  /*int sockfd;
    char buffer[LENGTH]; 
    char *hello = "Hello from server"; 
    struct sockaddr_in servaddr, cliaddr;
    int len = sizeof(servaddr);
  
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
    perror("socket creation failed"); 
    exit(EXIT_FAILURE); 
    } else {
    printf("Socket successfully created..\n");
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
    } else {
    printf("Socket successfully binded..\n");
    }
  
    if(!fork()) { //Change fs_name to that of http request file name 
    char* fs_name = "lab2.html";
    char sdbuf[LENGTH];
    printf("[Server] Sending %s to Client...", fs_name);
    //FILE *fs = fopen(fs_name, "r");
    /*if(fs == NULL){
    printf("ERROR: 404 Not Found.\n");
    exit(1);
    }

    bzero(sdbuf, LENGTH);
    int fs_block_sz, nBytes;
    int n;
    /*n = recvfrom(sockfd, (char *)buffer, LENGTH,
    0, ( struct sockaddr *) &cliaddr,
    &len);
    while(1){
    printf("\nWaiting for file name...\n");

    // receive file name
    bzero(sdbuf, LENGTH);
      
    nBytes = recvfrom(sockfd, sdbuf,
    LENGTH, 0,
    (const struct sockaddr*)&cliaddr, &len);

    FILE fs = fopen(fs_name, "r");
    printf("\nFile Name Received: %s\n", sdbuf);
    if (fs == NULL){
    printf("\nFile open failed!\n");
    }else{
    printf("\nFile Successfully opened!\n");
    }
    while((fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs))>0){
    if(sendto(sockfd, sdbuf, LENGTH, 0, (const struct sockaddr *) &cliaddr, len) < 0){
    printf("ERROR: Failed to send file %s.\n", fs_name);
    }
    bzero(sdbuf, LENGTH);
    }
    if (fs != NULL)
    fclose(fs);
      
    }
    printf("Ok sent to client!\n");
    close(sockfd);
    printf("[Server] Connection with Client closed. Server will wait now...\n");
    while(waitpid(-1, NULL, WNOHANG) > 0);
    }*/
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
  for(;;) {
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
      printf("server acccept failed...\n"); 
      exit(0); 
    } 
    else
      printf("server acccept the client...\n"); 
  
    // Function for chatting between client and server 
    func(connfd); 
  }
  // After chatting close the socket 
  close(sockfd); 
}

void func(int sockfd){ 
  if(!fork()) { //Change fs_name to that of http request file name 
    char* fs_name = "lab2.html";
    char sdbuf[LENGTH]; // Send buffer
    printf("[Server] Sending %s to Client...", fs_name);
    FILE *fs = fopen(fs_name, "r");
    if(fs == NULL){
      printf("ERROR: 404 Not Found.\n");
      exit(1);
    }

    bzero(sdbuf, LENGTH); 
    int fs_block_sz; 
    while((fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs))>0){
      if(send(sockfd, sdbuf, fs_block_sz, 0) < 0){
	printf("ERROR: Failed to send file %s.", fs_name);
	exit(1);
      }
      bzero(sdbuf, LENGTH);
    }
    printf("Ok sent to client!\n");
    close(sockfd);
    printf("[Server] Connection with Client closed. Server will wait now...\n");
    while(waitpid(-1, NULL, WNOHANG) > 0);
  }
} 
