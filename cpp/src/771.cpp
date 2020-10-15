//
// Created by Guo,Hongjie on 2020-10-02.
//

#include "leetcode.h"

/*
 * https://leetcode-cn.com/problems/jewels-and-stones/
 * 使用set判断
 */
int numJewelsInStones(string J, string S) {
    set<char> jewel;
    for (int i = 0; i < J.size(); i++) {
        jewel.insert(J[i]);
    }
    int num = 0;
    for (int i = 0; i < S.size(); i++) {
        if (jewel.find(S[i]) != jewel.end())
            num ++;
    }
    return num;
}