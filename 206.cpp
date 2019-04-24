/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\206.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-03
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-03-16
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */

/*
反转一个单链表。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL

*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <map>
#include <string>
#include <cmath>



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=NULL, *next=NULL;
        while(head){
            next=head;
            head=head->next;
            next->next=pre;
            pre=next;
        }
        return pre; 
    }
};