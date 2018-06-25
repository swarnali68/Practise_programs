#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

#define PORT 4444

int main()
{
	int client_fd;
	struct sockaddr_in serv_addr;
	int nbytes;
	char buffer[1024];

	client_fd = socket(AF_INET, SOCK_STREAM, 0);

	if(client_fd < 0)
	{
		perror("Socket Failure");
		exit(EXIT_FAILURE);
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	
	/*if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    	{
        	printf("\nInvalid address/ Address not supported \n");
        	return -1;
    	}*/

	if(connect(client_fd,(struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
	{
		perror("Connect Failed");
		exit(EXIT_FAILURE);
	}

	send(client_fd, "Hello from client", 18, 0);

	nbytes = recv(client_fd, buffer, 1024,0);
	printf("%s\n", buffer);	
}
