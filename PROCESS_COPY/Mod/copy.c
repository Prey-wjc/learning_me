#include<copy.h>
int main(int argc,char**argv)
{
	int srcfd,destfd;
	srcfd = open(argv[1],O_RDONLY);
	destfd = open(argv[2],O_WRONLY|O_CREAT,0664);
	int srcfd_copy=srcfd;
	int destfd_copy=destfd;
	lseek(srcfd,atoi(argv[3]),SEEK_SET);
	lseek(destfd,atoi(argv[3]),SEEK_SET);
	int len;
	char buffer[atoi(argv[4])];
	bzero(buffer,sizeof(buffer));
	len = read(srcfd,buffer,sizeof(buffer));
	write(destfd,buffer,len);
	close(srcfd_copy);
	close(destfd_copy);
}
