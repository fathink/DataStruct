/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~x&~y)&~(x&y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {

  return 1 << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // TMax+1=100000...,
  // ~(TMax+1)=01111...., 
  // ~(TMax+1)^TMax=0，最后取反即可
  // 另一种情况是1111....,此时!!(x+1)=0,过滤掉该情况
  return !(~(x+1)^(x)) & (!!(x+1));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    // 核心是 x^x=0,首先要构造0xAAAAAAAA
    //
    int a=0xAA<<8; //0xAA00
    int b=a|0xAA; //0xAAAA
    int c=b<<16|b; //0xAAAAAAAA
    
  return !( (x&(c)) ^ (c));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    //取反加1
  return ~x+1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    // 高4为为3，低四位为0～9, 低四位与-10相加，判断是否小于0
    int a=!(x>>4^3); // 判断高四位是否为3

    int b=x&0xF; //获取低四位
    int c=~0xA+1 ; //获取-10
    int d=!!((b+c)&(0x1<<31));  //如果是负数，高位一定是1,两次取非

  return a&d;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    // return y if x !=  0 else return z
    int a=!!(x^0x0); // a=0 if x==0 else 1
    int b=~a+1; //0000...,1111....
    int c=~(y&~b)+1;
    int d=~(z&b)+1;
   

  return y+z+c+d;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int a=(x>>31)&0x1; //x符号位
    int b=(y>>31)&0x1; //y符号位
    int c1=(a&~b); //x正y负，返回0
    int c2=(~a&b); //x负y正，返回1

    int e=y+(~x+1); // 计算y-x
    int flag=e>>31; //如果falg和c2不同，说明溢出
    

  return c1 | (!c2&!flag);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    // if x!=0 return 0
    //x为正，(~x+1)>>31为1
    //x为负，(~x+1)>>31为0，将(~x+1)与x做与运算，然后使用算术右移，变成1111...，最后加1，返回0
  return ((x|(~x+1))>>31)+1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    //找到正数最左边的1所在的位置，再加上1位符号位（负数的话先转为正数）
    int b16,b8,b4,b2,b1,b0;
    int flag=x>>31; //记录符号
    x=(flag&~x)|(~flag&x); // x是负数，按位取反，x是正数，不做处理

    b16=!!(x>>16)<<4; //如果x高16为不为零，则让b16=16，否则b16=0
    x=x>>b16; //继续看高16位的情况

    //进行拆分
    b8=!!(x>>8)<<3; //处理高8位
    x=x>>b8;

    b4=!!(x>>4)<<2; //处理高4位
    x=x>>b4;

    b2=!!(x>>2)<<1; //处理高2位
    x=x>>b2;

    b1=!!(x>>1); //倒数第2位
    x=x>>b1;

    b0=x; //最后一位


  return b16+b8+b4+b2+b1+b0+1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    //32位单精度浮点数，31位符号位，31-23位阶码,23-0尾数

    unsigned exp=(uf&0x7f800000)>>23; //获取阶码
    unsigned sign=uf>>31&0x1; //获取符号位
    unsigned frac=uf&0x7fffff;

    unsigned res;

    if (exp==0xff) return uf; //如果是NaN，直接返回uf

    //非规格化数
    if (exp==0){
        frac<<=1;
        res=(sign<<31)|(exp<<23)|frac;
    }
    else{
        exp++;
        res=(sign<<31)|(exp<<23)|frac;
    }

  return res;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    int exp=(uf&0x7f800000)>>23; //获取阶码
    int sign=uf>>31&0x1; //获取符号位
    int frac=uf&0x7fffff; //获取尾数

    int E=exp-127;

    // 小于0的小数，直接返回0
    if (E<0) return 0;
   
    // NaN，直接返回0x80000000，超过整数范围同样返回0x8000...
    if (E>=31) return 0x80000000;

    //给尾数补充上省略的1
    frac=frac|(1<<23);
    
    //判断E和23的大小，23是尾数长度
    if(E<23){
        frac=frac>>(23-E);
    }
    else{
        frac=frac<<(E-23);
    }
    
    int res;
    if(sign){
        res=-frac;
    }
    else{
        res=frac;
    }

  return res;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    
    //超过极大值，返回NaN
    if (x>127) return 0xFF<<23;

    //超过极小值，返回0
    if (x<-148) return 0;

    //规格化数
    if (x>=-126)
    {
        int exp = x + 127; // 32位浮点数的偏置为127,所以这里要加上127
        return exp << 23; 

    }
    else  //非规格化数
    {
        int t = 148 + x; // 22-(1-127-x)=148+x,非规格化数，考虑尾数实现幂函数
        return 1 << t;
    }
    
}
