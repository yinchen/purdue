#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <signal.h>
#include <sys/wait.h>

const char* usage =
"usage: myhttpd [-f|-t|-p] [<port>]                             \n"
"                                                               \n"
"   -f: Create a new process for each request                   \n"
"   -t: Create a new thread for each request                    \n"
"   -p: Pool of threads                                         \n"
"                                                               \n";

int debug = 1; // enable for debug messages

int QueueLength = 5;
int Concurrency = 0; // 0 = none, 1 = (-f) process based, 2 = (-t) thread based, 3 = (-p) thread pool based

void processRequest(int socket);
extern "C" void killzombie(int sig);

int
main(int argc, char** argv)
{
    // Print usage if not enough arguments
    if (argc < 2)
    {
        fprintf(stderr, "%s", usage);
        exit(-1);
    }
    
    int port = 0;
    
    // Get the concurrency type from the arguments
    if (argv[1][0] == '-')
    {
        if (argv[1][1] == 'f')
        {
            Concurrency = 1;
        }
        else if (argv[1][1] == 't')
        {
            Concurrency = 2;
        }
        else if (argv[1][1] == 'p')
        {
            Concurrency = 3;
        }
        else
        {
            fprintf(stderr, "%s", usage);
            exit(-1);
        }
        
        // Get the port from the arguments
        port = atoi(argv[2]);
    }
    else
    {
        Concurrency = 0;
        
        // Get the port from the arguments
        port = atoi(argv[1]);
    }
    
    // DEBUG
    if (debug == 1) printf("Using concurrency mode %d.\n", Concurrency);
        
    // Catch the zombie processes
    struct sigaction signalAction;
    
    signalAction.sa_handler = killzombie;
    sigemptyset(&signalAction.sa_mask);
    signalAction.sa_flags = SA_RESTART;
    
    int error1 = sigaction(SIGCHLD, &signalAction, NULL);
    if (error1) 
    {
        perror("sigaction");
        exit(-1);
    }
    
    // DEBUG
    if (debug == 1) printf("Launching web server on port %d... ", port);
    
    // Set the IP address and port for this server
    struct sockaddr_in serverIPAddress; 
    memset(&serverIPAddress, 0, sizeof(serverIPAddress));
    serverIPAddress.sin_family = AF_INET;
    serverIPAddress.sin_addr.s_addr = INADDR_ANY;
    serverIPAddress.sin_port = htons((u_short) port);

    // Allocate a socket
    int masterSocket =  socket(PF_INET, SOCK_STREAM, 0);
    if (masterSocket < 0)
    {
        perror("socket");
        exit(-1);
    }
    
    // Set socket options to reuse port. Otherwise we will
    // have to wait about 2 minutes before reusing the sae port number
    int optval = 1; 
    int err = setsockopt(masterSocket, SOL_SOCKET, SO_REUSEADDR, 
    (char*) &optval, sizeof(int));

    // Bind the socket to the IP address and port
    int error = bind(masterSocket,
        (struct sockaddr *)&serverIPAddress,
        sizeof(serverIPAddress));
    if (error)
    {
        perror("bind");
        exit(-1);
    }

    // Put socket in listening mode and set the 
    // size of the queue of unprocessed connections
    error = listen( masterSocket, QueueLength);
    if (error)
    {
        perror("listen");
        exit(-1);
    }

    // DEBUG
    if (debug == 1) printf("Complete.\n");
        
    while (1)
    {
        // Accept incoming connections
        struct sockaddr_in clientIPAddress;
        int alen = sizeof(clientIPAddress);
        int slaveSocket = accept(masterSocket,
            (struct sockaddr *)&clientIPAddress,
            (socklen_t*)&alen);

        if (slaveSocket < 0)
        {
            perror("accept");
            exit(-1);
        }
        
        if (Concurrency == 1)
        {
            pid_t slave = fork();
            
            if (slave == 0)
            {
                // Process request.
                processRequest(slaveSocket);
                
                // Close socket
                close(slaveSocket);
                
                exit(1);
            }
        }
        else
        {
            // Process request.
            processRequest(slaveSocket);            
        }

        // Close socket
        close(slaveSocket);
    }  
}

void
processRequest(int socket)
{
    // Buffer used to store the name received from the client
    const int size = 1024;
    char currString[size + 1];
    int n;
    int length = 0;

    // Currently character read
    unsigned char newChar;

    // Last character read
    unsigned char oldChar = 0;
    
    // Flag for GET request
    int hasGET = 0;
    
    // Requested document path
    char docPath[size + 1] = {0};

    while (n = read(socket, &newChar, sizeof(newChar)))
    {
        if (newChar == ' ')
        {
            if (hasGET == 0)
            {
                hasGET = 1;
            }
            else
            {
                currString[length] = 0;
                strcpy(docPath, currString);
            }
        }
        else if (newChar == '\n' && oldChar == '\r')
        {
            break;
        }
        else
        {
            oldChar = newChar;
            
            if (hasGET == 1)
            {
                currString[length] = newChar;
                length++;
            }
        }
    }
    
    // Map document path to server path
    char cwd[size + 1] = {0};
    getcwd(cwd, sizeof(cwd));
    
    if (strncmp(docPath, "/icons", strlen("/icons")) == 0)
    {
        strcat(cwd, "/http-root-dir/");
        strcat(cwd, docPath);
    }
    else if (strncmp(docPath, "/htdocs", strlen("/icons")) == 0)
    {
        strcat(cwd, "/http-root-dir/");
        strcat(cwd, docPath);
    }
    else
    {
        if (strcmp(docPath, "/") == 0)
        {
            strcpy(docPath, "/index.html");
        }
        
        strcat(cwd, "/http-root-dir/htdocs");
        strcat(cwd, docPath);
    }
    
    // Determine requested content type
    char contentType[size + 1] = {0};
    
    if (strstr(docPath, ".html") != 0)
    {
        strcpy(contentType, "text/html");
    }
    else if (strstr(docPath, ".jpg") != 0)
    {
        strcpy(contentType, "image/jpeg");
    }
    else if (strstr(docPath, ".gif") != 0)
    {
        strcpy(contentType, "image/gif");
    }
    else
    {
        strcpy(contentType, "text/plain");
    }
    
    FILE *document;
    if (strstr(contentType, "image/") != 0)
        document = fopen(cwd, "rb");
    else
        document = fopen(cwd, "r");
    
    if (document > 0)
    {    
        fseek(document, 0, SEEK_END);
        long length = ftell(document);
        rewind(document);
        
        char* slen = (char*)malloc(sizeof(char) * 16);
        sprintf(slen, "%d", length);
        
        write(socket, "HTTP/1.1 200 OK", 15);
        write(socket, "\n\r", 2);
        write(socket, "Server: Mattserv 1.0", 20);
        write(socket, "\n\r", 2);
        write(socket, "Content-Type: ", 14);
        write(socket, contentType, strlen(contentType));
        
        if (strstr(contentType, "image/") != 0)
        {
            write(socket, "\n\r", 2);
            write(socket, "Content-Transfer-Encoding: ", 27);
            write(socket, "binary", 6);
        }
        
        write(socket, "\n\r", 2);
        write(socket, "Content-Length: ", 16);
        write(socket, slen, strlen(slen));
        write(socket, "\n\r", 2);
        write(socket, "\n\r", 2);
        
        // char *line;
        // line = new char[size + 1];
        // while (fgets(line, size + 1, document))
        // {
        //     write(socket, line, strlen(line));
        // }
        
        char *buff = (char*)malloc(sizeof(char) * 1024);
        
        size_t result;
        while ((result = fread(buff, 1, 1024, document)) > 0)
            write(socket, buff, result);
        
        fclose(document);
    }
    else
    {
        const char *message = "File not found";
        write(socket, "HTTP/1.1", 8);
        write(socket, " ", 1);
        write(socket, "404", 3);
        write(socket, " ", 1);
        write(socket, "File", 4);
        write(socket, "Not", 3);
        write(socket, "Found", 5);
        write(socket, "\n\r", 2);
        write(socket, "Server:", 7);
        write(socket, " ", 1);
        write(socket, "Mattserv 1.0", 12);
        write(socket, "\n\r", 2);
        write(socket, "Content-type:", 13);
        write(socket, " ", 1);
        write(socket, "text/html", 9);
        write(socket, "\n\r", 2);
        write(socket, "\n\r", 2);
        write(socket, message, strlen(message));
    }
}
    
extern "C" void killzombie(int sig)
{
    int pid = wait3(0, 0, NULL);
    while(waitpid(-1, NULL, WNOHANG) > 0);
}
