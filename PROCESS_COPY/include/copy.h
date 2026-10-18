#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<stdbool.h>

bool check_pram(int ,const char* ,int);
int block_cur(const char*,int);
int process_create(const char* ,const char* ,int ,int);
int process_wait();
