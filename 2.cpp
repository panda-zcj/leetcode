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
 * Last Modified:  2019-06-04
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */

/*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
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

//第一种解法
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

//第二种解法
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0,carry=0,a=l1->val,b=l2->val;
        ListNode* l3=new ListNode(0);
        ListNode* l4=l3;
        while( l1 || l2 ){
            sum=(a+b+carry)%10;
            carry=(a+b+carry)/10;
            ListNode* l4 =new ListNode(sum);
            l3->next=l4;
            l3=l4;
            a=(l1 && l1->next)?l1->next->val:0;
            b=(l2 && l2->next)?l2->next->val:0;
            l1=(l1 && l1->next)?l1->next:NULL;
            l2=(l2 && l2->next)?l2->next:NULL;
        }
        if(carry){
            ListNode* l4 =new ListNode(carry);
            l3->next=l4;
            l3=l4;
        }
        return l4->next;
    }
};