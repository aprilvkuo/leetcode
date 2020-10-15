/***************************************************************************
 *
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/
/**
 * @file    : 3.py
 * @author  : GuoHongjie 
 * @email   : guohongjie@baidu.com)
 * @date    : 2/9/2019, 5:38:54 PM
 *
 **/

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int>  char_last_position;
        int result = 0;
        int last_len = 0;
        int now_len = 0;
        map<char, int>::iterator find_res;
        for (int i = 0; i < s.size(); i++){
            now_len = last_len + 1;
            find_res = char_last_position.find(s[i]);
            if (find_res != char_last_position.end())
                now_len = min(now_len, i - find_res->second);
            
            result = max(result, now_len);
            last_len = now_len;
            char_last_position[s[i]] = i;
        }
        return result;

    }
};