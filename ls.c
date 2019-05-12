/*************************************************************************
	> File Name: ls.c
	> Author:OuyangRuihong 
	> Mail:845540021@qq.com 
	> Created Time: 2019年05月11日 星期六 14时43分26秒
 ************************************************************************/

#include<stdio.h>
#include<dirent.h>
#include<sys/types.h>
#include<unistd.h>
#include<pwd.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<sys/ioclt.h>

#define LEN 512
//0 : ls_opt
//1: ls -a
//2:ls -l
//3:ls -al

int ls_opt = 0;
void do_ls(char *);
char work_dir[LEN];
void show_file_info(char *filename, struct stat *info);
void do_stat(char *);
void size_window(char file_name[][LEN], int cnt, int *row, int *col);

int main( int argc, char *argv[]) {
    int opt;
    getwd(work_dir, LEN);     //获得当前工作目录
    while((opt = getopt(argc, argv, "al")) != -1) {
        switch (opt) {
            case 'a' :
                printf("a\n");
                ls_opt++;
                break;
            case 'l' :
                printf("l\n");
                ls_opt += 2;
                break;
            default:
                exit(1);
        }
    }

    argc -= (optind - 1);
    argv += (optind - 1);
    printf("argv[%d] = %s\n", argc +1, *(argv + 1));
    
    if(argc == 1) {
        do_ls(".");
    } else {
        while(--argc) {
            do_ls(*argv);
        }
    }
    return 0;
}

int cmp_name(const void* _a, const void* _b) {
    char *a = (char*)_a;
    char *b = (char*)_b;
    return strcmp(a, b);
}

void do_ls(char *dirname) {
    printf("%s:\n", dirname);
    chdir(work_dir);
    DIR *dir_ptr = NULL;
    struct dirent *direntp;
    char file_name[1024][256] = {0}; //保存

    if ((dir_ptr = opendir(dirname)) == NULL) {
        perror("opendir");
    } else {
        int cnt = 0;
        while ((direntp = readdir(dir_ptr)) != NULL) {
            strcpy(file_name[cnt++], dirent->d_name);
            printf("%s\n", direntp->d_name);
        }
        qsort(file_name, cnt, LEN, cmp_name);
    /*   for (int i = 0; i < cnt; i++) {
            printf("file_name[%d = %s\n]". i, file_name[i]);
        }*/
        if (ls_opt >= 2) {
            for (int i = 0; i < cnt; i++) {
            do_stat(file_name[i]);
            }        
         }
    }
}

void size_window(char file_name[][LEN], int cnt, int *row, int *col) {
    struct winsize size;
    int len[cnt];
    int max;
    memset(len, 0,sizeof(int) * cnt);
    if (isatty(STDOUT_FILENO) == 0) {
        exit(1);
    }
    if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0) {
        perror("ioclt");
        exit(1);
    }
    printf("size_row = %d, size_col = %d\n", size.ws_row, size.ws_col);
    
    for (int i= 0; i < cnt; i++) {
        strcpy(len[i], strlen(filename[i]));
        if(max < len[i]) max = len[i];
    }
    if (max > size.ws_col) {
        *row =cnt;
        *col = 1;
        return;
    }

    int try_begin = 0;
    for (it i = 0, tmp = 0; i < cnt; i++) {
        tmp += (len[i] + 2);
        if(tmp > size.ws_col) {
            try
        }
    }
}

void do_stat(char file_name[][LEN]) {
    struct stat info;
    if (stat(file_name, &info) == -1) {
        perror(filename);
    } else {
        show_file_info(filename, &info);
    }
}

void show_file_info(char *filename, struct stat *info) {
    char modestr[11] = "----------";
    char *uid_to_name, 
    mode_to_letters(info->st_mode, modestr);
	printf("%s ", modestr);
	printf("%4d ", info->st_nlink);
	printf("%8s ", uid_to_name(info->st_uid));
	printf("%8ld ", (long))
}

void mode_to_letters(mode_t mode, char *str) {
    if(S_ISDIR(mode)) str[0] = 'd';
    if(S_ISCHR(mode)) str[0] = 'c';
    if(S_ISBLK(mode)) str[0] = 'b';
    if(S_ISSOCK(mode)) str[0] = 's';
    if(S_ISFIFP(mode)) str[0] = 'p';
    if(S_ISLNK(mode)) str[0] = 'l';
    if(S_ISREG(mode)) str[0] = '-';

    if(mode & S_IRUSR) str[1] = 'r';
    if(mode & S_IRUSR) str[2] = 'w';
	if(mode & S_IRUSR) str[3] = 'x';

    if(mode & S_IRGRP) str[4] = 'r';
    if(mode & S_IWGRP) srt[5] = 'w';
    if(mode & S_IXGRP) str[6] = 'x';

    if(mode & S_IROTH) str[7] = 'r';
    if(mode & S_IWOTH) srt[8] = 'w';
    if(mode & S_IXOTH) str[9] = 'x';
}

char *uid_to_name(uid_t uid) {
	struct group *gr_ptr;
	static char numstr[10] = {0};
	if((gr_ptr = getgrgid
}

void uid_to_name(uid_t)
void gid_to_name(gid_t)
