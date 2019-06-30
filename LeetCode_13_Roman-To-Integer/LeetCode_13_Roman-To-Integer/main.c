//
//  main.c
//  LeetCode_13_Roman-To-Integer
//
//  Created by 李小龙 on 2019/6/30.
//  Copyright © 2019 李小龙. All rights reserved.

/*
 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
 
 字符          数值
 I             1
 V             5
 X             10
 L             50
 C             100
 D             500
 M             1000
 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。
 
 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 
 I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
 C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 
 示例 1:
 
 输入: "III"
 输出: 3
 示例 2:
 
 输入: "IV"
 输出: 4
 示例 3:
 
 输入: "IX"
 输出: 9
 示例 4:
 
 输入: "LVIII"
 输出: 58
 解释: L = 50, V= 5, III = 3.
 示例 5:
 
 输入: "MCMXCIV"
 输出: 1994
 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/roman-to-integer
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */



//
#define nI 1  //直接用define I 1，好像会有歧义
#define nV 5
#define nX 10
#define nL 50
#define nC 100
#define nD 500
#define nM 1000
#include <stdio.h>


int romanToInt(char * s){
    int num = 0, flag = 0;   /*立一个flag，是因为之前我在后面会用三个if，一个else，其实我的初衷是三个if有其中任何一个满足都不要再执行else了
                              但是如果没有flag的话，意思是第三个if如果不成立便会跳去else，比如IV，第一个if满足，然后第三个if不满足，else这时候
                              就会出来执行，很不爽*/
    while(*s != NULL)
    {
        if(*s == 'I' && (*(s + 1) == 'V' || *(s + 1) == 'X'))     //接下来的这三个if都有特殊含义，所以flag=1，普通情况属于flag=0
        {
            flag = 1;
            switch(*(s + 1))
            {
                case 'V':num += (nV - nI); s+=2; break;
                case 'X':num += (nX - nI); s+=2; break;
            }
        }
        if(*s == 'X' && (*(s + 1) == 'L' || *(s + 1) == 'C'))
        {
            flag = 1;
            switch(*(s + 1))
            {
                case 'L':num += (nL - nX); s+=2; break;
                case 'C':num += (nC - nX); s+=2; break;
            }
        }
        if(*s == 'C' && (*(s + 1) == 'D' || *(s + 1) == 'M'))
        {
            flag = 1;
            switch(*(s + 1))
            {
                case 'D':num += (nD - nC); s+=2; break;
                case 'M':num += (nM - nC); s+=2; break;
            }
        }
        if(flag == 0)   //本来这里是else的，改为if(flag == 0)
        {
            switch(*s)
            {
                case 'I':num += nI; s += 1; break;
                case 'V':num += nV; s += 1; break;
                case 'X':num += nX; s += 1; break;
                case 'L':num += nL; s += 1; break;
                case 'C':num += nC; s += 1; break;
                case 'D':num += nD; s += 1; break;
                case 'M':num += nM; s += 1; break;
            }
        }
        flag = 0;  //最后置回普通状态
    }
    return num;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
