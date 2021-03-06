/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\94.cpp
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
给定一个二叉树，返回它的中序 遍历。

示例:

输入: [1,null,2,3]

   1
    \
     2
    /
   3

输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

*/

#include <iostream>
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> vec;
    void  inOrder(TreeNode *node){
        if(node){
            inOrder(node->left);
            vec.push_back(node->val);
            inOrder(node->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inOrder(root);
        return vec;
    }
};