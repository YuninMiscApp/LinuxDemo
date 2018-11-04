#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<ipc.h>
char *create_pipe(char *pipename)
{
	mode_t mode=0666;
	if((mkfifo(pipename,mode))<0)
	{
		perror("failed to mkfifo:\n" );
		//printf("error=%d\n",errno);
		exit(1);
	}
	 printf("create pipe sucessfully\n");
	return pipename;
}

