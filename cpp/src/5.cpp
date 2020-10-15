/***************************************************************************
 *
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/
/**
 * @file    : 5.py
 * @author  : GuoHongjie 
 * @email   : guohongjie@baidu.com)
 * @date    : 2/9/2019, 8:53:06 PM
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
 **/

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max_len = 0;
        string max_string = "";
        int all_the_same = 0;
        int last_len = 0;
        string last_string = "";
        if (s.size() == 0)
            return max_string;
        for (int i = 0; i < s.size(); i++){
            if (i == 0){
                last_len = 1;
                last_string = s[i];
                all_the_same = 1;
            }
            else{
                if (i-last_len-1 >= 0 && s[i-last_len-1] == s[i]){
                    last_len+=2, last_string = s[i] + last_string +s[i];
                    if (s[i] != s[i-1])
                        all_the_same = 0;
                }
                else if (s[i-1] == s[i] && all_the_same == 1)
                    last_len += 1, last_string = last_string + s[i];
                else if (s[i] == s[i-1]){
                    last_len = 2;
                    last_string = last_string + s[i];
                    all_the_same = 1;
                }
                else
                {
                    last_len = 1;
                    last_string = s[i];
                }
                
            }
            if (last_len > max_len)
                max_len = last_len, max_string = last_string;
        }
        return max_string;
    }
};

int main(){
    
}