#include<copy.h>
int process_wait(){
	pid_t zpid;
	while((zpid=wait(NULL))>0);
	return 0;
}
