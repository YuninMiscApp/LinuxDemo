#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ctype.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<sock.h>
#define PORT   8000
int server_base(void)
{
	struct sockaddr_in sin;
	int socket_fd;
	memset(&sin,0,sizeof(sin));
	sin.sin_family=AF_INET;
	sin.sin_addr.s_addr=INADDR_ANY;
	sin.sin_port=htons(PORT);
	if((socket_fd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		printf("create socket error:\n");
		exit(0);
	}
	if(bind(socket_fd,(struct sockaddr*)&sin,sizeof(sin))==-1)
	{
		printf("bind socket error:\n");
		exit(0);
	}
	if(listen(socket_fd,10)==-1)
	{
		printf("listen socket error:\n");
		exit(0);
	}
	return socket_fd;
}