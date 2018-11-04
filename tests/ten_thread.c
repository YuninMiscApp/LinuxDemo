#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define N 3

static void *task_routine(void *arg)
{	
	int i=(int)arg;
	while(1)
	{
		sleep(1);
 		printf("my %d pid is:%lu\n",i,pthread_self());
	}
	return NULL;
		
}
int main(int argc, char *argv[])
{	
	int i;
	int ret=-1;
	pthread_t thread;
	for(i=0;i<N;i++)
	{
		ret=pthread_create(&thread,NULL,task_routine,(void*)i);
		if(ret<0)
		{
			printf("[%s:%d]: pthread_create fail!\n",__func__,__LINE__);
			return -1;
		}
		
	}
	while(1)
	{
		sleep(2);
		printf("I am the main pthread:%lu\n",pthread_self());
	}
	
	
	return 0;
}
