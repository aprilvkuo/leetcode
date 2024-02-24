//
// Created by april on 2020/7/11.
//

#include "KMP.h"

std::vector<int> KMP::build_next_(const std::string &word) {
    int word_size = word.size();
    std::vector<int> next(word_size, 0);
    // build next
    for (int i = 1; i < next.size(); i++) {
        if (next[i - 1] != 0 && word[i] == word[next[i - 1]]) {
            next[i] = next[i - 1] + 1;
        } else if (word[i] == word[0]) {
            next[i] = 1;
        } else {
            next[i] = 0;
        }
    }
    return next;
}

int KMP::kmp_match(const std::string &query, const std::string &word) {
    auto next = build_next_(word);
    // match
    int query_index = 0, word_index = 0;
    while (query_index < query.size()) {
        while (word_index < word.size() &&
                query_index < query.size() &&
                query[query_index] == word[word_index]) {
            query_index++;
            word_index++;
        }
        if (word_index == word.size()) {

            return query_index-word_index;
        }
        word_index = next[word_index];
        query_index++;
    }
    return -1;
}

std::vector<int> KMP::kmp_match_all(const std::string &query, const std::string &word) {
    auto next = build_next_(word);
    std::vector<int> res;
    // match
    int query_index = 0, word_index = 0;
    while (query_index < query.size()) {
        while (query_index < query.size() &&
                word_index < word.size() &&
                query[query_index] == word[word_index]) {
            query_index++;
            word_index++;
        }
        if (word_index == word.size()) {
            res.push_back(query_index-word_index);
            word_index--;
            query_index--;
        }
        word_index = next[word_index];
        query_index++;
    }
    return res;
}