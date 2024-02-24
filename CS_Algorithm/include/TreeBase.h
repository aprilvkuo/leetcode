//
// Created by april on 2020/7/12.
//

#ifndef ALGORITHM_TREEBASE_H
#define ALGORITHM_TREEBASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <assert.h>
#include "vector"

class TreeNode {
    public:
        TreeNode(double data): left(nullptr), right(nullptr), value(data) {};
        ~TreeNode();
        TreeNode *left, *right;
        double value;
};

class TreeMethod {
    public:
        static TreeNode* build_tree(std::vector<std::string> data);
        // 通过vector进行建树， 按层建数， 不存在的节点为“NULL”
        static void pre_traverse(TreeNode *root, int mode=0);
        // 先序遍历， mode为0， 表示递归遍历； mode为1， 表示非递归遍历
        static void mid_traverse(TreeNode *root, int mode=0);
        // 中序遍历， mode为0， 表示递归遍历； mode为1， 表示非递归遍历
        static void suf_traverse(TreeNode *root, int mode=0);
        // 后序遍历， mode为0， 表示递归遍历； mode为1， 表示非递归遍历
};


#endif //ALGORITHM_TREEBASE_H
