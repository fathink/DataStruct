/*
* 采用fork函数对读写文件描述符的影响


- 文件表item结构体, 
struct file
    {
        mode_t f_mode;//表示文件是否可读或可写，FMODE_READ或FMODE_WRITE
        dev_ t  f_rdev ;// 用于/dev/tty
        off_t  f_ops;//当前文件偏移量
        unsigned short f_flags;//文件标志，O_RDONLY,O_NONBLOCK和O_SYNC
        unsigned short f_count;//打开的文件数目,文件的引用计数，只有当引用计数为0时，文件才会关闭
        unsigned short f_reada;
        struct inode *f_inode;//指向inode的结构指针，实际存储内容的地方
        struct file_operations *f_op;//文件索引指针
    }


Ref: 
[1] 介绍Linux文件管理，含文件表数据结构等信息： https://blog.csdn.net/wwwlyj123321/article/details/100298377


*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <assert.h>
#include <errno.h>


//在fork之前打开文件，父子进程共享文件表，指向共同的打开文件表，共享文件的偏移位置，父子进程的操作会相互影响
void test_1()
{
    
    int fd = open("data_fd.txt", O_RDONLY); 
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


//在fork之后打开文件，父子进程各自独立的文件表，各自独立的偏移量，两个进程的读写相对独立；
int test_2()
{
    pid_t pid = fork();  

    // 子进程
    if(pid==0){
         
        int fd = open("data_fd.txt", O_RDONLY); 
        if(fd == -1){
            printf("open file failed, errno=%d-%s\n", errno, strerror(errno));
            return 1;
        }
    
        char buff[128] = {0};
        read(fd, buff, 1); 
        printf("child process_id=%d, read: %s\n", getpid(), buff);

        sleep(1);

        read(fd, buff, 1);
        printf("child process_id=%d, read: %s\n", getpid(), buff);

        close(fd);

        //子进程写入数据
        int fd2 = open("data_fd_w.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(fd2 == -1){
            printf("errno=%d,errmsg=%s\n", errno, strerror(errno));
            return 1;
        }

        printf("Child Write\n");
        char *message = "hello world";
        int write_bytes = write(fd2, message, strlen(message));
        if(write_bytes == -1){
            printf("write_bytes=%d, errno=%d-%s\n", write_bytes, errno, strerror(errno));
            return 1;
        }
        close(fd2);

        return 0;
    }

    //父进程
    else{

        //在fork之后打开文件，父子进程各自独立的文件表，各自独立的偏移量
        int fd = open("data_fd.txt", O_RDONLY); 
        assert( fd != -1);  
    
        char buff[128] = {0};
        read(fd, buff, 1); 
        printf("main process_id=%d, read: %s\n", getpid(), buff);

        sleep(1);

        read(fd, buff, 1);
        printf("main process_id=%d, read: %s\n", getpid(), buff);

        close(fd);


        //父进程写入数据，如果是指向同样的文件，子进程先写，父进程后写，父进程会覆盖子进程的内容
        int fd2 = open("data_fd_w.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if(fd2 == -1){
            printf("errno=%d,errmsg=%s\n", errno, strerror(errno));
            return 1;
        }

        printf("Main Write\n");
        char *message = "Main hello world";
        int write_bytes = write(fd2, message, strlen(message));
        if(write_bytes == -1){
            printf("write_bytes=%d, errno=%d-%s\n", write_bytes, errno, strerror(errno));
            return 1;
        }
        close(fd2);
    }

    printf("process id=%d, finished\n", getpid());
}

// 同一个进程打开同一个文件两次，各自独立
void test_3()
{
    int fd1 = open("data_fd.txt", O_RDONLY); 
    int fd2 = open("data_fd.txt", O_RDONLY);
    printf("fd1=%d, fd2=%d\n", fd1, fd2);

    char buff[128] = {0};

    // 第一个fd先读
    read(fd1, buff, 1);
    printf("fd1=%d, read: %s\n", fd1, buff);

    // 第二个fd再读，不受第一个fd的偏移量影响
    read(fd2, buff, 1);
    printf("fd2=%d, read: %s\n", fd2, buff);
    close(fd1);
    close(fd2);
}

int main(int args, char *argv[])
{
   
    // test_1();
    // int e = test_2();
    test_3();

    return 0;
}