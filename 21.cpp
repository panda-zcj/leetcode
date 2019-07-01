/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\21.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-06
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-06-20
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <map>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

/*
将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例：

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4

*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        int list1,list2;
        ListNode list(0),*tmp=&list;
        while (l1 || l2)
        {
            list1=l1?l1->val:INT_MAX;
            list2=l2?l2->val:INT_MAX;
            if(list1>list2){
                tmp->next=l2;
                tmp=tmp->next;
                l2=l2->next;
            }else
            {
                tmp->next=l1; 
                tmp=tmp->next;
                l1=l1->next;
            } 
        } 
        return list.next; 
    }
};