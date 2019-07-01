/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\95.cpp
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

给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

示例:

输入: 3
输出:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
解释:
以上的输出对应以下 5 种不同结构的二叉搜索树：

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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

/*
    思路：比如3，那我们就可以分别让1，2，3作为根节点，并以这个根节点作为分界线，在它左边的数就是它的左子树对应的节点集；
    在它右边的就是它的右子树对应的节点集。就会产生如下情况：
    ①root.val = 1：左子树集{}，右子树集{2，3}
    ②root.val = 2：左子树集{1}，右子树集{3}
    ③root.val = 3：左子树集{1，2}，右子树集{}
    然后你会观察到，为null的和只有一个元素的其实已经可以和root节点建立联系了，但是超过2个元素的集合还是需要去选择的。

    所以我们可以把2个以上元素的再进行类似这样的划分：
    把①中右子树集{2，3}：我们可以
    让2为root,那么root的左子树集{}，右子树集{3}
    让3为root，那么root的左子树集{2}，右子树{}
    把③中左子树集{1，2}我们可以
    让1为root,那么root的左子树集{}，右子树集{2}
    让2为root,那么root的左子树集{1}，右子树集{}

    这个时候所有的集合都被化为{}或者{一个元素}的情况了。
    然后我们还可以吧{一个元素}这种集合也分解掉，这样就可以让结束程序的地方更加简洁，{一个元素}这种情况很好分解，
    直接让它当root然后左子树集{}，右子树集也为{}。这样结束的条件就变成{}这种情况了。

 */

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {/*输出为root值集合 */
        if (n == 0) return {};
        return *generateTreesDFS(1, n);
    }
    vector<TreeNode*> *generateTreesDFS(int start, int end) {
        vector<TreeNode*> *subTree = new vector<TreeNode*>();
        if (start > end) subTree->push_back(NULL);
        else {
            for (int i = start; i <= end; ++i) {
                vector<TreeNode*> *leftSubTree  = generateTreesDFS(start, i - 1);
                vector<TreeNode*> *rightSubTree = generateTreesDFS(i + 1, end);
                for (int j = 0; j < leftSubTree->size(); ++j) {
                    for (int k = 0; k < rightSubTree->size(); ++k) {
                        TreeNode *node = new TreeNode(i);
                        node->left  = leftSubTree->at(j);
                        node->right = rightSubTree->at(k);
                        subTree->push_back(node);
                    }
                }
            }
        }
        return subTree;
    }
};