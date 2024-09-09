/*
 * 第八章：异常控制流
 
 * 8.5.3节，接收信号试验
 * 
 * 
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

/* 定义捕获信号后处理函数 */
void handler(int sig)
{
    return;
}

unsigned int snooze(unsigned int secs)
{
    unsigned int r = sleep(secs);  //剩余未执行的时长
    printf("sleep for %d of %d secs\n",secs-r,secs);
    return r;
}

int main(int argc, char *argv[])
{   
    int i;

    printf("Command Arguments:\n");
    for(i=0;argv[i]!=NULL;i++){
        printf("argv[%d]=%s\n",i,argv[i]);
    }


    if(argc!=2){
        printf("stderror");
        exit(0);
    }

    if(signal(SIGINT,handler)==SIG_ERR){
        printf("Signle Error");
    }

    (void)snooze(atoi(argv[1]));

    return 0;
}
