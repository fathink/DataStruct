/*
函数指针与指针函数
*/

#include <stdio.h>


/*
    函数指针，修饰指针，指针指向一个函数
*/
int (*p)(int x, int y);  //注意：这里的括号不能掉，因为括号()的运算优先级比解引用运算符*高


/*
    指针函数，指函数的返回值是一个指针
*/
int *p1(int x, int y);

int max_value(int x, int y)
{
    return x>y ? x : y;
}

int main(int args, char * argv[])
{
    int (*p)(int, int) = NULL; //定义一个与maxValue兼容的指针
    p = max_value;

    int res = p(2,3);  // 两种调用方式均可以
    // int res = (*p)(2,3);  // 通过指针调用函数
    
    printf("res = %d\n", res);

    printf("%p-%p\n",p,*p);  // p和*p等价
    printf("%p,%p\n",max_value, &max_value);
    

    return 0;
}