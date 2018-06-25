#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>

#define PORT 4444 
int main()
{
	int server_fd;
	int opt;
	struct sockaddr_in address;
	int new_socket;
	int nbytes;
	char buffer[1024];
	int addrlen = sizeof(address);
	

	server_fd = socket(AF_INET,SOCK_STREAM,0);

	if(server_fd < 0)
	{
		printf("Socket could not be created\n");
		exit(1);
	}

	if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR|SO_REUSEPORT, &opt, sizeof(opt)) < 0)
	{
		printf("Failed to setsockopt");
		exit(1);
	}

	address.sin_family = AF_INET;
	address.sin_port = htons(PORT);
	address.sin_addr.s_addr = INADDR_ANY;

	if(bind(server_fd, (struct sockaddr *)&address, sizeof(address))<0)
	{
		perror("Bind Error\n");
		exit(1);
	}

	if(listen(server_fd, 3) < 0)
	{
		printf("Listen Error\n");
		exit(1);
	}

	new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);

	if(new_socket < 0)
	{
		perror("Accept Error");
		exit(1);
	}

	nbytes = recv(new_socket, buffer, 1024,0);

	printf("%s\n", buffer);
	
	send(new_socket, "Hello From Server", 18, 0);

	return 0;
		
}
