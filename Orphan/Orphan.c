#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
#include<sys/mman.h>
#include<unistd.h>

#define msg "子进程未关闭"

int main()
{
	int fds[2];
	if((pipe(fds))==-1) {
		perror("pipe create failed");
		exit(1);
	}
	int i;
	pid_t pid;
	for(i=0;i<5;i++){
		pid=fork();
		if(pid==0) {
			close(fds[0]);
			while(1){
				sleep(1);
				write(fds[1],msg,strlen(msg));
			}
		}
	}
	sleep(20);
	close(fds[1]);
	exit(1);
}
