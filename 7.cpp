/**
 * 
 * Copyright (c) 2018 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\7.cpp
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
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321
 示例 2:

输入: -123
输出: -321
示例 3:

输入: 120
输出: 21
注意:

假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
*/
#include <iostream>
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int a=0,b=0,sum=0;
        while(x)
        {
            b=x%10;
            a=sum;
            sum=sum*10+b;
            if(sum/10!=a||sum%10!=b)
            {
                return 0;
            }
            x/=10;
        }
        return sum;   
    }
};