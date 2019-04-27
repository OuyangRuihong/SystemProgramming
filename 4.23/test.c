/*************************************************************************
	> File Name: test.c
	> Author:OuyangRuihong 
	> Mail:845540021@qq.com 
	> Created Time: 2019年04月26日 星期五 21时37分43秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pwd.h>
int main (void)
{

       struct passwd *passwd;
       passwd=getpwuid(getuid());
       /** passwd=getcwnam("phpos"); **/
       printf("Username:%s\n",passwd->pw_name);
       printf("Password:%s\n",passwd->pw_passwd);
       printf("uid:%d\n",passwd->pw_uid);
       printf("gid:%d\n",passwd->pw_gid);
       printf("shell:%s\n",passwd->pw_shell);
       printf("dir:%s\n",passwd->pw_dir);

       return 0;
}
