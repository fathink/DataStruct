/*
 * Author: 
 * 模拟缓存器
*/

#include "cachelab.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>

int char2int(char c){
    return c-'0';
}

void printUsage()
{
    printf("Usage: ./csim-ref [-hv] -s <num> -E <num> -b <num> -t <file>\n"
            "Options:\n"
            "  -h         Print this help message.\n"
            "  -v         Optional verbose flag.\n"
            "  -s <num>   Number of set index bits.\n"
            "  -E <num>   Number of lines per set.\n"
            "  -b <num>   Number of block offset bits.\n"
            "  -t <file>  Trace file.\n\n"
            "Examples:\n"
            "  linux>  ./csim-ref -s 4 -E 2 -b 4 -t traces/yi.trace\n"
            "  linux>  ./csim-ref -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
}


typedef struct CacheStruct
{
    int valid; //有效位 1表示占用
    int tag; //标记位
    int stamp; //时间戳，逐渐增大
}CacheLine;

CacheLine **Cache = NULL;  // 二维数组
int Hits=0 , Misses=0, Evicts=0;  //命中/不命中/替换

void InitCache(int S, int E){
    Cache = (CacheLine **)malloc(sizeof(CacheLine*) * S);
    for(int i=0; i<S; i++){
        Cache[i] = (CacheLine*)malloc(sizeof(CacheLine) * E);
        for(int j=0;j<E;j++){
            Cache[i][j].valid = 0;
            Cache[i][j].tag = -1;
            Cache[i][j].stamp = -1;

        }
    }
}

//释放缓存空间
void FreeCache(int S){
    for(int i=0;i<S;i++){
        free(Cache[i]);
    }

    free(Cache);
}

//更新Stamp
void updateStamp(int S, int E){
    for(int i=0; i<S;i++)
        for(int j=0;j<E;j++){
            if(Cache[i][j].valid == 1){
                ++Cache[i][j].stamp;   // stamp自增1
            }
        }

}

// 更新缓存
void update(uint64_t address, int s, int E, int b){
    int s_idx = (address >> b) & ( (-1U)>>(64-s) );  //获取组的索引,0,1,2,3,4...,2^s
    int tag = address >> (b+s); //获取标记位

    int MaxStamp = INT_MIN;  //初始化最小时间戳
    int MaxStamp_idx = -1; //记录块编号
    
    //遍历组内所有行，如果tag相同，则表示命中
    for(int i=0;i<E;i++){
        if((Cache[s_idx][i].valid == 1) && (Cache[s_idx][i].tag == tag)){
            Cache[s_idx][i].stamp = 0;
            ++Hits;
            return;
        }

    }

    //执行到这里，表示没有命中缓存
    //先判断是否还有空闲空间,如果有空闲空间，则占用，没有执行下一个for循环
    for(int i=0;i<E;i++){
        if(Cache[s_idx][i].valid == 0){
            Cache[s_idx][i].valid = 1;
            Cache[s_idx][i].stamp = 0;
            Cache[s_idx][i].tag = tag;
            ++Misses;
            return;
        }
    }

    // 执行到这里，表示没有命中缓存，且缓存没有空间
    // 替换逻辑(把stamp最大的块替换掉)
    ++Misses;
    ++Evicts;
    for(int i=0;i<E;i++){
        if(Cache[s_idx][i].stamp > MaxStamp){   
            MaxStamp = Cache[s_idx][i].stamp;
            MaxStamp_idx = i;
        }
    }

    Cache[s_idx][MaxStamp_idx].tag = tag;
    Cache[s_idx][MaxStamp_idx].stamp = 0;
    return ;
}

/*
 * -h: Optional help flag that prints usage info
 * -v: Optional verbose flag that displays trace info
 * -s <s>: Number of set index bits (S = 2^s is the number of sets)
 * -E <E>: Associativity (number of lines per set)
 * -b <b>: Number of block bits (B = 2^b is the block size)
 *  -t <tracefile>: Name of the valgrind trace to replay
 * 
 * Execute:  ./csim -s 4 -E 2 -b 4 -t traces/yi.trace
 * 
 */

char *path;
char str[1024];
int main(int argc, char* argv[])
{
 


    int s, E, b, size; 
    FILE * fp;
    char op;
    uint64_t address;
    
    for(int i=1; i<argc; i++){
        if (argv[i][0] == '-'){
            char tag = argv[i][1];  //s/E/b,etc
            switch (tag){
                case 'h':
                    printUsage();
                    exit(0);
                case 's':
                    s = argv[i+1][0]-'0';
                    break;
                case 'E':
                    E = argv[i+1][0]-'0';
                    break;
                case 'b':
                    b = argv[i+1][0]-'0';
                    break;
                case 't':
                    path = argv[i+1];
                    break;
                default:
                    break;

            }

        }
    }
    int S = 1 << s; // S=2^s
    InitCache(S, E);  // 初始化Cache

    // 打开文件
    fp = fopen(path, "r");
    if (fp == NULL){
        printf("open error\n");
        exit(-1);
    }

    // 遍历每一行文件
    while ( fgets(str, 100, fp) != NULL){
        sscanf(str, " %c %lx,%d", &op, &address, &size);  // 读取每一行，赋值给变量，不考虑I开头的行
        switch (op){
            case 'I':
                continue;
            case 'L':case 'S':
                update(address, s, E, b);
                break;
            case 'M':
                update(address, s, E, b);
                update(address, s, E, b);
                break;
        }
        printf("%c %lx,%d\n",op,address,size);
        
        //读取一行后更新Stamp
        updateStamp(S,E);
    }
    fclose(fp);
    FreeCache(S); // 释放Cache

    printSummary(Hits, Misses, Evicts);

    return 0;
}
