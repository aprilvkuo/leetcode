//
// Created by april on 2020/7/11.
//

#ifndef ALGORITHM_KMP_H
#define ALGORITHM_KMP_H
#include <iostream>
#include "vector"

/*
 * http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
 */

class KMP {
public:
    static int kmp_match(const std::string &query, const std::string &word);

    // ret code of -1 means: there is no match res
    // ret code of k means : the begin position of query of first matched pattern
    static std::vector<int> kmp_match_all(const std::string &query, const std::string &word);
    // return : the begin position of query of all matched patterns

private:
    static std::vector<int> build_next_(const std::string &word);
};


#endif //ALGORITHM_KMP_H
