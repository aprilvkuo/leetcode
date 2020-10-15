//
// Created by April Kuo on 2020/10/13.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 *
 * 1. 我怕出错， 写了一个栈写法
 * 2. 递归， 代码很精简
 * 3. 最简单的暴力， 但是容易写错
 */
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* new_node = new ListNode(0);
		ListNode* tmp = new_node;
		vector<ListNode*> stack;
		while (head) {
			stack.push_back(head);
			head = head->next;
			if (stack.size() == 2) {
				while (stack.size() != 0) {
					new_node->next = stack.back();
					stack.pop_back();
					new_node = new_node->next;
				}
			}
			
		}
		while (stack.size() != 0) {
			new_node->next = stack.back();
			new_node = new_node->next;
			stack.pop_back();
			
		}
		new_node->next=NULL;
		return tmp->next;
	}
};