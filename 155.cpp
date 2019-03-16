/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\155.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-01
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-01-21
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
/*
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
*/
#include <iostream>
#include <vector>
#include <hash_map>
#include <string>
#include <cmath>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    struct Node{
        int val;
        struct Node* next;
        Node(int item){
            val=item;
            next=NULL;
        }
        Node(){
            val=0;
            next=NULL;
        }
    }; 
    struct Node *head;
    struct Node *min;
    struct Node *mid;
    int size;
    MinStack() {
        head=new Node();
        min =new Node(INT_MAX);
        size=0;
    }
    ~MinStack() {
        while(head->next){
            pop();
        }
        delete head;
        delete min;
    }
    void push(int x) {
        Node *p=new Node(x);
        p->next=head;
        head=p;
        if(min->val>=x){
            Node *q=new Node(x);
            q->next=min;
            min=q;
        }
        size++;
    }
    void pop() {
        if(head->next==NULL)
            return;
        if(head->val==min->val){
            mid=min;
            min=min->next;
            delete mid;
        }
        mid=head;
        head=head->next;
        delete mid; 
        size--;
    }
    int top() {
        return head->val;
    }
    int size(){
        return size;
    }
    int getMin() {
        return min->val;
    }
};