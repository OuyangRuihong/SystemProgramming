/*************************************************************************
	> File Name: fake_sscanf.c
	> Author:OuyangRuihong 
	> Mail:845540021@qq.com 
	> Created Time: 2019年05月12日 星期日 15时36分56秒
 ************************************************************************/

#include<stdio.h>
int main() {
    char str1[20] = "192.168.1.2";
    int ip1[4] = {0};
    sscanf(str1, "%d.%d.%d.%d", ip1, ip1 + 1, ip1 + 2, ip1 + 3);
    printf("%d.%d.%d.%d\n", ip1[0], ip1[1], ip1[2], ip1[3]);
}
