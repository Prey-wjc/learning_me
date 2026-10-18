#include<copy.h>
bool check_pram(int argc,const char* srcfile,int pronum){
	if(argc<3){
		printf("参数数量异常\n");
		return false;
	}
	if((access(srcfile,F_OK))==-1){
		printf("目标文件不存在\n");
		return false;
	}
	if(pronum<=0||pronum>100){
		printf("进程数量异常\n");
		return false;
	}
	return true;
}
