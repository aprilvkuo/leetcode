#include "Trie.h"

Trie::~Trie() {
    for (int i = 0; i < MAX_CHILD_NUM; i++) {
        if (child[i] != nullptr) {
            delete child[i];
        }
    }
}

Trie::Trie(){
    is_end = 0;
    cnt = 0;
    for (int i = 0; i < MAX_CHILD_NUM; i++) {
        child[i] = nullptr;
    }
}

bool Trie::delete_word(const string &s) {
    if (search_word(s) == false) {
        printf("[Trie] can't find word [%s] in trie tree \n", s.c_str());
        return false;
    }

    Trie *node  = this;
    for (int i = 0; i < s.size(); i++) {
        Trie *tmp = node->child[s[i]];
        if (tmp == nullptr) {
            return true;
        }
        tmp->cnt--;
        if (tmp->cnt == 0) {
            printf("[Trie] delete word [%s]  successfully when char [%c]\n", s.c_str(), s[i]);
            delete tmp;
            node->child[s[i]] = nullptr;
            return true;
        }
        node = tmp;
    }
    return true;
}

bool Trie::insert_word(const string &s) {
    if (search_word(s) == true) {
        printf("[Trie] word [%s] was in trie tree before\n", s.c_str());
        return false;
    }
    Trie *tmp  = this;
    for (int i = 0; i < s.size(); i++) {
        if (tmp->child[s[i]] == nullptr) {
            tmp->child[s[i]] = new Trie();
        }
        tmp = tmp->child[s[i]];
        tmp->cnt++;
    }
    tmp->is_end = 1;
    printf("[Trie] word: [%s] insert successfully\n", s.c_str());
    return true;
}

bool Trie::search_word(const string &s, int mode) {
    Trie *tmp  = this;
    for (int i = 0; i < s.size(); i++) {
        tmp = tmp->child[s[i]];
        if (tmp == nullptr) {
            return false;
        }

    }
    return mode == 0? tmp->is_end: 1;
}