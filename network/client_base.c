#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<sock.h>
#define PORT 8000
int client_base(void)
{
	int clientfd;
	struct sockaddr_in sin;
	if((clientfd=socket(AF_INET,SOCK_STREAM,0))<0)
	{
		printf("create socket error:\n");
		exit(0);
	}
	memset(&sin,0,sizeof(sin));
	sin.sin_family=AF_INET;
	sin.sin_port=htons(PORT);
	sin.sin_addr.s_addr=INADDR_ANY;
	if(connect(clientfd,(struct sockaddr*)&sin,sizeof(sin))<0)
	{
		printf("connect error:\n");
		exit(0);
	}
	return clientfd;
}