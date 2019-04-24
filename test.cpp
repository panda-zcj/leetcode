/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\test.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-03
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-03-19
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
#include <iostream>
using namespace std;
//递归实现
void getSubset(int list[],bool v[],int a,int b){
  if(a == b){
    for(int i = 0; i < b; i++){
      if(v[i])
      cout<<list[i]<<"  ";
    }
    cout<<endl;
    return;
  }
  v[a] = true;
  getSubset(list,v,a+1,b);
  v[a] = false;
  getSubset(list,v,a+1,b);
 
}
//迭代实现
void getSubset_iterative(int list[],int n){
    int t = 0;//t 代表解空间树的深度
    bool v[n+1] = {false,false,false};
    int init[n+1] = {0,0};
    while( t >= 0){
        if( init[t] < 2){
            init[t]++;
            cout<<"init"<<"["<<t<<"]="<<init[t]<<"  ";
            v[t] = !v[t];
            if( t >= n ){
                for(int i = 0; i <=n; i++){
                    if(v[i]) {
                        cout<<list[i]<<"  ";
                    }else{
                        cout<<"-"<<"  ";
                    }
                }
                cout<<"t="<<t<<endl;
            }else{
                ++t;//进入下一层
                cout<<"t1="<<t<<endl;
            } 
        }else{
            //回溯至上一层，并将该层的状态重置，一定要重置
            init[t] = 0;
            --t;
            cout<<"t2="<<t<<endl;
        }    
    } 
}
int main(){
    int li[] = {1,2,3};
    bool v[] = { false,false,false,false};
    // getSubset(li,v,0,4);
    getSubset_iterative(li,2);
}