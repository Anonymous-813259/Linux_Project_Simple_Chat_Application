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
	memset(&addr, '\0', sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = port;
	addr.sin_addr.s_addr = inet_addr(ip);
	connect(sock, (struct sockaddr *)&addr, sizeof(addr));
	printf("Connected to the server.\n");
	while(1){
		bzero(buffer, 1024);
		printf("Your Message:");
		gets(buffer);
		send(sock, buffer, sizeof(buffer), 0);
		bzero(buffer, 1024);
		recv(sock, buffer, sizeof(buffer), 0);
		printf("Server: %s\n",buffer);
	}
	close(sock);
	printf("Disconnected from the server.\n");
	return 0;
}
