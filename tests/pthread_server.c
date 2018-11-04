#include<stdio.h>
#include<sock.h>
#include<sys/socket.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include <pthread.h>

#define MAX_LINE 30
char buf[MAX_LINE]={0};
void *thread(void *arg);
int main(int argc,char *argv[])
{
	pthread_t tid;
	int *connect_fd;
	int listen_fd;
	listen_fd=server_base();
	while(1)
	{
		connect_fd=malloc(sizeof(int));
		*connect_fd=accept(listen_fd,(struct sockaddr*)NULL,NULL);
		pthread_create(&tid,NULL,thread,connect_fd);
		
	}
	
	return 0;
}
void *thread(void *arg)
{	
	int t=0;
	int connfd=*((int*)arg);
	while(1)
	{
	read(connfd,buf,MAX_LINE);
	printf("%s,number:%d\n",buf,t++);
	memset(buf,0,MAX_LINE);
	sleep(1);
	}
	return NULL;
}

