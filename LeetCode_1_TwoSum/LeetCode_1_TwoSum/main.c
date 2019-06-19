//
//  main.c
//  LeetCode_1_TwoSum
//
//  Created by 李小龙 on 2019/6/9.
//  Copyright © 2019 李小龙. All rights reserved.
//

#include <stdio.h>

/*
 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 
 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
 
 示例:
 
 给定 nums = [2, 7, 11, 15], target = 9
 
 因为 nums[0] + nums[1] = 2 + 7 = 9
 所以返回 [0, 1]
 
 
 */


int* twoSum(int* nums, int numsSize, int target){
    static int a[2] = {0};
    
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (a[i] + a[j] == target) {
                a[0] = i;
                a[j] = j;
                return a;
            }
        }
    }
    
    
    return 0;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int nums = {2, 7, 11, 15};
    int  numsize = 4;
    int target = 9;
    
    int a[2];
    
    
    twoSum(&nums , 4 , 9);
    
    
    return 0;
}

