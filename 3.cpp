/**
 * 
 * Copyright (c) 2018 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\3.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2018-12
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-06-09
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */

/*

给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
#include <set>
using namespace std;

#if 0
class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        int m[256] = { 0 }, res = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (m[s[i]] == 0 || m[s[i]] < left) {
                res = max(res, i - left + 1);
            }else {
                left = m[s[i]];
            }
            m[s[i]] = i + 1;
        }
        return res;
    }
};
#else 
class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        std::set<char> tmp;
        int i=0,j=0,max=0;
        for(;j<s.size();){
            if(!tmp.insert(s.at(j)).second){
                max=max>(j-i)?max:(j-i);
                tmp.erase(s.at(i++));
            }else{
                max=max>(j-i+1)?max:(j-i+1);
                j++;
            }
        }
        return max;
    }
};
#endif