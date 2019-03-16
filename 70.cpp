/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\70.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-02
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-02-19
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
*/

#include <iostream>
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
            return 1;
        else if (n == 2)
            return 2;
        else {
            int *ans =new int[n];
            ans[0] = 1;
            ans[1] = 2;
            for(int i=2 ; i < n; i++ ) {
                ans[i]=ans[i-1]+ans[i-2];
            }
            return ans[n-1];
        }
    }
};