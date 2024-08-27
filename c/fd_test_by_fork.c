/*
* 采用fork函数对写文件的影响
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>

void test_1()
{
    //在fork之前打开文件，父子进程共享文件表，指向共同的打开文件表，共享文件的偏移位置，文件
    int fd = open("fd_data.txt", O_RDONLY); 
    assert( fd != -1);  

    pid_t pid = fork();  

    // 子进程
    if(pid==0){
        char buff[128] = {0};
        read(fd, buff, 1); 
        printf("child process_id=%d, read: %s\n", getpid(), buff);

        sleep(1);

        read(fd, buff, 1);
        printf("child process_id=%d, read: %s\n", getpid(), buff);

    }

    //父进程
    else{
        char buff[128] = {0};
        read(fd, buff, 1); 
        printf("main process_id=%d, read: %s\n", getpid(), buff);

        sleep(1);

        read(fd, buff, 1);
        printf("main process_id=%d, read: %s\n", getpid(), buff);
    }

    close(fd);
    printf("process id=%d, finished\n", getpid());
}

int main(int args, char *argv[])
{
   
    test_1();

    return 0;
}