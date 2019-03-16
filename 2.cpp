/**
 * 
 * Copyright (c) 2018 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\2.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2018-12
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-12-26
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0,carry=0,a,b;
        ListNode *l3 = new ListNode(0);
        ListNode *l4 = l3;
        while(l1 || l2){
            a=l1?l1->val:0;
            b=l2?l2->val:0;
            if(l1) l1=l1->next?l1->next:NULL;
            if(l2) l2=l2->next?l2->next:NULL;
            sum  = (l4->val+a+b)%10;
            carry= (l4->val+a+b)/10;
            l4->val =sum; 
            if((!l1) && (!l2) && (!carry))
            {
                break;
            } 
            ListNode *l = new ListNode(carry);
            l4->next=l;
            l4=l;    
        }
        return l3;
    }
};