/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\46.cpp
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
给定一个没有重复数字的序列，返回其所有可能的全排列。

示例:

输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
#include <sstream>
#include <iostream>
#include <algorithm> 
#include <vector>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()<1) return {};
        vector<vector<int>> vec;
        vector<int> root; //一个根解
        int deep=0, layerNumber=nums.size()-1 , layer[layerNumber+1]={0};
        vector<int> element(nums);  //每层迭代的元素
        while(deep>=0){
            if(layer[deep] < element.size()){
                root.push_back(element.front());
                element.erase(element.begin());
                layer[deep]++;
                if(deep < layerNumber){
                    deep++; //进入下一层
                }else
                {
                    //得到结果
                    vec.push_back(root);
                    element.push_back(root.back());//迭代该层下一个元素
                    root.pop_back();
                }
            }else
            {
                //回到上一层
                layer[deep]=0;
                deep--; 
                if(root.size())     //清除上一层元素
                {
                    element.push_back(root.back());
                    root.pop_back();
                }
            }
        }
        return vec;
    }
};
int main(int argc ,char** argv){
    Solution s;
    vector<int> tmp;
    int sum;
    if(argc < 2){
        sum=2;
    }else
    {
        sum=atoi(argv[1]);
    }
    
    for (int i=0; i <sum ;i++)
    {
        tmp.push_back(i+1);
    }
    vector<vector<int>> vec= s.permute(tmp);
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec.at(i).size();j++)
            cout<<vec.at(i).at(j)<<"  ";
        cout<<"\n";
    }
    return 0;
}
