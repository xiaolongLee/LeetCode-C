//
//  main.c
//  LeetCode_20_Longest_ValidParentheses
//
//  Created by 李小龙 on 2019/7/14.
//  Copyright © 2019 李小龙. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*
 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 
 有效字符串需满足：
 
 左括号必须用相同类型的右括号闭合。
 左括号必须以正确的顺序闭合。
 注意空字符串可被认为是有效字符串。
 
 示例 1:
 
 输入: "()"
 输出: true
 示例 2:
 
 输入: "()[]{}"
 输出: true
 示例 3:
 
 输入: "(]"
 输出: false
 示例 4:
 
 输入: "([)]"
 输出: false
 示例 5:
 
 输入: "{[]}"
 输出: true
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/valid-parentheses
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
bool isVaild(char *s){
    struct ListNode{
        char sym;
        struct ListNode* next;
        struct ListNode* pre;
    };
    int i = 0;
    //首先创建头结点
    struct ListNode* head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->sym = '\0';
    head->next = NULL;
    head->pre = NULL;
    struct ListNode* curNode = head;
    //遍历字符串
    while(s[i] != '\0')
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            struct ListNode* p = (struct ListNode *)malloc(sizeof(struct ListNode));
            p->sym = s[i];
            p->next = NULL;
            p->pre = curNode;
            curNode ->next = p;
            curNode = p;
        }
        else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            switch(s[i]){
                case ')':
                    if(curNode->sym == '(')
                        break;
                    else
                        return false;
                case ']':
                    if(curNode->sym == '[')
                        break;
                    else
                        return false;
                case '}':
                    if(curNode->sym == '{')
                        break;
                    else
                        return false;
            }
            curNode = curNode->pre;
            free(curNode->next);
        }
        i++;
    }
    if(curNode->sym == '\0')
        return true;
    else
        return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
