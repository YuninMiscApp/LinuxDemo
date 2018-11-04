#include<stdio.h>
#include<sock.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char * argv [])
{	
	int sockfd;
	char *str="bullshit!";
	sockfd=client_base();
	printf("send bullsit! per second:\n");
	while(1)
	{	
		write(sockfd,str,12);
		sleep(1);
	}
	close(sockfd);
	return 0;
}
