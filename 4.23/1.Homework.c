/*************************************************************************
	> File Name: 1.Homework.c
	> Author:OuyangRuihong 
	> Mail:845540021@qq.com 
	> Created Time: 2019年04月22日 星期一 20时44分34秒
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(){    
	char hostname[32];    
	char* name;    
	char* path;    
	name = getenv("LOGNAME");    
	path = getenv("PWD");    
	gethostname(hostname,sizeof(hostname));    
	printf("\033[;31m%s\033[0m",name);    
	printf("\033[;32m@\033[0m");    
	printf("\033[;33m%s\033[0m",hostname);    
	printf("\033[;31m:\033[0m");    
	printf("\033[;34m%s \n",path);    
	return 0;
}
