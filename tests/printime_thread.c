#include <stdio.h>
#include <unistd.h>
#include <timer.h>
#include <pthread.h>

static void *print_time(void *arg)
{
	char *systime=NULL;
	while(1)
	{
	 	systime=time_get();
	 	printf("time is:%s",systime);
	 	sleep(1);
	}
	return 0;
}
int main(int argc, char *argv[])
{
	pthread_t thread;
	int ret = -1;
    ret=pthread_create(&thread,NULL,print_time,NULL);
	if(ret<0)
	{
		printf("[%s:%d]: pthread_create fail!\n",__func__,__LINE__);
		return -1;
	}
	//sleep(1);
	pthread_join(thread,NULL);
	return 0;
}

