//
//  main.c
//  LeetCode_14_Longest-Common-Prefix
//
//  Created by 李小龙 on 2019/7/7.
//  Copyright © 2019 李小龙. All rights reserved.
//

/*
 
 编写一个函数来查找字符串数组中的最长公共前缀。
 
 如果不存在公共前缀，返回空字符串 ""。
 
 示例 1:
 
 输入: ["flower","flow","flight"]
 输出: "fl"
 示例 2:
 
 输入: ["dog","racecar","car"]
 输出: ""
 解释: 输入不存在公共前缀。
 说明:
 
 所有输入只包含小写字母 a-z 。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-common-prefix
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

#include <stdio.h>
#include <string.h>
char * longestCommonPrefix(char ** strs, int strsSize){
    /*
     * 思路：
     * 先比较第一和第二个，如果有公共的前缀，则用前缀和第三个比较
     * 如果没有公共前缀，就直接返回，后面的不需要比较
     */
    
    char * temp = (char *)malloc(128); //用来存储公共前缀
    /*
     void *memset(void *s, int ch, size_t n);
     函数解释：将s中当前位置后面的n个字节 （typedef unsigned int size_t ）用 ch 替换并返回 s 。
     memset：作用是在一段内存块中填充某个给定的值，它是对较大的结构体或数组进行清零操作的一种最快方法 [1]  。
     memset()函数原型是extern void *memset(void *buffer, int c, int count) buffer：为指针或是数组,c：是赋给buffer的值,count：是buffer的长度.
     */
    memset(temp, 0, 128);
    if (strsSize == 0) {
        return "";
    }
    /*
     strcpy，即string copy（字符串复制）的缩写。
     strcpy是一种C语言的标准库函数，strcpy把含有'\0'结束符的字符串复制到另一个地址空间，返回值的类型为char*。
     */
    strcpy(temp, strs[0]);
    int count = strlen(temp);////用来计数，公共前缀字符数为0时，则没有
    
    for (int i = 0; i < strsSize; i++) {
        char * currentStr = strs[i];
        
        if (count == 0) {
            return "";
        }
        
        int j;
        for (j = 0; j < count; j++) {
            if (temp[j] != currentStr[j]) {
                break;
            }
        }
        
        count = j;
        temp[j] = 0;
    }
    
    return temp;
    
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
