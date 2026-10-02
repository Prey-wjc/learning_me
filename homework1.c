#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<regex.h>
#include<unistd.h>
#include<string.h>
#include<sys/mman.h>
int main()
{
	int fd=open("url.txt",O_RDWR);
	int fsize=lseek(fd,0,SEEK_END);
	char*mmap_ptr=NULL;
	char*comp_ptr=NULL;
	mmap_ptr=mmap(NULL,fsize,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
	//"<a\([[:space:]]\+[^=[:space:]>]\+\(=\"[^\"]*\"\)\?\)*[[:space:]]*>[^<]*</a>"
	comp_ptr=mmap_ptr;
	close(fd);
	char*regstr="<a[^>]*href=\"\\([^\"]*\\)\"[^>]*>\\([^<]*\\)</a>";
	int regnum=3;
	regex_t reg;
	regcomp(&reg,regstr,0);
	regmatch_t match[regnum];
	char href[1024];
	char text[1024];
	while(regexec(&reg,mmap_ptr,regnum,match,0)==0){
		bzero(text,sizeof(text));
		bzero(href,sizeof(href));
		snprintf(text,match[1].rm_eo-match[1].rm_so+1,"%s",mmap_ptr+match[1].rm_so);
		snprintf(href,match[2].rm_eo-match[2].rm_so+1,"%s",mmap_ptr+match[2].rm_so);
		mmap_ptr+=match[0].rm_eo;
		printf("%s %s\n",href,text);
	}
	regfree(&reg);
	munmap(comp_ptr,fsize);
	return 0;
}
