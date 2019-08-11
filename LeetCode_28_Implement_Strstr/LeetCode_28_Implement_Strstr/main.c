//
//  main.c
//  LeetCode_28_Implement_Strstr
//
//  Created by 李小龙 on 2019/8/11.
//  Copyright © 2019 李小龙. All rights reserved.
//

#include <stdio.h>
/*
 实现 strStr() 函数。
 
 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
 
 示例 1:
 
 输入: haystack = "hello", needle = "ll"
 输出: 2
 示例 2:
 
 输入: haystack = "aaaaa", needle = "bba"
 输出: -1
 说明:
 
 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 
 */

int strStr(char * haystack, char * needle){
    int strLen, strstrLen;
    int i,j;
    if((haystack == NULL) || (needle == NULL))
    {
        return 0;
    }
    
    for(i = 0; haystack[i] != '\0'; i++);
    strLen = i;
    for(j = 0; needle[j] != '\0'; j++);
    strstrLen = j;
    j = 0;
    if(strstrLen == 0)
        return 0;
    if(strLen == 0)
        return -1;
    
    for(i = 0; i <= (strLen - strstrLen); i++)
    {
        j = 0;
        for(j = 0; j < strstrLen; j++)
        {
            if(haystack[i + j] != needle[j])
            {
                break;
            }
            else
            {
                if(j == (strstrLen - 1))
                    return i;
            }
        }
    }
    return -1;
    

}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
