/**
 * 
 * Copyright (c) 2018 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\15.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2018-12
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-12-29
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> all; 
        int size = nums.size(); 
        if(size>=3){  
            sort(nums.begin(),nums.end());
            int a,b,c,sum,i,j,k;
            for(i=0;i<size-2;i++){
                a=nums.at(i);
                if((i-1)>=0&&a==nums.at(i-1)){
                    continue;
                }
                for(j=i+1,k=size-1;j<k;){
                    b=nums.at(j);
                    c=nums.at(k);
                    sum=a+b+c;
                    if(sum==0){
                        all.push_back({a,b,c});
                        j++;
                        k=size-1;
                        while(nums.at(j)==nums.at(j-1)&&j<k){
                            j++;
                        }
                    }else if(sum>0) {
                        k--;
                    }else if(sum<0){
                        j++;
                    }
                }
            }
        }
        return all;
    }
};