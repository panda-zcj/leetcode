/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\100.cpp
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
二叉树算法的设计的总路线：明确一个节点要做的事情，然后剩下的事抛给框架。

void traverse(TreeNode root) {
    // root 需要做什么？在这做。
    // 其他的不用 root 操心，抛给框架
    traverse(root.left);
    traverse(root.right);
}
举两个简单的例子体会一下这个思路，热热身。

1. 如何把二叉树所有的节点中的值加一？

void plusOne(TreeNode root) {
    if (root == null) return;
    root.val += 1;

    plusOne(root.left);
    plusOne(root.right);
}
2. 如何判断两棵二叉树是否完全相同？

boolean isSameTree(TreeNode root1, TreeNode root2) {
    // 都为空的话，显然相同
    if (root1 == null && root2 == null) return true;
    // 一个为空，一个非空，显然不同
    if (root1 == null || root2 == null) return false;
    // 两个都非空，但 val 不一样也不行
    if (root1.val != root2.val) return false;

    // root1 和 root2 该比的都比完了
    return isSameTree(root1.left, root2.left)
        && isSameTree(root1.right, root2.right);
}

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL )  return true ;
        if(p==NULL || q==NULL )  return false;
        if(p->val  != q->val  )  return false;
        return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right); 
    }
};