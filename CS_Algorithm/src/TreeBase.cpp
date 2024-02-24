//
// Created by april on 2020/7/12.
//

#include "TreeBase.h"

TreeNode::~TreeNode() {
    if (left != nullptr) {
        delete left;
        left = nullptr;
    }
    if (right != nullptr) {
        delete right;
        right = nullptr;
    }
    value = 0;
}

TreeNode* TreeMethod::build_tree(std::vector<std::string> data) {
    std::vector<TreeNode*> tree_data;
    for (auto &item : data) {
        if (item == "NULL") {
            tree_data.push_back(nullptr);
        } else {
            TreeNode* node = new TreeNode(std::stod(item));
            tree_data.push_back(node);
        }
    }
    for (int i = 0; i < data.size(); i++) {
        if (tree_data[i] != nullptr) {
            if ((i + 1) * 2 - 1 < data.size()) {
                tree_data[i]->left = tree_data[(i + 1) * 2 -1];
            }
            if ((i + 1) * 2 < data.size()) {
                tree_data[i]->right = tree_data[(i + 1) * 2];
            } else {
                break;
            }
        }
    }
    return tree_data[0];
}

void TreeMethod::pre_traverse(TreeNode *root, int mode) {
    if (mode == 0) {
        if (root == nullptr) {
            return;
        }
        printf("%lf,", root->value);
        pre_traverse(root->left);
        pre_traverse(root->right);
    } else {
        std::vector<TreeNode*> stack;
        stack.push_back(root);
        while (stack.size() != 0) {
            auto tmp = stack.back();
            stack.pop_back();
            if (tmp == nullptr) {
                continue;
            } else {
                printf("%lf,", tmp->value);
                stack.push_back(tmp->right);
                stack.push_back(tmp->left);
            }
        }
    }
}

void TreeMethod::mid_traverse(TreeNode *root, int mode) {
    if (mode == 0) {
        if (root == nullptr) {
            return;
        }
        mid_traverse(root->left);
        printf("%lf,", root->value);
        mid_traverse(root->right);
    } else {
        std::vector<TreeNode*> stack;
        while (root != nullptr) {
            stack.push_back(root);
            root = root->left;
        }
        while (stack.size() != 0) {
            auto tmp = stack.back();
            stack.pop_back();
            printf("%lf,", tmp->value);
            if (tmp->right) {
                root = tmp->right;
                while (root) {
                    stack.push_back(root);
                    root = root->left;
                }
            }


        }
    }
}

void TreeMethod::suf_traverse(TreeNode *root, int mode) {
    if (mode == 0) {
        if (root == nullptr) {
            return;
        }
        suf_traverse(root->left);
        suf_traverse(root->right);
        printf("%lf,", root->value);
    } else {
        std::vector<TreeNode*> stack_1;
        std::vector<TreeNode*> stack_2;
        stack_1.push_back(root);
        while (stack_1.size() != 0) {
            auto tmp = stack_1.back();
            stack_1.pop_back();
            if (tmp == nullptr) {
                continue;
            } else {
                stack_2.push_back(tmp);


                stack_1.push_back(tmp->left);
                stack_1.push_back(tmp->right);
            }
        }
        while (stack_2.size() != 0) {
            auto tmp = stack_2.back();
            printf("%lf,", tmp->value);
            stack_2.pop_back();
        }

    }

}