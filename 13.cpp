/**
 * 
 * Copyright (c) 2018 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\13.cpp
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
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:

输入: "III"
输出: 3
示例 2:

输入: "IV"
输出: 4
示例 3:

输入: "IX"
输出: 9
示例 4:

输入: "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
*/

#include <iostream>
#include <vector>
#include <hash_map>
#include <map>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int size =s.size();
        if(size==0){
            return 0;
        }
        int num=0;
        for(int i =size -1;i>=0;i--){
            char c = s.at(i);
            if(c=='I'){
                num+=1;
            }else if(c=='V'){
                if((i-1)>=0 && s.at(i-1)=='I'){
                    num+=4;
                    i--;
                }else{
                    num+=5;
                }
            }else if(c=='X'){
                if((i-1)>=0&&s.at(i-1)=='I'){
                    num+=9;
                    i--;
                }else{
                    num+=10;
                }
            }else if(c=='L'){
                if((i-1)>=0&&s.at(i-1)=='X'){
                    num+=40;
                    i--;
                }else{
                    num+=50;
                }
            }else if(c=='C'){
                if((i-1)>=0&&s.at(i-1)=='X'){
                    num+=90;
                    i--;
                }else{
                    num+=100;
                }
            }else if(c=='D'){
                if((i-1)>=0&&s.at(i-1)=='C'){
                    num+=400;
                    i--;
                }else{
                    num+=500;
                }
            }else if(c=='M'){
                if((i-1)>=0&&s.at(i-1)=='C'){
                    num+=900;
                    i--;
                }else{
                    num+=1000;
                }
            }
        }
        return num;
    }
};