/*
 * 第八章：异常控制流
 
 * 8.5.3节，接收信号试验
 * 
 * 
*/

#include <stdio.h>
#include <time.h>
#include<signal.h>


int main(int argc, char *argv[])
{   
    int i;

    printf("Command Arguments:\n");
    for(i=0;argv[i]!=NULL;i++){
        printf("argv[%d]=%s",i,argv[i]);
    }

    return 0;
}