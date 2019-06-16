/**

 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\19.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-06
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-06-09
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
/*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。

进阶：

你能尝试使用一趟扫描实现吗？

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
#include <set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
#if 0
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<ListNode*> vec;
        while (head)
        {
            vec.push_back(head);
            head=head->next;
        }
        if(vec.size()>n){
            if(n>1){
                vec.at(vec.size()-n-1)->next=vec.at(vec.size()-n+1);
            }else if(n==1){
                vec.at(vec.size()-n-1)->next=NULL;
            }
        }else if(vec.size()==n) {
             if(n>1){
               return vec.at(1);
            }else if(n==1){
               return NULL;
            }
        }
        return vec.at(0);
    }
};
#else
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head;
        ListNode *q = head;

        for (int i = 0; i < n; ++i) {
            p = p->next;
        }
        if (p) {
            while (p->next) {
                q = q->next;
                p = p->next;
            }
            q->next = q->next->next;
        }
        else {
            return head->next;
        }
        return head;
    }
};
#endif
