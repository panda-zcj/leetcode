/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\96.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-06
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-06-16
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */

/*
给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？

示例:

输入: 3
输出: 5
解释:
给定 n = 3, 一共有 5 种不同结构的二叉搜索树:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/


/*
动态规划

假设n个节点存在二叉排序树的个数是G(n)，令f(i)为以i为根的二叉搜索树的个数

即有:G(n) = f(1) + f(2) + f(3) + f(4) + ... + f(n)

n为根节点，当i为根节点时，其左子树节点个数为[1,2,3,...,i-1]，右子树节点个数为[i+1,i+2,...n]，
所以当i为根节点时，其左子树节点个数为i-1个，右子树节点为n-i，即f(i) = G(i-1)*G(n-i),

上面两式可得:G(n) = G(0)*G(n-1)+G(1)*(n-2)+...+G(n-1)*G(0)
 */

#include <iostream>
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        int dp[n+1]={0};
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n ; i++)
            for(int j = 0; j < i ; j++) 
                dp[i] += dp[j] * dp[i-1-j];
        return dp[n];
    }
};