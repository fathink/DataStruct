/*
 * 第二章：信息的表示和处理
 *
 * 测试不同类型数据在内存中的表示
 * 
 * 
*/

#include <stdio.h>


typedef unsigned char * byte_pointer;  // 定义指向无符号字符指针


/*
* 打印指针和指针指向的内容
*/
void show_bytes(byte_pointer start, size_t len)
{
    size_t i;

    // printf("\n\n-----Address-------value----\n");
    printf("\n----[address] --- value----\n");
    for(i=0;i<len;i++)
    {
         printf("[%p]    %.2x    ｜\n",start+i,start[i]);  // [地址] - 值, 值以十六进制方式输出
    }
    printf("------------------------\n");
    
}



/*
* int类型数据demo
*/
void int_demo()
{
    printf("int type size = %lu Bytes\n",sizeof(int));
    int TMin = -2147483648;   //-2^31 最小的整数, 1000000...
    int TMax = 2147483648-1;  //2^31-1 最大整数, 0111111...

    int *p1 = &TMin;
    int *p2 = &TMax;

    // printf("%p\n",&p1);
    //打印p1指针本身的地址的存储地址和值
    show_bytes((byte_pointer)(&p1), sizeof(p1)); 
    
    // 打印最小整数和最大整数十六进制输出
    show_bytes((byte_pointer)p1, sizeof(*p1)); 
    show_bytes((byte_pointer)p2, sizeof(*p2));

    printf("%d",TMax+1);
    

}

/*
* float(浮点)类型数据demo
*/
void float_demo()
{
    float a = 1.0;  //01111111 10000000 00000000 00000000,(-1)^s * 2^(e-127)*(1+f) = 2^0 * 1.0 = 1.0
    printf("float type size = %lu Bytes\n", sizeof(float));

    float *p = &a;

    show_bytes((byte_pointer)p,sizeof(*p));


    float b = 1.0+1.0;
    float *p2 = &b;
    show_bytes((byte_pointer)p2,sizeof(*p2));

}

int main()
{
    int_demo();
   
    // float_demo();

    return 0;


    
}