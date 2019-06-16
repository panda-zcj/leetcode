/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\235.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-04
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-04-26
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */

/**
 * 
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]

https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/12/14/binarysearchtree_improved.png

示例 1:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
输出: 6 
解释: 节点 2 和节点 8 的最近公共祖先是 6。
示例 2:

输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
输出: 2
解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 

说明:

所有节点的值都是唯一的。
p、q 为不同节点且均存在于给定的二叉搜索树中。
*/

#include <iostream>
#include <string>
#include <cmath>



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int min ,max;
        min=p->val<q->val?p->val:q->val;
        max=p->val>q->val?p->val:q->val;
        while (root)
        {
            if (root->val==min){
                return root;
            }else if(root->val<min){
                root=root->right;
            }else if(root->val==max){
                return root;
            }else if(root->val>max){
                root=root->left;
            }else{
                return root;
            }
        }
        return root;
    }
};

