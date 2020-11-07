//
// Created by April Kuo on 2020/10/12.
//

// https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/

/*
 * 中序遍历
 */
class Solution {
public:
	int min_num = INT_MAX;
	int now_num = -1;
	void mid_travel(TreeNode* root) {
		
		if (root->left) {
			mid_travel(root->left);
		}
		if (now_num != -1) {
			min_num = min(root->val - now_num, min_num);
		}
		now_num = root->val;
		if (root->right) {
			mid_travel(root->right);
		}
	}
	int getMinimumDifference(TreeNode* root) {
		if (root)
			mid_travel(root);
		return min_num;
	}
};

