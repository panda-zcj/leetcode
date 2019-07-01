/**
 * 
 * Copyright (c) 2019 南京航空航天大学 航空通信网络研究室
 * 
 * @file     d:\code\C\leetcode\37.cpp
 * @author   詹长建 (2233930937@qq.com)
 * @date     2019-06
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2019-07-01
 * Modified By:    詹长建 (2233930937@qq.com)
 * 
 */
/*
编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。


一个数独。


答案被标成红色。

Note:

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。

 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cmath>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int length=0,width=0;
        //location[deep]=length*9+width
        int location[81]={0},deep=0, layerNumber=-1,layer[81]={0};
        vector<vector<char>> element(9);
        int row[9][10]={0},column[9][10]={0},block[9][10]={0};
        int ch;
        for(int i=0; i<9 ; i++ ){
            for(int j=0; j<9 ;j++){
                if(board.at(i).at(j)!='.'){
                    ch=board.at(i).at(j)-'0';
                    row[i][ch]=1;
                    column[j][ch]=1;
                    block[i/3*3+j/3][ch]=1;
                }else
                {
                    layerNumber++;
                    location[layerNumber]=i*9+j;
                }
            }
        }   
        for(int i=0; i<9 ; i++ ){
            for(char j=1; j<10 ;j++){
                if(row[i][j]==0){
                    element.at(i).push_back(j+'0');
                }
            }
        }
        while (deep>=0)
        { 
            length=location[deep]/9;
            width =location[deep]%9;
            if(layer[location[deep]] < element.at(length).size()){
                ch=element.at(length).front()-'0';
                if(!(row[length][ch] || column[width][ch] || block[length/3*3+width/3][ch])){
                    board.at(length).at(width)=element.at(length).front();
                    row[length][ch]=1;
                    column[width][ch]=1;
                    block[length/3*3+width/3][ch]=1;
                    element.at(length).erase(element.at(length).begin());
                    layer[location[deep]]++;//下一次迭代下一个元素
                    if(deep < layerNumber){
                        deep++;
                    }else
                    {
                        return;
                    }  
                }else
                {
                    element.at(length).push_back(element.at(length).front()); //迭代下一个元素
                    element.at(length).erase(element.at(length).begin()); 
                    layer[location[deep]]++;
                }
            }else
            {
                layer[location[deep]]=0;
                deep--;
                if(deep>=0){
                    length=location[deep]/9;
                    width =location[deep]%9;
                    ch=board.at(length).at(width)-'0';
                    row[length][ch]=0;
                    column[width][ch]=0;
                    block[length/3*3+width/3][ch]=0; 
                    element.at(length).push_back(board.at(length).at(width));
                }
            } 
        }
    }
};
    
int main(int argc ,char** argv){
   
    vector<vector<char>> vec=
    {
    {'.','.','.','.','7','.','.','.','.'},
    {'6','.','.','1','.','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
    }; 
    Solution s;
    s.solveSudoku(vec);
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec.at(i).size();j++)
            cout<<vec.at(i).at(j)<<"  ";
        cout<<'\n';
    }
    return 0;
}