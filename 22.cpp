/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\22.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-06
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-06-29
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <map>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
/*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */
class Solution {
public:
    bool isOrder(string &str){
        int m=0;
        for(auto i : str){
            if(i=='('){
                m++;
            }else
            {
                m--;
            } 
            if(m<0) break;
        }
        return m==0?true:false;
    }
    vector<string> generateParenthesis(int n) {
        if(!n) return {};
        vector<string> parenthesis;
        string  str;//一个根解
        int deep=0, layerNumber=2*n-1, layer[layerNumber+1]={0};
        char element[2]={'(',')'};
        while (deep>=0)
        {
            if(layer[deep]<2){
                str.push_back(element[layer[deep]]);
                layer[deep]++;//下一次迭代的元素
                if(deep<layerNumber){
                    deep++;
                }else
                {
                    if(isOrder(str)){
                        parenthesis.push_back(str);
                    }
                    str.pop_back();
                }  
            }else
            {
                layer[deep]=0;//回到上一层
                deep--;
                if(str.size()){
                    str.pop_back();
                }
            }  
        } 
        return parenthesis; 
    }
};