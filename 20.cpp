/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\20.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-06
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-06-09
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
/*

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true
示例 2:

输入: "()[]{}"
输出: true
示例 3:

输入: "(]"
输出: false
示例 4:

输入: "([)]"
输出: false
示例 5:

输入: "{[]}"
输出: true

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
#include <set>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> ss;
        for(auto i:s) {//c++11
            if (i=='{' || i=='('|| i=='[') {
                ss.push(i);
            }else {
                if (ss.size() == 0 && (i == ']' || i == '}' || i == ')')) {
                    return false;
                }else if ((i == '}' && ss.top() != '{') || (i == ']' && ss.top() != '[') || (i == ')' && ss.top() != '(') ){
                    return false;
                }
                else{
                    ss.pop();
                }
            }
        }
        if (ss.size() != 0 ) {
            return false; 
        }
        return true;
    }
};