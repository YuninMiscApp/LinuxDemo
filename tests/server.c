#include<stdio.h>
#include<sock.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#define MAX_LINE 20
int main(int argc,char *argv[])
{	
	char buf[MAX_LINE]={0};
	int t=0;
	int connect_fd;
	int listen_fd;
	listen_fd=server_base();
	if((connect_fd=accept(listen_fd,(struct sockaddr*)NULL,NULL))==-1)
	{
		printf("accept socket fail:\n");
		exit(0);
	}
		
	while(1)
	{	
		read(connect_fd,buf,MAX_LINE);
		printf("%s,number:%d\n",buf,t++);
		memset(buf,0,MAX_LINE);
		sleep(1);
	}
	close(connect_fd);
	return 0;
}