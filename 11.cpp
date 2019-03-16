/**
 * 
 * Copyright (c) 2018 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\11.cpp
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
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。
示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/

#include <iostream>
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int max_area=0 , length;
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                length=height.at(j)>height.at(i)?height.at(i):height.at(j);
                max_area=(j-i)*length>max_area?(j-i)*length:max_area;
            }
        }
        return max_area;
    }
};