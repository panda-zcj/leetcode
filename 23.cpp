/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\23.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-01
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-01-24
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <map>
#include <string>
#include <cmath>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *list=NULL,*seq=NULL,*li=NULL;
        for(int i=0;i<lists.size();i++){
            if(!li){
                if(lists.at(i)!=NULL){
                    li=lists.at(i);
                    seq=li;
                    list=li;
                }
            }else{
                if(lists.at(i)!=NULL){
                    for(;seq->next!=NULL;){
                        seq=seq->next;
                    }
                    seq->next=lists.at(i);
                }
            }
        }
        int exchange ;
        for(;list!=NULL&&list->next!=NULL;){
            seq=list->next;
            for(;seq!=NULL&&seq->next!=NULL;){
                if( list->val > seq->val){
                    exchange=list->val;
                    list->val=seq->val;
                    seq->val=exchange;
                }
                seq=seq->next;
            }
            if( list->val > seq->val){
                exchange=list->val;
                list->val=seq->val;
                seq->val=exchange;
            }
            list=list->next;
        }
        return li;
    }
};