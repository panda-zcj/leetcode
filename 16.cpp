/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\16.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-01
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-01-24
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */

/*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).

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
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int min=nums.at(0)+nums.at(1)+nums.at(2),sum;
        int len=nums.size();
        for(int i=0;i<len-2;i++){
            for(int m=i+1,n=len-1;m<n;){
                sum=nums.at(i)+nums.at(m)+nums.at(n);
                if(target == sum){
                    cout<<"result:"<<nums.at(i)<<" "<<nums.at(m)<<" "<<nums.at(n)<<endl;
                    return sum;
                }else if(target > sum){
                    m++;
                    min=abs(min-target)>abs(sum-target)?sum:min;
                    // cout<<"target > sum:"<<nums.at(i)<<" "<<nums.at(m)<<" "<<nums.at(n)<<endl;
                }else if(target < sum){
                    n--;
                    min=abs(min-target)>abs(sum-target)?sum:min;
                    // cout<<"target < sum"<<nums.at(i)<<" "<<nums.at(m)<<" "<<nums.at(n)<<endl;
                }
            }
        } 
        return min;
    }
};