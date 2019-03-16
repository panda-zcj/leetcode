/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\344.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-01
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-01-23
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
/*
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

*/
#include <sstream>
#include <iostream>
#include <algorithm> 
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len=s.size();
        if(!len){
            return;
        }else{
            char c;
            int times = len/2;
            len--;
            for(int i=0;i<times;i++){
                c=s.at(i);
                s.at(i)=s.at(len-i);
                s.at(len-i)=c;
            }
        } 
    }
};