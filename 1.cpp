/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\1.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-06
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-06-04
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */


/*

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]

*/
#include <iterator>
#include <iostream>
#include <vector>
#include <map>
#include <iterator>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,int> num;
        std::map<int,int>::iterator iter;
        for(int i=0;i<nums.size();i++){
            iter=num.find(target-nums.at(i));
            if(iter!=num.end()){
                std::vector<int> a;
                a.push_back(iter->second);
                a.push_back(i);
                return a;
            }else{
                num.insert(std::make_pair(nums.at(i),i));
            }
        }
        return std::vector<int>();
    }
};