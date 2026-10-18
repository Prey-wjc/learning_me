#include<copy.h>
int process_create(const char* srcfile,const char* destfile,int pronum,int blocksize){
	pid_t pid;
	int i;
	int offset;
	for(i=0;i<pronum;i++){
		pid=fork();
		if(pid==0) {
			offset=i*blocksize;
			char str_blocksize[10];
			char str_offset[10];
			bzero(str_blocksize,10);
			bzero(str_offset,10);
			snprintf(str_blocksize,sizeof(str_blocksize),"%d",blocksize);
			snprintf(str_offset,sizeof(str_offset),"%d",offset);
			printf("child %d preparing to exec, offset=%s, size=%s\n", i, str_offset, str_blocksize);
			execl("/home/colin/learn/PROCESS/PROCESS_COPY/Mod/copy","copy",srcfile,destfile,str_offset,str_blocksize,NULL);
			perror("execl failed");
			exit(1);
		}
	}
}
