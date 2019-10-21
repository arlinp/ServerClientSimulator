#include <arpa/inet.h>
#include <ctype.h>
#include <math.h>
#include <netdb.h> 
#include <netinet/in.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

// LENGTH is the size of the packet
#define LENGTH 64
#define SA struct sockaddr 

int UDP(int port);
int TCP(int port);
void dataStreamTCP(int sockfd);

/*********************************************************************
 * Based on the users input runs either the UDP or the TCP
 * Driver function
 *********************************************************************/
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
    printf("Incorrect amount of arguments: Expected 2, found %d\n", argc - 1);
    return 0;
  }
}

/**************************************************************************
 * UDP is connectionless therefore there is no handshaking.
 * UDP provides an unreliable data transfer service meaning when a 
 * process sends a message into a UDP socket it provides noguarantee that 
 * the message reaches the  receiving  process.
 **************************************************************************/
int UDP(int port) {

  int sockfd, nBytes; 
  struct sockaddr_in addr_con; 
  int addrlen = sizeof(addr_con); 
  addr_con.sin_family = AF_INET; 
  addr_con.sin_port = htons(port); 
  addr_con.sin_addr.s_addr = INADDR_ANY; 
  char sdbuf[LENGTH]; 
  FILE* fp; 
  
  // socket creation
  sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
  
  if (sockfd < 0) {
    printf("\nFile descriptor not received!!\n");
  } else {
    printf("\nFile descriptor %d received\n", sockfd);
  }
  
  // binding socket
  if (bind(sockfd, (struct sockaddr*)&addr_con, sizeof(addr_con)) < 0) {
    printf("\nBinding Failed!\n");
  } else {
    printf("\nBinded Successfully!\n");
  }
  
  // Sending
  for (;;) {
    bzero(sdbuf, LENGTH);
  
    nBytes = recvfrom(sockfd, sdbuf, 
		      LENGTH, 0, 
		      (struct sockaddr*)&addr_con, &addrlen);
    // Child process for sending HTML file
    if(!fork()) {
      clock_t t; 
      char* fs_name = "lab2.html";
      FILE *f = fopen("udp_latency.csv", "a");
      FILE *fs = fopen(fs_name, "r");
      if (fp == NULL) {
	printf("\nFile open failed!\n"); 
      } else {
	printf("\nFile Successfully opened!\n");
      }
  
      int fs_block_sz;
      // Sends Datagrams
      t = clock();
      while((fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs))>0){
	if(sendto(sockfd, sdbuf, LENGTH, 0, (struct sockaddr*)&addr_con, addrlen) < 0){
	  printf("ERROR: Failed to send file %s.\n", fs_name);
	  exit(1);
	}
	bzero(sdbuf, LENGTH);
      }
      t = clock() - t;
      // Notifies client that entire file has been sent
      bzero(sdbuf, LENGTH);
      strcpy(sdbuf, "exit");
      if(sendto(sockfd, sdbuf, LENGTH, 0, (struct sockaddr*)&addr_con, addrlen) < 0){
	printf("ERROR: Failed to send message.\n");
	exit(1);
      }
      // Time stamp in seconds for latency 
      double time_taken = ((double)t)/CLOCKS_PER_SEC; 
      fprintf(f,"%f\n", time_taken);
      fclose(f);
      while(waitpid(-1, NULL, WNOHANG) > 0);
    }
    printf("Sent to client!\n");
  }
  // Close Socket Connection
  close(sockfd);
  return 0;
}

/*********************************************************************
 * TCP is connectionless therefore there is handshaking. The TCP 
 * service model includes a connection-oriented service and a reliable 
 * datatransfer service. 
 *********************************************************************/
int TCP(int port) 
{
  int sockfd, connfd, len; 
  struct sockaddr_in servaddr, cli; 
  
  // socket creation
  sockfd = socket(AF_INET, SOCK_STREAM, 0); 
  if (sockfd == -1) { 
    printf("Socket creation failed...\n"); 
    exit(0); 
  } else {
    printf("Socket has successfully created..\n");
  }
  bzero(&servaddr, sizeof(servaddr)); 
  
  // IP and PORT 
  servaddr.sin_family = AF_INET; 
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
  servaddr.sin_port = htons(port); 
  
  // Binding socket to port and IP
  if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
    printf("Socket bind failed...\n"); 
    exit(0); 
  } else {
    printf("Socket has successfully binded..\n");
  }
  
  // Server listening
  if ((listen(sockfd, 10000)) != 0) { 
    printf("Listen failed...\n"); 
    exit(0); 
  } 
  else 
    printf("Server listening..\n"); 
  len = sizeof(cli); 
  
  // Accept the data packet from client
  for(;;) {
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
      printf("Server acccept failed...\n"); 
      exit(0); 
    } 
    else
      printf("Server acccepted the client...\n"); 
  
    // Function for sending
    dataStreamTCP(connfd);
  }
  // Close the socket 
  close(sockfd);
  return 0;
}

/*********************************************************************
 * Sends HTML file through TCP datastream
 *********************************************************************/
void dataStreamTCP(int sockfd){
  // Child process for sending HTML file
  if(!fork()) { 
    clock_t t; 
    char* fs_name = "lab2.html";
    char sdbuf[LENGTH]; // Send buffer
    printf("[Server] Sending %s to Client...", fs_name);
    FILE *fs = fopen(fs_name, "r");
    FILE *f = fopen("tcp_latency.csv", "a");
    if(fs == NULL){
      printf("ERROR: 404 Not Found.\n");
      exit(1);
    }
    
    int fs_block_sz;
    bzero(sdbuf, LENGTH);
    // Sends Datagrams
    t = clock();
    while((fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs))>0){
      if(send(sockfd, sdbuf, fs_block_sz, 0) < 0){
	printf("ERROR: Failed to send file %s.", fs_name);
	exit(1);
      }
      bzero(sdbuf, LENGTH);
    }
    t = clock() - t; 
    printf("Ok sent to client!\n");
    bzero(sdbuf, LENGTH);
    // Notifies client that entire file has been sent
    if(send(sockfd, sdbuf, LENGTH, 0) < 0){
      printf("ERROR: Failed to send message.\n");
      exit(1);
    }
    // close connection
    close(sockfd);
    printf("[Server] Connection with Client has been closed. Server waiting.\n");
    // Time stamp in seconds for latency
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    fprintf(f,"%f\n", time_taken);
    fclose(f);
    while(waitpid(-1, NULL, WNOHANG) > 0);
  }
} 
