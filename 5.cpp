/**
 * @file 4.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-06-09
 * 
 * @copyright Copyright (c) 2019
 * 
 */
/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
using namespace std;

class Solution {
    public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();) {
            if (s.size() - i <= max_len / 2) break;
            int j = i, k = i;
            while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
            i = k+1;
            while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
            int new_len = k - j + 1;
            if (new_len > max_len) { min_start = j; max_len = new_len; }
        }
        return s.substr(min_start, max_len);
    }
};
