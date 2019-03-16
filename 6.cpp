/**
 * 
 * Copyright (c) 2018 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\6.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2018-12
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-12-27
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */

/*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
*/
#include <iostream>
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string row[numRows],sum;
        if(numRows==1){
            return s;
        }
        int i=0,j=0;
        int n=-1,m=-1;
        int size = s.size();
        while(i<size){
            n*=(-1); 
            for(;j<numRows;j++){
                m+=n;
                row[m].push_back(s.at(i++));
                if(i>=size)
                {
                    break;
                }
            }
            j=1;
        }
        sum.resize(0);
        for(j=0;j<numRows;j++){
            sum+=row[j];
        }
        return sum;
    }
};