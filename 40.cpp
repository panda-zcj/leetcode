/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\40.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-06
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-07-01
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */

/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明：

所有数字（包括目标数）都是正整数。
解集不能包含重复的组合。 
示例 1:

输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
示例 2:

输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
  [1,2,2],
  [5]
]
*/
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size()==0) return {};
        vector<vector<int>> vec;
        vector<int> root;
        int sum=0;
        int deep=0, layerNumber=candidates.size()-1, layer[layerNumber+1]={0};
        vector<vector<int>> element(layerNumber+1,{1,0});
        while(deep>=0){
            if(layer[deep] < 2){
                sum+=candidates.at(deep)*element.at(deep).at(layer[deep]);
                if(sum > target){
                    sum-=candidates.at(deep)*element.at(deep).at(layer[deep]);
                    layer[deep]++;
                }else
                {
                    root.push_back(candidates.at(deep)*element.at(deep).at(layer[deep]));
                    layer[deep]++;
                    if(deep < layerNumber){
                        deep++;
                    }else{
                        if(sum == target){
                            vector<int> r;
                            bool ok=true;
                            for(auto i: root){
                                if(i!=0){
                                    r.push_back(i);
                                }
                            }
                            sort(r.begin(), r.end());
                            for(auto i:vec){
                                if(i==r){
                                    ok=false;
                                    break;
                                }
                            }
                            if(ok){
                                vec.push_back(r);
                            }
                        }
                        sum-=root.back();
                        root.pop_back();
                    }
                }
            }else{
                if(root.size()){
                    sum-=root.back();
                    root.pop_back();
                }
                layer[deep]=0;
                deep--;
            }
        }
        return vec;
    }
};
