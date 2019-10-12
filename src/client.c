#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 
  
#define MAXLINE 1024 
#define MAX 80 
#define SA struct sockaddr

int TCP();
void func(int sockfd);
int UDP();
  
// Driver code 
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
    char* hello = "Hello from client"; 
    struct sockaddr_in     servaddr; 
  
    // Creating socket file descriptor 
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) { 
        perror("socket creation failed"); 
        exit(EXIT_FAILURE); 
    } 
  
    memset(&servaddr, 0, sizeof(servaddr)); 
      
    // Filling server information 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(PORT); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
      
    int n, len; 
      
    sendto(sockfd, (const char* )hello, strlen(hello), 
        MSG_CONFIRM, (const struct sockaddr*) &servaddr,  
            sizeof(servaddr)); 
    printf("Hello message sent.\n"); 
          
    n = recvfrom(sockfd, (char* )buffer, MAXLINE,  
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
  
int TCP(int port) 
{ 
    /* Variable Definition */
	int sockfd; 
	int nsockfd;
	char revbuf[LENGTH]; 
	struct sockaddr_in remote_addr;

	/* Get the Socket file descriptor */
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
	  fprintf(stderr, "ERROR: Failed to obtain Socket Descriptor! (errno = %d)\n",errno);
	  exit(1);
	}
    
    /* Fill the socket address struct */
	remote_addr.sin_family = AF_INET; 
	remote_addr.sin_port = htons(PORT); 
	inet_pton(AF_INET, "127.0.0.1", &remote_addr.sin_addr); 
	bzero(&(remote_addr.sin_zero), 8);
  
    /* Try to connect the remote */
	if (connect(sockfd, (struct sockaddr *)&remote_addr, sizeof(struct sockaddr)) == -1)
	{
	    error("ERROR: Failed to connect to the host!\n");
	}
  
	else
	  printf("[Client] Connected to server at port %d...ok!\n", PORT);

	* Receive File from Server */
	printf("[Client] Receiveing file from Server and saving it as final.txt...");
	char* fr_name = "/home/aryan/Desktop/progetto/final.txt";
	FILE *fr = fopen(fr_name, "a");
	if(fr == NULL)
		printf("File %s Cannot be opened.\n", fr_name);
	else
	{
	    bzero(revbuf, LENGTH); 
	    int fr_block_sz = 0;
	    int success = 0;
	    //while(success == 0)
	    //{
	        while(fr_block_sz = recv(sockfd, revbuf, LENGTH, 0))
	        {
	            if(fr_block_sz < 0)
	            {
	                error("Receive file error.\n");
	            }
	            int write_sz = fwrite(revbuf, sizeof(char), fr_block_sz, fr);
	            if(write_sz < fr_block_sz)
	            {
	                error("File write failed.\n");
	            }
				else if(fr_block_sz)
				{
					break;
				}
	            bzero(revbuf, LENGTH);
	        }
	        printf("Ok received from server!\n");
	        success = 1;
	        fclose(fr);
	    //}
	}
	close (sockfd);
	printf("[Client] Connection lost.\n");
	return (0);
        
}
