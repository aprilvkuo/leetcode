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

int findRepeatNumber(vector<int>& nums) {
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

vector<int> reversePrint(ListNode* head) {
    vector<int> res;
    if (head == nullptr) {
        return res;
    }
    res = reversePrint(head->next);
    res.push_back(head->val);
    return res;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree(preorder, inorder, 0, preorder.size()-1, 0, preorder.size()-1);
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int p_begin, int p_end, int i_begin, int i_end) {
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

int fib(int n) {
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

int minArray(vector<int>& numbers) {
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

bool exist(vector<vector<char>>& board, string word) {
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

bool exist(vector<vector<char>>& board, string word, int begin, int x, int y) {
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

double myPow(double x, int n) {
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

int hammingWeight(uint32_t n) {
    int cnt = 0;
    for (int i = 0; i < 32; i ++) {
        if (n & 1 ){
            cnt ++;
        }
        n >>=1;
    }
    return cnt;
}

int movingCount(int m, int n, int k) {
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
bool moving_result(int m, int n, int k) {
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

int cuttingRope(int n) {
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

bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (!B || !A) {
        return false;
    }
    else{
        return isSubStructure1(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    
}

bool isSubStructure1(TreeNode* A, TreeNode* B) {
    if (!B || !A) {
        return false;
    }
    if (A->val == B->val &&
        (!B->left || isSubStructure1(A->left, B->left)) &&
        (!B->right || isSubStructure1(A->right, B->right))) {
        return true;
    }
    return false;
}

bool isMatch(string s, string p) {
    // return isMatch(s, p, 0, 0);
    vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
    for (int i = 0; i <= s.size(); i++) {
        for (int j = 0; j <= p.size(); j++) {
            if (j == 0) {
                dp[i][j] = i == 0 ? 1: 0;
            } else {
                if ((i > 0 && j > 0) && 
                    (s[i-1] == p[j-1] || p[j-1] == '.')) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    if (j > 0 && p[j - 1] == '*') {
                        if (i > 0 && (p[j - 2] == '.' || p[j-2] == s[i-1])) {
                            dp[i][j] |= dp[i-1][j];
                        }
                        if (j > 1) {
                            dp[i][j] |= dp[i][j-2];
                        }   
                    }

                }
                
            }
            
        }
    }
    return dp[s.size()][p.size()];  
}

ListNode* deleteNode(ListNode* head, int val) {
    ListNode* tmp_head = new  ListNode(-1);
    tmp_head->next = head;
    head = tmp_head;
    while (head) {
        if (head->next && head->next->val == val) {
            head->next = head->next->next;
        }
        head = head->next;
    }
    return tmp_head->next;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* tmp_head = new ListNode(-1);
    ListNode* head = tmp_head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            tmp_head->next = l1;
            tmp_head = tmp_head->next;
            l1 = l1->next;
        } else {
            tmp_head->next = l2;
            tmp_head = tmp_head->next;
            l2 = l2->next;
        }
    }
    while (l1) {
        tmp_head->next = l1;
        tmp_head = l1;
        l1 = l1->next;
    }
    while (l2) {
        tmp_head->next = l2;
        tmp_head = l2;
        l2 = l2->next;
    }
    return head->next;
}

  ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
        // vector<ListNode*> vec_tmp;
        // while (head) {
        //     vec_tmp.push_back(head);
        //     head = head->next;
        // }
        // ListNode *ret_node = vec_tmp.back();
        // ListNode *tmp_ret_node = ret_node;
        // vec_tmp.pop_back();
        // while (vec_tmp.size() != 0) {
        //     ret_node->next = vec_tmp.back();
        //     ret_node = vec_tmp.back();
        //     vec_tmp.pop_back();
        // }
        // ret_node->next = nullptr;
        // return tmp_ret_node;


        // ListNode *ret_node = head;
        // ListNode *tmp_head = head->next;
        // ret_node->next = nullptr;
        // while (tmp_head) {
        //     ListNode *tmp_head2 = ret_node;
        //     ret_node = tmp_head;

        //     tmp_head = tmp_head->next;
        //     ret_node->next = tmp_head2;
        // }
        // return ret_node;
    }

     vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            while (left < right && nums[left] % 2 == 1) {
                left++;
            }
            while (left < right && nums[right] % 2 == 0) {
                right--;
            }
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
        }
        return nums;
    }


ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode* fast = head, *slow = head;
    while (k > 0 && fast) {
        fast = fast->next;
        k--;
    }
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}


bool findNumberIn2DArray(vector<vector<int>>& array, int target) {
    if (array.size() == 0) {
        return false;
    }
    int size_0 = array.size();
    int size_1 = array[0].size();
    int x = 0, y = size_1 - 1;
    while (true) {
        if (x >= size_0 || y < 0) {
            return false;
        }
        if (array[x][y] == target) {
            return true;
        } else if (array[x][y] > target) {
            y --;
        } else {
            x ++;
        }
    }
    return true;
}

TreeNode* mirrorTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        TreeNode *right = mirrorTree(root->left);
        TreeNode *left = mirrorTree(root->right);
        root->left = left;
        root->right = right;
        return root;
    }


bool isSymmetric(TreeNode* root) {
    if (!root) {
        return true;
    }
    return isSymmetric(root->left, root->right);
}

bool isSymmetric(TreeNode* left, TreeNode* right) {
    if (!left && !right) {
        return true;
    }
    if (!(left && right)) {
        return false;
    }
    if (left->val != right->val) {
        return false;
    }
    return isSymmetric(left->left, right->right) && 
            isSymmetric(left->right, right->left);
}

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    vector<int> states;
    int p_id = 0;
    for (int i = 0; i < pushed.size(); i++) {
    
        states.push_back(pushed[i]);
        while (states.size() > 0 && 
                p_id < popped.size() &&
                states.back() == popped[p_id]) {
            states.pop_back();
            p_id++;
        }
    }
    return states.size() == 0;
}

vector<int> levelOrder(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> q;
    q.push(root);
    while (q.size() != 0) {
        auto head = q.front();
        if (head) {
            if (head->left) q.push(head->left);
            if (head->right) q.push(head->right);
            res.push_back(head->val);
        }
        
        q.pop();
    }
    return res;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> q;
    queue<TreeNode*> next_q;
    q.push(root);
    vector<int> now_res;
    while (q.size() != 0 || next_q.size() != 0) {
        if (q.size() == 0) {
            res.push_back(now_res);
            now_res.clear();
            q = next_q;
            next_q = queue<TreeNode*>();
        }
        auto head = q.front();
        if (head) {
            if (head->left) next_q.push(head->left);
            if (head->right) next_q.push(head->right);
            now_res.push_back(head->val);
        }
        
        q.pop();
    }
    if (now_res.size() != 0) res.push_back(now_res);
    return res;
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> q;
    queue<TreeNode*> next_q;
    q.push(root);
    vector<int> now_res;
    int level_index = 0;
    while (q.size() != 0 || next_q.size() != 0) {
        if (q.size() == 0) {
            if (level_index % 2) reverse(now_res.begin(), now_res.end());
            res.push_back(now_res);
            now_res.clear();
            q = next_q;
            next_q = queue<TreeNode*>();
            level_index++;
        }
        auto head = q.front();
        if (head) {
            if (head->left) next_q.push(head->left);
            if (head->right) next_q.push(head->right);
            now_res.push_back(head->val);
        }
        
        q.pop();
    }
    if (level_index % 2) {
        reverse(now_res.begin(), now_res.end());
    }
    if (now_res.size() != 0 ) res.push_back(now_res);
    return res;
}



}