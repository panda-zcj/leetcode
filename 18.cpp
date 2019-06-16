/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\18.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-06
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-06-09
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> all; 
        int size = nums.size(); 
        if(size>=4){  
            sort(nums.begin(),nums.end());
            int a,b,c,d,sum;
            for(int i=0; i< size-3 ;i++){
                a=nums.at(i);
                if(i>0 && a==nums.at(i-1)){
                    continue;
                }
                for(int j=i+1; j < size-2 ;j++){
                    b=nums.at(j);
                    if(j-1 >i && b==nums.at(j-1)){
                        continue;
                    }
                    for(int k=j+1,l=size-1 ; k < l ; ){
                        c=nums.at(k);
                        d=nums.at(l);
                        sum=a+b+c+d;
                        if(sum == target){
                            all.push_back({a,b,c,d});
                            k++;
                            l=size-1;
                            while(nums.at(k)==nums.at(k-1) && k<l){
                                k++;
                            }
                        }else if(sum>target) {
                            l--;
                        }else if(sum<target){
                            k++;
                        }
                    }
                }
            }
        }
        return all;
    }
};
