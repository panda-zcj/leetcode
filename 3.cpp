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
 * Last Modified:  2018-12-26
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
using namespace std;

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
