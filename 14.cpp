/**
 * 
 * Copyright (c) 2018 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\14.cpp
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
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1:

输入: ["flower","flow","flight"]
输出: "fl"
示例 2:

输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:

所有输入只包含小写字母 a-z 。
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
    string longestCommonPrefix(vector<string>& strs) {
        int num=strs.size();
        if(num<1){
            return "";
        }
        string common_str;
        int sum,j=-1;
        char c; 
        while(true){
            j++;
            sum=0;
            c=0xff;
            for(int i=0;i<num;i++){
                if(j<strs[i].size()){
                    sum+=strs[i].at(j);
                    c&=strs[i].at(j);
                }else{
                    return common_str;
                }
            }
            if((sum/num)==c&&(sum%num)==0)
            {
                common_str+=strs[0].at(j);
            }else{
                return common_str;
            }
        }
        return "";
    }
};