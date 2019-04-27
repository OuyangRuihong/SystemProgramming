/*************************************************************************
	> File Name: 1.Homework.c
	> Author:OuyangRuihong 
	> Mail:845540021@qq.com 
	> Created Time: 2019年04月22日 星期一 20时44分34秒
 ************************************************************************/

#include <stdio.h>
#include <pwd.h>
#include <unistd.h>
int main() {
    struct passwd *pwd;
    pwd = getpwuid(getuid());
	printf("\033[;34m%s \n",pwd->pw_name);    
	return 0;
}
