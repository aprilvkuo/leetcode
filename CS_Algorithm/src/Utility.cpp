//
// Created by april on 2020/7/11.
//

#include "Utility.h"

// 分离函数的声明与定义遇到的问题: https://blog.csdn.net/imred/article/details/80261632


template <typename T>

void print_vector(const std::vector<T> &data) {
    std::cout << "[";
    for (auto &item: data) {
        std::cout << item << ",";
    }
    std::cout << "]\n";

//    std::string out_str;
//    out_str += "[";
//    for (auto &item: data) {
//        out_str += std::to_string(item) + ",";
//    }
////    out_str = out_str.substr(0, out_str.size() - 1);
//    out_str += "]\n";
////    printf("%s", out_str.c_str());
}

template void print_vector(const std::vector<float> &data);

template void print_vector(const std::vector<int> &data);

