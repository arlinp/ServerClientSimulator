# Lab 2: Client/Server Chat Room Simulation

This project was useful for learning Socket network programming in C and understand the fundamental operations of web servers. At a fundamental level, the web server and the client are C programs. The server accepts HTTP request over a TCP or UDP network socket while the client simulates a web browser. The web server handles multiple incoming HTTP GET requests and sends a response back to the client. When the web server receives a request from the client, it parses the HTTP request and returns an HTML file for the requested content or an error message letting them know the URL requested is invalid.

## Analysis
![Average Latency](uploads/e4278a48f11fe11826072a9aa8c76bdc/plot.png)

To analyze the network, we collected the time required for the one-way transfer of data between two server and client. As indicated in the graph, the TCP transport protocol performed better on average than the UDP transport protocol. Based on our data, overall the latency decreases as there are more clients for both the UDP and the TCP. Our UDP data had unexpected behavior as it approached 10,000 clients, which was that the latency actually increased. Although we do not currently know why the latency increased for UDP, it may be attributed to threading or how/when time was collected.

## Group members:

Working on Server:<br/>
Reuben Fresquez - Graduate <br/>
Amber Sustaita - Graduate <br/>

Working on Client:<br/>
Arlin Pedregon - Undergraduate <br/>
Lauren Pascoe - Undergraduate <br/>

[More on division of labor](Work-Division)

## Libraries
The following include the libraries that were used in our program:<br/>

`arpa/inet.h`<br/>
`ctype.h`<br/>
`math.h`<br/>
`netdb.h` <br/>
`netinet/in.h`<br/>
`signal.h`<br/>
`string.h`<br/>
`stdlib.h`<br/>
`stdio.h`<br/>
`sys/socket.h`<br/>
`sys/types.h`<br/>
`sys/wait.h`<br/>
`unistd.h`<br/>


## Client

The client parses the URL to get the server IP address and port number and establish a connection with the web server via whichever connection type is requested. It accepts one optional input, which is the requested URL. If the user did not initially request a URL, the terminal will prompt the client to enter a URL.

`$> ./client <URL> <TCP or UDP>`

[More on how Client.c operates](How-It-Works/Client.c) or see the code for comments.

## Server
The server maintains a high availability to prevent crashing. The server accepts connections from a designated port; this port assigns by default or as a user arguments before running the server. The user has the option to select the type of communication socket they would like to use either TCP or UDP using the following command in the terminal:

`$> ./webserver <port number> <TCP or UDP>` 

[More on how Webserver.c operates](How-It-Works/Webserver.c) or see the code for comments.

## How to run the programs
Add files to a directory and Make the files in your terminal:<br/>  
`$> make clean`<br/>
`$> make`

Run the server first:  `$> ./webserver <port number> <TCP or UDP>`

Then run the client:  `$> ./client <URL> <TCP or UDP>`

The programs then do the rest automatically. Once the URL has been read, the client will close its' socket and exits the program while the server remains open and awaiting more connections. If the URL is not correct, the user will receive a error message.

## Shell scripts
To run the shell scripts:
Use `./webserver.sh <port number> <TCP or UDP>` for the webserver shell scripts.<br/>
`./client.sh <url> <TCP or UDP> <number of clients>` for the client shell scripts.<br/>
The shell scripts run both "make" and "make clean"<br/>
otherwise, the user must run:<br/>
1. `make clean`<br/>
2. `make`<br/>
3. same as spec

## Example (Running the program)

### TCP
> Webserver
>
>`$> ./webserver 8080 TCP`
>

>Client
>
>`$> ./client 127.0.0.1:8080 TCP`

### UDP
> Webserver
>
>`$> ./webserver 8080 UDP`
>

>Client
>
>`$> ./client 127.0.0.1:8080 UDP`
--- 
