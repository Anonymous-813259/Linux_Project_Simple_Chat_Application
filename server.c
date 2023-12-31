#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
int main()
{
	char *ip = "127.0.0.1";
	int port = 8080;
	int server_sock, client_sock;
	struct sockaddr_in server_addr, client_addr;
	socklen_t addr_size;
	char buffer[1024];
	int n;
	server_sock = socket(AF_INET, SOCK_STREAM, 0);
	if(server_sock < 0){
		perror("[-]Socket error");
		exit(1);
	}
	printf("[+]TCP Server Socket Created.\n");
	memset(&server_addr, '\0', sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = port;
	server_addr.sin_addr.s_addr = inet_addr(ip);
	n = bind(server_sock, (struct sockaddr *)&server_add, sizeof(server_addr));
	if(n < 0){
		perror("[-]Bind Error");
		exit(1);
	}
	printf("[+]Bind to the port number: %d\n", port);
	listen(server_sock, 5);
	printf("Listening....\n");
	while(1){
		addr_size = sizezof(client_addr);
		client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_size);
		printf("[+]Client Connected.\n");
		while(1){
			bzero(buffer, 1024);
			recv(client_sock, buffer, sizeof(buffer), 0);
			printf("Client: %s\n",buffer);
			bzero(buffer, 1024);
			printf("Your Message:");
			gets(buffer);
			send(client_sock, buffer, sizeof(buffer), 0);
		}
		close(client_sock);
		printf("Disconnected from the server.\n");
	}
	return 0;
}
