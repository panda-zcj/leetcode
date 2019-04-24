/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\27.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-01
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-03-19
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
/*
给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1:

给定 nums = [3,2,2,3], val = 3,

函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,1,2,2,3,0,4,2], val = 2,

函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

注意这五个元素可为任意顺序。

你不需要考虑数组中超出新长度后面的元素。
说明:

为什么返回数值是整数，但输出的答案是数组呢?

请注意，输入数组是以“引用”方式传递的，这意味着在函数里修改输入数组对于调用者是可见的。

你可以想象内部操作如下:

// nums 是以“引用”方式传递的。也就是说，不对实参作任何拷贝
int len = removeElement(nums, val);

// 在函数里修改输入数组对于调用者是可见的。
// 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
for (int i = 0; i < len; i++) {
    print(nums[i]);
}
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <map>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length=nums.size();
        for(int i=0; i< length; ){
            if(nums.at(i)==val){
                nums[i]=nums[length-1];
                length--;
            }else
            {
                i++;
            }  
        }
        return  length;  
    }
};