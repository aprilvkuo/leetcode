#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <assert.h>
//#include <glog/logging.h>
//http://www.hankcs.com/program/java/%e5%8f%8c%e6%95%b0%e7%bb%84trie%e6%a0%91doublearraytriejava%e5%ae%9e%e7%8e%b0.html

using namespace std;

const int MAX_CHILD_NUM = 128;

class Trie
{
    public:
        bool is_end;    // 是否为结尾
        Trie *child[MAX_CHILD_NUM];    // 儿子节点
        int cnt;    // 该节点出现的次数， 方便删除
    public:
        ~Trie();
        Trie();
        bool delete_word(const string &s); // 当单词不在字典中， 返回false
        bool insert_word(const string &s); // 当单词已经在字典中， 返回false
        bool search_word(const string &s, int mode=0);  // mode: 0 表示字典查询， 1 表示前缀查询

};

#endif // TRIE_H
