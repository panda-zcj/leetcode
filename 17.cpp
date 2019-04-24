/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\c_source_code\leetcode\17.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-01
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-03-19
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */


/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <hash_map>
#include <map>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int length=digits.size();
        if(!length){
            return vector<string>();
        }else{
            map<char,string> keyboard;
            keyboard.insert(pair<char,string>('2',"abc"));
            keyboard.insert(pair<char,string>('3',"def"));
            keyboard.insert(pair<char,string>('4',"ghi"));
            keyboard.insert(map<char,string>::value_type('5',"jkl"));
            keyboard.insert(pair<char,string>('6',"mno"));
            keyboard.insert(pair<char,string>('7',"pqrs"));
            keyboard.insert(pair<char,string>('8',"tuv"));
            keyboard.insert(pair<char,string>('9',"wxyz"));
            
            string word;
            vector<string> alphabet;
            int deep = 0,  layerNumber=length-1,  layer[length]={0};
            while (deep >=0 ) { 
                if (layer[deep] < keyboard.at(digits.at(deep)).size() ) {
                    word.push_back(keyboard.at(digits.at(deep)).at(layer[deep]));
                    layer[deep]++;//该层的节点数目
                    if(deep < layerNumber){
                        deep++;
                    }else{
                        alphabet.push_back(word);
                        word.pop_back();
                    }  
                }else {
                    //回到上一层，该层的节点数清零
                    layer[deep]=0;
                    deep--;
                    word.pop_back();
                }    
            }
            return alphabet;
        }
    }
};
int main(){
    Solution s;
    string test="23";
    vector<string> vec=s.letterCombinations(test);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec.at(i)<<"  ";
    }
    return 0;
}