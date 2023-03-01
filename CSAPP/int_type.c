#include <stdio.h>


typedef unsigned char * byte_pointer;


/*
* 输出指针指向地址的值
*/
void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for(i=0;i<len;i++)
    {
         printf("[%p] - %.2x\n",start+i, start[i]);  // [地址] 地址对应存储的值
    }
    printf("\n");
}


/*
* 针对整数类型进行测试
*/
void int_demo()
{
    printf("int type size = %lu Bytes", sizeof(int));

}

void float_demo()
{
    printf("OK");
}

int main()
{
    int *z;
    int b = -2147483648;  //-2^31 TMin
    int c = 2147483648-1; //2^31-1 TMax

    z = &c;



    // printf("%lu\n",sizeof(int));
    show_bytes((byte_pointer) z,sizeof(int));


    int_demo();

    
    

    return 0;
}