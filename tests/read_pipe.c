#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<limits.h>
#include<unistd.h>
#include<ipc.h>
#define BUFSIZE 20
int main(int argc,char *argv[])
{
	int fd;
	char *pipename=NULL;
	char buf[BUFSIZE]={0};
	//mode_t mode=0666;
	pipename=create_pipe(argv[1]);
	if((fd=open(pipename,O_RDONLY))<0)
	{
		perror("open");
		exit(1);
	}
	while(1)
	{
		if((read(fd,buf,BUFSIZE))>0)
		printf("%s\n",buf);
		else
		{
		printf("error\n");
		close(fd);
		}
		sleep(1);
	}
	close(fd);
	exit(0);
	
}
