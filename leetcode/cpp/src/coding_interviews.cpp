/*
 * @Author: your name
 * @Date: 2020-11-15 16:31:19
 * @LastEditTime: 2020-11-15 20:37:34
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcode/src/coding_interviews.h
 */

#include "coding_interviews.h"
namespace leetcode {

int Solution::findRepeatNumber(vector<int>& nums) {
    int tmp = 0;
    for (int i = 0; i < nums.size(); i++) {
        while (nums[i] != i) {
            tmp = nums[nums[i]];
            if (nums[nums[i]] == nums[i]) {
                return nums[i];
            }
            nums[nums[i]] = nums[i];
            nums[i] = tmp;
        }
    }
    return 0;
}

vector<int> Solution::reversePrint(ListNode* head) {
    vector<int> res;
    if (head == nullptr) {
        return res;
    }
    res = reversePrint(head->next);
    res.push_back(head->val);
    return res;
}

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree(preorder, inorder, 0, preorder.size()-1, 0, preorder.size()-1);
}

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder, int p_begin, int p_end, int i_begin, int i_end) {
    if (p_end < p_begin) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[p_begin]);
    int left_size = 0;
    for (int i = i_begin; inorder[i] != preorder[p_begin]; i++) {
        left_size ++;
    }
    int right_size = p_end - p_begin - left_size;
    root->left = buildTree(preorder, inorder, p_begin + 1, p_begin + left_size, i_begin, i_begin + left_size - 1);
    root->right = buildTree(preorder, inorder, p_begin + left_size + 1, p_end, i_begin + left_size + 1, i_end);
    return root;
}

int Solution::fib(int n) {
    int mod_num = 1000000007;
    if (n <= 1) {
        return n;
    }
    int data_1 = 0, data_2 = 1;
    int target = 0;
    for (int i = 2; i <= n; i++) {
        target = (data_1 + data_2) % mod_num;
        data_1 = data_2;
        data_2 = target;
    }
    return target;    
}

int Solution::minArray(vector<int>& numbers) {
    int left = 0, right = numbers.size() - 1;
    int mid  = 0;
    while (left < right) {
        int mid = left + (right-left) / 2;

        if (numbers[mid] > numbers[right]) {
            left = mid + 1;
        } else if (numbers[mid] < numbers[right]) {
            right = mid;
        } else {
            right--;
        }
    }
    return numbers[left];
}

bool Solution::exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0 || board[0].size() == 0) {
        return 0;
    }
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (exist(board, word, 0, i, j)) {
                return true;
            }
        }
    }
    return false;
}

bool Solution::exist(vector<vector<char>>& board, string word, int begin, int x, int y) {
    if (begin == word.size()) {
        return true;
    }
    if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || 
        word[begin] != board[x][y]) {
        return false;
    }
    
    int x_change[4] = {1, -1, 0, 0};
    int y_change[4] = {0, 0, 1, -1};
    board[x][y] = '\0';
    bool result = false;
    for (int i = 0; i < 4; i++) {
        if (result == false) {
            result = exist(board, word, begin + 1, x + x_change[i], y + y_change[i]);
        }
    }
    board[x][y] = word[begin];
    return result;
}

double Solution::myPow(double x, int n) {
    if (x == 0 || x == 1) {
        return x;
    }
    if (n < 0) {
        return myPow(1.0 / x, -1 - n) / x;
    }
    double result = 1.0;
    double base = x;
    while (n != 0) {
        if (n & 1 == 1) {
            result *= base;
        }
        n = n >> 1;
        base *= base;
    }
    return result;
}

int Solution::hammingWeight(uint32_t n) {
    int cnt = 0;
    for (int i = 0; i < 32; i ++) {
        if (n & 1 ){
            cnt ++;
        }
        n >>=1;
    }
    return cnt;
}

int Solution::movingCount(int m, int n, int k) {
    vector<vector<bool>> flags (m, vector<bool>(n, false));
    int cnt_num = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            bool flag = false;

            if ((i - 1 >= 0 && flags[i - 1][j] == 1) ||
                (j - 1 >= 0 && flags[i][j -1] == 1) ||
                (i + j == 0) ) {
                flag = true;
            }
        
            if (flag && moving_result(i, j, k)) {
                flags[i][j] = 1;
                cnt_num ++;
            }
        }
    }
    return cnt_num;
}
bool Solution::moving_result(int m, int n, int k) {
    int cnt = 0;
    while (m != 0) {
        cnt += (m % 10);
        m /= 10;
    }
    while (n != 0) {
        cnt += (n % 10);
        n /= 10;
    }
    return cnt <= k ? true: false;
}

int Solution::cuttingRope(int n) {
    vector<int> dp(n + 1, 0);
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = max(dp[i], j * dp[i - j]);
            dp[i] = max(dp[i], j * (i-j));
        }
    }
    return dp[n];
}

}