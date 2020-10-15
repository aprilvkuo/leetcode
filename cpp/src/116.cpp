//
// Created by April Kuo on 2020/10/15.
//

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

 https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
 
 116. 填充每个节点的下一个右侧节点指针
 
 解法： 栈解法
*/

class Solution {
public:
	Node* connect(Node* root) {
		if (root == nullptr)
			return root;
		queue<Node*> q;
		q.push(root);
		while (q.size() != 0) {
			queue<Node*> q_new;
			while (q.size() != 0) {
				Node* node = q.front();
				q.pop();
				node->next = q.size() == 0? nullptr: q.front();
				if (node->left != nullptr) q_new.push(node->left);
				if (node->right != nullptr) q_new.push(node->right);
			}
			q = q_new;
		}
		return root;
	}
};