/**
 * 
 * Copyright (c) 2018 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\12.cpp
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
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

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
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

示例 1:

输入: 3
输出: "III"
示例 2:

输入: 4
输出: "IV"
示例 3:

输入: 9
输出: "IX"
示例 4:

输入: 58
输出: "LVIII"
解释: L = 50, V = 5, III = 3.
示例 5:

输入: 1994
输出: "MCMXCIV"
解释: M = 1000, CM = 900, XC = 90, IV = 4.
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
    string intToRoman(int num) {
        string num_str;
        for(;num>0;){
            if(num/1000){
                int i = num/1000;
                for(int j=0;j<i;j++){
                    num_str+="M";
                }
                num%=1000;
            }else if(num/100){
                int i = num/100;
                if(i<4){
                    for(int j=0;j<i;j++){
                        num_str+="C";
                    }
                }else if(i==4){
                    num_str+="CD";
                }else if(i==5){
                    num_str+="D";
                }else if(i>5&&i<9){
                    num_str+="D";
                    for(int j=5;j<i;j++){
                        num_str+="C";
                    }
                }else if(i==9){
                    num_str+="CM";
                }
                num%=100;
            }else if(num/10){
                int i = num/10;
                if(i<4){
                    for(int j=0;j<i;j++){
                        num_str+="X";
                    }
                }else if(i==4){
                    num_str+="XL";
                }else if(i==5){
                    num_str+="L";
                }else if(i>5&&i<9){
                    num_str+="L";
                    for(int j=5;j<i;j++){
                        num_str+="X";
                    }
                }else if(i==9){
                    num_str+="XC";
                }
                num%=10;
            }else if(num<10){
                int i=num;
                if(i<4){
                    for(int j=0;j<i;j++){
                        num_str+="I";
                    }
                }else if(i==4){
                    num_str+="IV";
                }else if(i==5){
                    num_str+="V";
                }else if(i>5&&i<9){
                    num_str+="V";
                    for(int j=5;j<i;j++){
                        num_str+="I";
                    }
                }else if(i==9){
                    num_str+="IX";
                }
                num=0;
            }
        }
        return num_str;
    }
};