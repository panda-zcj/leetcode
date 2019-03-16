/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\557.cpp
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

给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

示例 1:

输入: "Let's take LeetCode contest"
输出: "s'teL ekat edoCteeL tsetnoc" 
注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

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
    string reverseWords(string si) {
        string result;
        if(!si.size()){
            return result;
        }
        istringstream str(si);
        vector<string> strs((istream_iterator<string>(str)), istream_iterator<string>());//字符串流迭代器构造vector
        for(auto &s : strs) {
            cout << s << endl;
            reverse(s.begin(),s.end());
            result+=s+" ";
        }
        result.erase(result.size()-1);
        return  result;
    }
};