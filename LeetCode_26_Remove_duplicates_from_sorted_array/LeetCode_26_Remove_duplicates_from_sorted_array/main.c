//
//  main.c
//  LeetCode_26_Remove_duplicates_from_sorted_array
//
//  Created by 李小龙 on 2019/7/28.
//  Copyright © 2019 李小龙. All rights reserved.
//
// 26. 删除排序数组中的重复项
/*
 
 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 
 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 
 示例 1:
 
 给定数组 nums = [1,1,2],
 
 函数应该返回新的长度 2, 并且原数组 nums 的前两个元素被修改为 1, 2。
 
 你不需要考虑数组中超出新长度后面的元素。
 示例 2:
 
 给定 nums = [0,0,1,1,1,2,2,3,3,4],
 
 函数应该返回新的长度 5, 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4。
 
 你不需要考虑数组中超出新长度后面的元素。
 说明:
 
 为什么返回数值是整数，但输出的答案是数组呢?
 
 请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。
 
 你可以想象内部操作如下:
 
 // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
 int len = removeDuplicates(nums);
 
 // 在函数里修改输入数组对于调用者是可见的。
 // 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
 for (int i = 0; i < len; i++) {
     print(nums[i]);
 }
 
 
 */


/*
 前后元素进行对比
 1.定义一个基准元素p,初始化赋值为表中的第一个元素。
 
 2.增加一个计数器k，初始化值为1，用于计算表中互不相同的元素个数。
 
 3.遍历整个表，依次把后面元素与基准元素p进行对比：例如把表中nums[1]和基准值p(nums[0])对比，如果两个元素相同，只有i进行累加，此时k值不变，基准值p也不变，程序上可以不做处理。如果两个结点值不相同，按照新的位序排列表中元素nums[k]=nums[i],基准元素重新赋值为当前的元素，计数器k+1。最终返回新的表长，值为k，完成算法。
 
 */
#include <stdio.h>
#include <stdbool.h>
int removeDuplicates(int *nums,int numsSize){
    if (numsSize==0) return false;
    //加入计数器，计算表中互不相同的元素个数
    int k=1;
    int p=nums[0];
    //nums[i]为当前元素的结点
    for (int i=1;i<numsSize;i++){
        if (nums[i]!=p){
            nums[k]=nums[i];
            p=nums[i];
            k++;
        }
    }
    return k;   //返回表长
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
