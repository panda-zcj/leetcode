/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\43.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-02
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-02-19
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
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
    string multiply(string num1, string num2) {
        string product ;
        int n1=num1.size(), n2=num2.size();
        string::reverse_iterator iter1;
        string::reverse_iterator iter2;
        for(iter1 = num1.rbegin();iter1 != num1.rend(); iter1++){
            int carry=0;
            for(iter2 = num2.rbegin(); iter2 != num2.rend(); iter2++){
                char p = ((*iter1 - '0')*(*iter2 - '0') +carry)%10;
                carry =((*iter1 - '0')*(*iter2 - '0') +carry)/10;
                product.push_back(p);
            }
        }
        
    }
};