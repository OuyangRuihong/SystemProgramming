/*************************************************************************
	> File Name: ip.c
	> Author:OuyangRuihong 
	> Mail:845540021@qq.com 
	> Created Time: 2019年05月12日 星期日 14时36分59秒
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[]) {
    int ip[4];
    int ip1[4];
    int ip2[4];
    int netmask = 255;
    while((scanf("%d.%d.%d.%d\n", &ip[0], &ip[1], &ip[2], &ip[3])) != EOF) {
        scanf("%d.%d.%d.%d\n", &ip1[0], &ip1[1], &ip1[2], &ip1[3]);
        scanf("%d.%d.%d.%d\n", &ip2[0], &ip2[1], &ip2[2], &ip2[3]);
        
        if((ip1[0] & netmask) == (ip2[0] & netmask)) {
            if((ip1[1] & netmask) == (ip2[1] & netmask)) {
               if((ip1[2] & netmask) == (ip2[2] & netmask)) {
                    printf("YES");
                }
                printf("NO");
            }
            printf("NO");
        } else {
            printf("NO");
        }
    
        return 0;
    }
}
