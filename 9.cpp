/**
 * 
 * Copyright (c) 2018 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\9.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2018-12
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-12-28
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
*/

#include <iostream>
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        } 
        int sx,sum=0;
        sx=x;
        for(;;){
            sum=sum*10+x%10;
            x=x/10;
            if(x==0){
                break;
            }
        }
        if(sum!=sx){
            return false;
        }
        return true;
    }
};