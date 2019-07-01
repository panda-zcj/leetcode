/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\401.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-06
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-06-29
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
/*
二进制手表顶部有 4 个 LED 代表小时（0-11），底部的 6 个 LED 代表分钟（0-59）。

每个 LED 代表一个 0 或 1，最低位在右侧。



例如，上面的二进制手表读取 “3:25”。

给定一个非负整数 n 代表当前 LED 亮着的数量，返回所有可能的时间。

案例:

输入: n = 1
返回: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
 

注意事项:

输出的顺序没有要求。
小时不会以零开头，比如 “01:00” 是不允许的，应为 “1:00”。
分钟必须由两位数组成，可能会以零开头，比如 “10:2” 是无效的，应为 “10:02”。

*/
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#if 1
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> vec;
        /**
         *
         * @param   deep                    树迭代深度
         * @param   layerNumber             树深度，即层数
         * @param   layer[layerNumber]      树每层可选取得元素个数
         * @param   element                 数每层可选取得元素
         */
        int deep = 0,  layerNumber=9, layer[layerNumber+1]={0};
        vector<int> sum={0,1};
        vector<vector<int>> element(layerNumber+1,vector<int>(sum));
        sum.clear();
        int n=0;
        while (deep >=0 ) { 
            if ( layer[deep] < 2 ) { //每层可选取得元素个数为2
                n+= element[deep][layer[deep]];
                if(n > num){//减枝
                    n-= element[deep][layer[deep]];  
                    layer[deep]++;  //下一次迭代得元素
                }else{
                    sum.push_back(element[deep][layer[deep]]);//得到该层迭代结果
                    layer[deep]++;  //下一次迭代得元素
                    if(deep < layerNumber){
                        deep++;
                    }else{ 
                            if(n==num){
                                int  s=0;
                                int  hour;
                                int  minute;
                                char t[100]={0};
                                for(auto i:sum){
                                    s=s*2+i;
                                }
                                hour  =(s & 976)>>6;
                                minute= s & 63;
                                if(hour<12 && minute<60){
                                    sprintf(t,"%d:%02d",hour,minute);
                                    vec.push_back(string(t));
                                }
                            }
                            n-=sum.back();
                            sum.pop_back();
                    }  
                }
            } else {
                //回到上一层，该层的元素数清零
                layer[deep]=0;
                deep--;  
                if(sum.size()){//迭代结果回到上一层
                    n-=sum.back();
                    sum.pop_back(); 
                }
            }    
        }
        return vec;
    }
};
#else
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> vec;
        for(int i=0;i<1024;i++){
            int n=i&1;
            n+=(i&2)>>1;
            n+=(i&4)>>2;
            n+=(i&8)>>3;
            n+=(i&16)>>4;
            n+=(i&32)>>5;
            n+=(i&64)>>6;
            n+=(i&128)>>7;
            n+=(i&256)>>8;
            n+=(i&512)>>9;
            if(n==num){
                char t[100]={0};
                int hour  =(i & 0b1111000000)>>6;
                int minute= i & 0b111111;
                if(hour<12 && minute<60){
                    sprintf(t,"%d:%02d",hour,minute);
                    vec.push_back(string(t));
                }
            }
        }
        return vec;
    }
};
#endif
int main(){
    Solution s;
    vector<string> vec=s.readBinaryWatch(8);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec.at(i)<<"  ";
    }
    return 0;
}

