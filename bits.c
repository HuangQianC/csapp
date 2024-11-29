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
 * bitXor - 只使用~和&实现异或运算(x^y)，异或：相同为0，不同为1；
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(~x & ~y) & ~(x & y);
}
/* 
 * tmin - 返回补码意义下的32位最小值。
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1<<31;
}
//2
/*
 * isTmax - 检测一个值是不是补码意义下的最大值。
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 * 思路：
 * 补码意义下的最大值就是除了最高位为0其余位都为1的数。
 * 观察到这个值加一(x+1)和这个值取反(~x)是同一个值，可以用异或来判：(x+1)^(~x)=0
 * 当然二进制全1的值也满足这个性质，特别判断一下~x是不是0即可。
 */
int isTmax(int x) {
  return !(((~x)^(x+1)) | !(~x)); 
}
/* 
 * allOddBits - 如果字中的所有奇数位均设置为1，则返回1。其中位数从0（最低有效位）编号到31（最高有效位）
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 * 思路：
 * 在Writeup中规定了，不允许使用超过8位的常量，所以只能是常量的范围0-255。
 * 只是判断所有的奇数位为1、偶数位为0，返回真。
 */
int allOddBits(int x) {
  // unsigned mask = 0xAA + (0xAA << 8); // 10101010 10101010
  // mask = (mask << 16) + mask;
  // return !((x & mask) ^ mask);
  return !((x & (x>>8) & (x>>16) & (x>>24) & 0xAA) ^ 0xAA);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x) + 1;
}
//3
/* isAsciiDigit - 判断x是否满足 0x30 <= x <= 0x39，即ASCII编码中'0'-'9'的编码
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 * 思路：
 * 0x30：00110000，0x39：00111001
 * 高四位：0011
 * 低四位：可以分为0xxx和100x；
 */
// int isAsciiDigit(int x) {
//   // 检查高四位是否为0011
//   int highFourBits = (x>>4) & 0xF;
//   int isCorrectHighBits = !(highFourBits ^ 3);

//   // 检查低四位是否为0xxx或100x（其中x为0或1，但100x中只有1000和1001是有效的）
//   int lowFourBits = (!((x>>3)&1)) | ( (!((x>>1)&1)) & (!((x>>2)&1)) );

//   return isCorrectHighBits & lowFourBits;
// }
int isAsciiDigit(int x) {
  return (!((x>>4)^3))&((!((x>>3)&1))|(!((x>>1)&1)&(!((x>>2)&1))));
}
/* 
 * conditional - 用位运算实现 x ? y : z
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 * 思路：
 * 判断x是否为0, !x要么为0要么为1;
 * 然后求其nagate，因为-(1)的补码 全1， -(0）的补码为全0
 */
int conditional(int x, int y, int z) {
  int flag = ~(!!(x)) + 1;
  return (flag & y) | (~flag & z);
}
/* 
 * isLessOrEqual - 判断 x <= y
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 * 思路：
 * 判断y-x是否为非负数。即y-x的最高位是否为0。
 * y-x=y+(~x)+1，-x的补码表示(~x)+1。
 */
int isLessOrEqual(int x, int y) {
  return !((y+((~x)+1))>>31);
}

//4
/* 
 * logicalNeg - 实现逻辑!的功能，不允许用!
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 * 思路：
 * 0则返回1，否则返回0;
 * 当x=TMin时，-x=TMin，所以只有0和最小数的补码为本身，其余数为其相反数。
 * 且 最小数的符号位为1，0的符号位为0，并且最小数右移31为-1（算术右移）;
 */
int logicalNeg(int x) {
  return ((x | (~x + 1)) >> 31) + 1;
}
/* 
 * howManyBits - 判断一个数最少需要多少位的补码才能表示
 * howManyBits - return the minimum number of bits required to represent x in
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
 * 思路：
 * 比如：howManyBits(12) = 5，最少的补码为[01100]；
 *      howManyBits(298) = 10，最少的补码为[100101010]；
 * 2分查找不断细分，用x值的>>bit来代替if的思想。
 */
int howManyBits(int x) {
  //如果是负数就让其为 ~x，这样负数和正数操作就统一了；
  x = conditional(x & 0x80000000, ~x, x); 
  // 判断高16位是否有1；如果有1，就为真，则乘以16(<<4)，bit16=16；
  int bit16 = ((!!(x >> 16)) << 4);  
  x = x >> bit16;  // 如果有，低16位则丢弃

  int bit8 = ((!!(x >> 8)) << 3);
  x = x >> bit8;

  int bit4 = ((!!(x >> 4)) << 2);
  x = x >> bit4;

  int bit2 = ((!!(x >> 2)) << 1);
  x = x >> bit2;

  int bit1 = ((!!(x >> 1)) << 0);
  x = x >> bit1;

  int bit0 = (!!(x));
  return bit16 + bit8 + bit4 + bit2 + bit1 + bit0 + 1;
}
//float
/* 
 * floatScale2 - 该函数接收一个表示为无符号整型的单精度浮点数，
 *   然后返回这个浮点数的两倍（也表示为无符号整型）。如果输入是
 *   NaN，则直接返回输入值。
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 * 思路：
 * 拆分这个出s、exp、frac。
 * 在单精度浮点格式中，s、exp 和 frac 字段分别为 1 位、k=8 位和 n=23 位。
 * V = (-1)^s * M * 2^E;
 * 规格化的值：M = 1 + f，E = e - Bias，Bias = 2^(k-1) - 1 = 127；
 * 非规格化的值：M = f，E = 1 - Bias = -126；
 * 特殊值：阶码域全为1，如果小数域全为0，得到的值表示无穷，根据s得到+∞或者-∞；
 *                    如果小数域为非0，结果值被称为NaN。
 */
unsigned floatScale2(unsigned uf) {
  unsigned s = uf & (1 << 31);
  unsigned exp = (uf & 0x7f800000) >> 23;
  unsigned frac = uf & (~0xff800000);

  // 对于非规格化的值，M乘以2即可，| s 保证符号相同。
  if(exp == 0) return frac << 1 | s;

  // 对于特殊值，也就是无穷或者NaN。
  if(exp == 255) return uf;

  // 对于规格化的值.
  exp++;
  if(exp == 255) return 0x7f800000 | s; // 如果乘以2之后阶码域全为1，则返回无穷；
  return s | (exp << 23) | frac;
}
/* 
 * floatFloat2Int - 该函数接收一个表示为无符号整型的单精度浮点数，并将其转换为整数（也表示为无符号整型）。
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
 * 思路：
 * 整数的低位 等于 浮点表示的小数部分的高位；
 * 比如：12345 与 12345.0
 * 00000000000000000011000000111001  ==> 12345
 *                   **************
 *          010001100110000001110010000000000  ==> 12345.0
 */
int floatFloat2Int(unsigned uf) {
  unsigned s = uf & (1 << 31);
  unsigned exp = (uf & 0x7f800000) >> 23;
  unsigned frac = uf & (~0xff800000);

  int E = exp - 127;
  if (exp == 255 || E > 31) return 0x80000000u; // 题目要求

  // 小于0为 小数，可以舍入为 0
  if (E < 0) return 0;

  unsigned M = frac | (1 << 23);  // M = 1 + frac
  int V = (E > 23 ? M << (E - 23) : M >> (23 - E));
  if (s) V *= -1;  // 负数
  return V;
}
/* floatPower2 - 给出2的x次方的浮点数的二进制表示(unsigned类型)
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
 * 思路：
 * E = e - 127
 * V = 1*2^E
 * 指数范围是 -126 ~ 127 
 * 根据浮点数表示，x就是指数表示
 */
unsigned floatPower2(int x) {
  int exp = x + 127;
  unsigned ans;
  if(exp > 254)
    ans = 0xFF << 23;
  else if(exp < 1)
    ans = 0;
  else
    ans = exp << 23;
  return ans;
}
