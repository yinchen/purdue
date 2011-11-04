#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

const char* usage =
"usage: myhttpd [-f|-t|-p] [<port>]                             \n"
"                                                               \n"
"   -f: Create a new process for each request                   \n"
"   -t: Create a new thread for each request                    \n"
"   -p: Pool of threads                                         \n"
"                                                               \n";

int QueueLength = 5;

// Processes time request
void processRequest(int socket);

int
main(int argc, char** argv)
{
    // Print usage if not enough arguments
    if (argc < 2)
    {
        fprintf(stderr, "%s", usage);
        exit(-1);
    }
  
    // Get the port from the arguments
    int port = atoi(argv[1]);

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

        // Process request.
        processRequest(slaveSocket);

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
    document = fopen(cwd, "r");
    
    if (document > 0)
    {    
        write(socket, "HTTP/1.0", 8);
        write(socket, " ", 1);
        write(socket, "200", 3);
        write(socket, " ", 1);
        write(socket, "OK", 2);
        write(socket, "\n\r", 2);
        write(socket, "Server:", 7);
        write(socket, " ", 1);
        write(socket, "Mattserv 1.0", 12);
        write(socket, "\n\r", 2);
        write(socket, "Content-type:", 13);
        write(socket, " ", 1);
        write(socket, contentType, strlen(contentType));
        write(socket, "\n\r", 2);
        write(socket, "\n\r", 2);
        
        // char *line;
        // line = new char[size + 1];
        // while (fgets(line, size + 1, document))
        // {
        //     write(socket, line, strlen(line));
        // }
        
        fseek(document, 0, SEEK_END);
        long length = ftell(document);
        rewind(document);
        
        char *buff = (char*)malloc(sizeof(char) * length);
        
        size_t result = fread(buff, 1, length, document);
        if (result != length)
            perror("fread");
        
        write(socket, buff, length);
        
        fclose(document);
    }
    else
    {
        const char *message = "File not found";
        write(socket, "HTTP/1.0", 8);
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

