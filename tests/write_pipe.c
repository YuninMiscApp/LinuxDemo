#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<limits.h>
#include <unistd.h> 
#define BUFSIZE 20
int main(int argc,char *argv[])
{
	int fd;
	char buf[BUFSIZE]={"hello,world!"};
	if((fd=open(argv[1],O_WRONLY))<0)
	{
		perror("open");
		exit(1);
	}
	printf("write hello world to pipe per sec:\n");
	while(1)
	{
		if((write(fd,buf,BUFSIZE))<0)
		{
			perror("write");
			close(fd);
			exit(1);
		}
		sleep(1);
	}
	close(fd);
	exit(0);
	
}

