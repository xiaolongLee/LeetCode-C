//
//  main.c
//  LeetCode_7_Reverse-Integer
//
//  Created by 李小龙 on 2019/6/16.
//  Copyright © 2019 李小龙. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

/*
 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 
 示例 1:
 
 输入: 123
 输出: 321
  示例 2:
 
 输入: -123
 输出: -321
 示例 3:
 
 输入: 120
 输出: 21
 注意:
 
 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
 
 */


int reverse(int x) {
    int quotient,remainder;
    long long result;
    quotient = x / 10;
    remainder = x % 10;
    result = remainder;
    int min = 0x80000000;
    int max = 0x7fffffff;
    while (quotient) {
        remainder = quotient % 10;
        quotient = quotient / 10;
        result = result * 10 + remainder;
        
    }
    
    if (result > max || result < min) {
        return 0;
    }
    
    return result;
    
    
}
