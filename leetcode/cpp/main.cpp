#include <iostream>
#include "vector"
#include "stack"
#include "stdio.h"
#include "sstream"

using namespace std;


//
//bool Find(int target, vector<vector<int> > array) {
//    if (array.size() == 0 || array[0].size() == 0){
//        return false;
//    }
//    int i = array.size()-1;
//    int j = 0;
//
//    while (array[i][j] != target){
//        if (target > array[i][j])
//            j++;
//        else
//            i--;
//        if (i < 0 || j >= array[0].size())
//            return false;
//
//    }
//    return true;
//
//}
//
//
//void replaceSpace(char *str,int length) {
//    int str_len = 0;
//    int space_len = 0;
//    while (str[str_len] != '\0')
//    {
//        if (str[str_len] == ' ')
//            space_len ++;
//        str_len ++;
//    }
//    int new_str_end = str_len + space_len*2;
//    str[new_str_end] = '\0';
//    new_str_end --;
//    str_len --;
//    while(new_str_end >= 0){
//        if (str[str_len] != ' ')
//        {
//            str[new_str_end--] = str[str_len--];
//        }
//        else{
//            str[new_str_end--]='0';
//            str[new_str_end--]='2';
//            str[new_str_end--]='%';
//            str_len--;
//        }
//    }
//    return;
//}
//
//
// struct ListNode {
//   int val;
//   struct ListNode *next;
//   ListNode(int x) :
//   val(x), next(NULL) {}
//  };
//
//vector<int> printListFromTailToHead(ListNode* head) {
//    vector<int> a;
//    while(head){
//        a.emplace_back(head->val);
//        if (head->next != NULL)
//            head = head->next;
//    }
//    std::reverse(a.begin(), a.end());
//    return a;
////    while (!a.empty()){
////        b.emplace_back(a.back());
////        a.pop_back();
////    }
////    return b;
//}
//
////struct TreeNode {
////        int val;
////        TreeNode *left;
////        TreeNode *right;
////        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
////};
////
////
////TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
////    if (pre.size() == 0)
////        return NULL;
////    TreeNode* root = new TreeNode(pre[0]);
////
////
////}
////
////TreeNode* reConstructBinaryTree(vector<int> &pre,vector<int> &vin, int left1, int right1, int left2, int right2) {
////
////    int node_num = right1 - left1 + 1;
////    TreeNode* root = new TreeNode(pre[left1]);
////    if (node_num == 1)
////        return root;
////   int left_num = 0;
////   while (vin[left2 + left_num] != pre[left1])
////       left_num ++;
////
////
////
////}
//
//stack<int> stack1;
//stack<int> stack2;
//
//void push(int node) {
//    stack1.push(node);
//}
//
//int pop() {
//    if (stack2.empty()){
//        while (!stack1.empty()){
//            stack2.push(stack1.top());
//            stack1.pop();
//        }
//    }
//    int result = stack2.top();
//    stack2.pop();
//    return result;
//
//}
//
//
//int minNumberInRotateArray(vector<int> rotateArray) {
//
//}
//
//
//
//int Fibonacci(int n) {
//    if (n == 0) return 0;
//    if (n == 1 || n == 2)
//        return 1;
//    int a = 1, b =1;
//    int a1 = 0, b1 = 0;
//    for (int i = 0 ; i < n - 2; i++){
//        a1 = a + b;
//        a = b;
//        b = a1;
//    }
//    return b;
//}
//
//int jumpFloor(int n) {
////    if (n==1 or n == 2)
////        return 1;
////    return jumpFloor(n-1) + jumpFloor(n-2);
//
//    if (n == 1) return 1;
//    int a = 1, b =1;
//    int a1 = 0, b1 = 0;
//    for (int i = 0 ; i < n - 1; i++){
//        a1 = a + b;
//        a = b;
//        b = a1;
//    }
//    return b;
//}
//
//int jumpFloorII(int number) {
//    if (number == 1)
//        return 1;
//    return 2*jumpFloorII(number-1);
//}
//
//
//int rectCover(int number) {
//    if (number <= 2) return number;
//    return rectCover(number-2) + rectCover(number-1);
//}
//
//
//int  NumberOf1(int n) {
//    int cnt = 0;
//    for (int i = 0; i < 32; i++){
//        if (n & 1  == 1)
//            cnt += 1;
//        n = n >> 1;
//    }
//    return cnt;
//}
//
//
//
//double Power(double base, int exponent) {
//    if (exponent  == 0) return 1;
//    if (exponent < 0)   base = 1.0/base, exponent=-exponent;
//    double result = 1.0;
//
//    int times = 2;
//    while (exponent != 0){
//        if (exponent % times == 1)
//            result *= base;
//        exponent = exponent/2;
//        base *= base;
//    }
//    return result;
//}
//
//ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
//    ListNode* quick, *slow;
//    quick = pListHead, slow = pListHead;
//    for (int i = 0; i < k; i++){
//        if (quick == NULL)
//            return NULL;
//        quick = quick->next;
//    }
//
//    while (quick != NULL){
//        quick = quick->next;
//        slow = slow->next;
//    }
//    return slow;
//
//}
//
//ListNode* ReverseList(ListNode* pHead) {
//    ListNode* new_node, *tmp_node;
//    new_node = NULL;
//    while (pHead){
//        tmp_node = pHead;
//        pHead = pHead->next;
//        tmp_node->next = new_node, new_node = tmp_node;
//    }
//    return new_node;
//}
//
//
//ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
//{
//    ListNode* new_node = new ListNode(-1);
//    ListNode* tmp_node;
//    tmp_node = new_node;
//    while (pHead1 != NULL && pHead2 != NULL){
//        if(pHead1->val < pHead2->val){
//            tmp_node->next = pHead1;
//            tmp_node = tmp_node->next;
//            pHead1 = pHead1->next;
//        }
//        else{
//            tmp_node->next = pHead2;
//            tmp_node = tmp_node->next;
//            pHead2 = pHead2->next;
//        }
//    }
//    if (pHead1 != NULL){
//        tmp_node->next = pHead1;
//    }
//    if (pHead2 != NULL){
//        tmp_node->next = pHead2;
//    }
//    return new_node->next;
//}
//
//
//struct TreeNode {
//    int val;
//    struct TreeNode *left;
//    struct TreeNode *right;
//
//    TreeNode(int x) :
//            val(x), left(NULL), right(NULL) {
//    }
//};
//
////bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
////{
////    if (!pRoot1 or !pRoot2) return false;
////    if (pRoot1->val == pRoot2->val){
////        if ((pRoot2->left == NULL || HasSubtree(pRoot1->left, pRoot2->left)) &&
////        (pRoot2->right == NULL || HasSubtree(pRoot1->right, pRoot2->right)))
////            return true;
////        else
////            return false;
////    }
////    else{
////        return HasSubtree(pRoot1->left, pRoot2) or HasSubtree(pRoot1->right, pRoot2);
////    }
////
////}
//
//
//void Mirror(TreeNode *pRoot) {
//    if (!pRoot) return;
//    Mirror(pRoot->left);
//    Mirror(pRoot->right);
//    TreeNode *tmpnode;
//    tmpnode = pRoot->right;
//    pRoot->right = pRoot->left;
//    pRoot->left = tmpnode;
//    return;
//}
//
//class Solution {
//public:
//    void push(int value) {
//        data.push(value);
//        min_data.push(std::min(value, min_data.top()));
//    }
//    void pop() {
//        if (!data.empty()){
//            data.pop();
//            min_data.pop();
//        }
//
//    }
//    int top() {
//        if (data.empty())
//            return -1;
//        return data.top();
//    }
//    int min() {
//        if (min_data.empty())
//            return -1;
//        return min_data.top();
//    }
//
//    stack<int> data, min_data;
//};
//
//
//
//
//bool isValidSerialization(string preorder) {
//    /*
//     * https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/
//     */
//
//    if (preorder == "#" or preorder == "")
//        return true;
//
//    cout << preorder << endl;
//    cout << preorder[preorder.size()-1] << endl;
//    if (preorder[preorder.size()-1] != '#') {
//        return false;
//    } else {
//        preorder = preorder.substr(0, preorder.size() - 1);
//    }
//
//
//    vector<string> nodes;
//    stringstream ss;
//    string tmp;
//    ss << preorder;
//    cout << preorder << endl;
//    while(getline(ss, tmp, ',')) {
//        cout << tmp << endl;
//        if (tmp == "#") {
//            if (nodes.empty()) {
//                return false;
//            } else {
//                nodes.pop_back();
//            }
//        } else {
//            nodes.push_back(tmp);
//        }
//    }
//
//    return nodes.empty()? true: false;
//}
//
//
//string decodeString(string s) {
//    int num = 0;
//
//    for (int i = 0 ; i < s.size(); i++) {
//        if (s[i] >= '0' && s[i] <= '9') {
//            num *= 10;
//            num += (s[i] - '0');
//        } else {
//            if (num != 0) {
//
//            }
//        }
//    }
//}
//
//int minAddToMakeValid_1(string S) {
//    vector<char> stack;
//    for (auto item : S) {
//        if (stack.empty()) {
//            stack.push_back(item);
//        } else if ( item == ')' and stack.back() == '('){
//           stack.pop_back();
//        } else {
//            stack.push_back(item);
//        }
//
//    }
//    return stack.size();
//}
//
//int minAddToMakeValid(string S) {
//    int left = 0, right = 0;
//    for (auto item : S) {
//        if (item == ')') {
//            left += 1;
//        } else {
//            left -= 1;
//        }
//        if (left == -1) {
//            left ++;
//            right ++;
//        }
//
//    }
//    return left + right;
//}
//
//
///**
// * // This is the interface that allows for creating nested lists.
// * // You should not implement it, or speculate about its implementation
// * class NestedInteger {
// *   public:
// *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
// *     bool isInteger() const;
// *
// *     // Return the single integer that this NestedInteger holds, if it holds a single integer
// *     // The result is undefined if this NestedInteger holds a nested list
// *     int getInteger() const;
// *
// *     // Return the nested list that this NestedInteger holds, if it holds a nested list
// *     // The result is undefined if this NestedInteger holds a single integer
// *     const vector<NestedInteger> &getList() const;
// * };
// */
////class NestedIterator {
////public:
////    NestedIterator(vector<NestedInteger> &nestedList) {
////        for (auto item : nestedList) {
////            if (item.isInteger()) {
////                s.push_back(item.getInteger());
////            } else {
////                add_int(item, s);
////            }
////        }
////        reverse(s.begin(), s.end());
////    }
////
////    void add_int(NestedInteger &data, vector<int> &s) {
////        if (data.isInteger()) {
////            s.push_back(data.getInteger());
////        } else {
////            add_int(data, s);
////        }
////    }
////
////    int next() {
////        int tmp = s.back();
////        s.pop_back();
////        return s;
////
////    }
////
////    bool hasNext() {
////        return !s.empty();
////
////    }
////
////private:
////    vector<int> s;
////
////};
//
///**
// * Your NestedIterator object will be instantiated and called as such:
// * NestedIterator i(nestedList);
// * while (i.hasNext()) cout << i.next();
// */
//
//
//vector<int> dailyTemperatures_1(vector<int>& T) {
//    vector<int> res;
//    for (int i = 0; i < T.size(); i++) {
//        int cnt = 0;
//        if (i > 0 && T[i] >= T[i-1]){
//            cnt = res.back()-1;
//        }
//        for (int j = cnt; j < T.size(); j++) {
//            cnt++;
//            if (T[i+j] > T[i]) {
//                res.push_back(cnt);
//                cnt = 0;
//                break;
//            }
//        }
//        if (cnt != 0 or i == T.size()-1) {
//            res.push_back(0);
//        }
//    }
//    return res;
//}
//
//vector<int> dailyTemperatures(vector<int>& T) {
//    vector<int> res;
//    vector<int> stack;
//    for (int i = T.size()-1; i >= 0; i--) {
//
//        while (!stack.empty() && T[i] >= stack.back()) {
//            stack.pop_back();
//        }
//
//        if (stack.empty())
//            res.push_back(0);
//        else
//            res.push_back(stack.back()-i);
//
//        stack.push_back(i);
//    }
//    return res;
//}
//
//
//bool isValid(string S) {
//    vector<char> stack;
//    for (int i = 0; i < S.size(); i++) {
//        stack.push_back(S[i]);
//        if (stack.size() >= 3) {
//            int stack_size = stack.size();
//            if (stack[stack_size-3] == 'a' && stack[stack_size-2] == 'b'
//                && stack[stack_size-1] == 'c') {
//                stack.pop_back();
//                stack.pop_back();
//                stack.pop_back();
//            }
//        }
//    }
//    return stack.size() == 0;
//}
//
//
//bool isValid(string S) {
//    stack<char> stk;
//    for (char c : S) {
//        if (c != 'c') {
//            stk.push(c);
//        } else {
//            if (stk.empty() || stk.top() != 'b') return false;
//            stk.pop();
//            if (stk.empty() || stk.top() != 'a') return false;
//            stk.pop();
//        }
//    }
//    return stk.empty();
//}
//
//bool Greater(int & data_left, int & data_right)
//{
//    return data_left >= data_right;
//}
//
//int mctFromLeafValues(vector<int>& arr) {
//    // a b c   |  a c b
//    vector<int> res;
//    int sum_num = 0;
//    for (int i = 0; i < arr.size(); i++) {
//
//        while (res.size() >= 2 && arr[i] >= res.back()) {
//            sum_num += res.back() * min(arr[i], res[res.size()-2]);
//            res.pop_back();
//        }
//
//        res.push_back(arr[i]);
//    }
//    while (res.size() > 2) {
//        int last_num = res.back();
//        res.pop_back();
//        sum_num += last_num * res.back();
//    }
//    return sum_num;
//}
//
//
//string minRemoveToMakeValid(string s) {
//    vector<int> rm_index;
//    vector<int> rm_stack;
//    for (int i = 0; i < s.size(); i++) {
//        if (s[i] == '(' {
//            rm_stack.push_back(i);
//        } else if (s[i] == ')') {
//            if (rm_stack.empty()) {
//                rm_index.append(i);
//            } else {
//                rm_stack.pop_back();
//            }
//        }
//    }
//    while (!rm_stack.empty()) {
//        rm_index.push_back(rm_stack.back());
//        rm_stack.pop_back();
//    }
//    string res = "";
//    int j = 0;
//    for (int i = 0; i < s.size(); i++) {
//        if (j < rm_index.size() && i == rm_index[j]) {
//            j++;
//        } else {
//            res += s[i];
//        }
//    }
//    return res;
//}
//
//vector<int> nextGreaterElements(vector<int>& nums) {
//    vector<int> res;
//    for (int i = 0; i < nums.size(); i++) {
//        bool flag = true;
//        for (int index = 0; index < nums.size(); index++) {
//            if (nums[(i + index)%nums.size()] > nums[i]) {
//                res.push_back(nums[(i + index)%nums.size()]);
//                flag = false;
//            }
//        }
//        if (flag)
//            res.push_back(-1);
//    }
//    return res;
//}
//
//
//void reverse(string &s, int left, int right) {
//    while (left <= right) {
//        char tmp = s[left];
//        s[left] = s[right];
//        s[right] = tmp;
//        left++, right--;
//
//    }
//    return;
//}
//
//string reverseParentheses(string s) {
//    vector<int> index_s;
//    for (int i = 0; i < s.size(); i ++){
//            index_s.push_back(i);
//        else if (s[i] == ')') {
//            int left = s.back();
//            s.pop_back();
//            reverse(s, left, i);
//        }
//    }
//    string res;
//    for (auto item : res) {
//        if (item == '(' or item == ')') {
//            continue;
//        } else {
//            res += item;
//        }
//    }
//    return res;
//}
//
//
//vector<int> nextLargerNodes(ListNode* head) {
//
//}
//
//
//vector<int> nextLargerNodes(ListNode* head) {
//    vector<int> data;
//    vector<int> res;
//    vector<int> large_num;
//    while (head != nullptr) {
//        data.push_back(head->val);
//        head = head->next;
//    }
//    for(int i = data.size()-1; i >=0 ; i--) {
//        while (large_num.size() > 0 && data[i] >= large_num.back()) {
//            large_num.pop_back();
//        }
//        if (large_num.size() == 0) {
//            res.push_back(0);
//            large_num.push_back(data[i]);
//        } else {
//            res.push_back(large_num.back());
//            large_num.push_back(data[i]);
//        }
//    }
//    reverse(res.begin(), res.end());
//    return res;
//}
//
//
//string decodeString(string s) {
//    string res;
//    string tmp;
//    string num = "";
//    vector<char> brackets;
//    for (int i = s.size()-1; i >= 0; i--) {
//        if (s[i] == ']') {
//            brackets.push_back(s[i]);
//        } else if (s[i] == '[') {
//            brackets.pop_back();
//        } else {
//            if (brackets.size() > 0) {
//                tmp
//            }
//        }
//    }
//}
//
//vector<string> split(const string& s, char sp) {
//    vector<string> v;
//    string t;
//    for (auto c : s) {
//        if (c == sp) {
//            if (!t.empty()) {
//                v.push_back(t);
//                t.clear();
//            }
//        } else {
//            t += c;
//        }
//    }
//    if (!t.empty()) v.push_back(t);
//    return v;
//}
//
//
//
//vector<int> exclusiveTime(int n, vector<string>& logs) {
//    vector<string> func;
//    vector<int> res;
//    int last_time = 0;
//    for (auto item : logs) {
//        auto res = split(item, ':');
//        if (res[1] == "start") {
//            func.push_back(res[0]);
//        } else if (res[1] == "end") {
//            if (func.back() == res[0]) {
//                func.pop_back();
//            } else {
//                cout << "error" << endl;
//            }
//        }
//        if (func.size() > 0)
//         res[atoi(func.back().c_str())] += atoi(res[2].c_str()) - last_time;
//
//    }
//    return res;
//}
//
//
//string decodeString(string s) {
//    int num = 0;
//    string res = "";
//    string tmp = "";
//    vector<int> nums_vec;
//    vector<string> tmp_vec;
//    for (auto item: s) {
//        if (s == '[') {
//            nums_vec.push_back(num);
//            tmp_vec.pop_back(tmp);
//            tmp = "";
//        } else if (s == ']') {
//            int num = nums_vec.back();
//            nums_vec.pop_back();
//
//            string tmp_str = ""
//            while (num--) {
//                tmp_str += tmp;
//            }
//            tmp = tmp_str;
//            tmp = tmp_vec.back() + tmp;
//            tmp_vec.pop_back();
//            if (nums_vec.size() == 0) {
//                res += tmp;
//                tmp = "";
//            }
//        } else if (s <= '9' and s >= '0'){
//            num *= 10;
//            num += s - '0';
//        } else {
//            tmp += item;
//        }
//    }
//    return res;
//}


//bool find132pattern(vector<int>& nums) {
//    vector<int> min_nums;
//    if (tmp.size() < 3)
//        return false;
//    int tmp = nums[0];
//    for (int i = 0; i < nums.size(); i++) {
//        tmp = min(nums[i], tmp);
//        min_nums.push_back(tmp);
//    }
//    vector<int> stack;
//    for (int i = nums.size()-1; i > 0; i--) {
//        if (stack.size() == 0) {
//            stack.push_back(nums[i]);
//        } else {
//            if (nums[i] > stack.back()) {
//                while (stack.size() > 0 && stack.back() < min_nums[i]){
//                    stack.pop_back();
//                }
//                if (stack.size() > 0 && stack.back() > min_nums[i])
//                    return true;
//            }
//            else if (nums[i] < stack.back())
//                stack.push_back(nums[i]);
//        }
//    }
//    return false;
//}


//vector<string> permutation(string S) {
//    vector<string> res;
//    for (int i = 0; i < S.size(); i++) {
//        if (i == 0) {
//            res.push_back(""+S[i]);
//        } else {
//            vector<string> new_res;
//            for (auto item: res){
//                for (int j = 0; j < item.size(); j++) {
//                    new_res.push_back(item.substr(0, j) + S[i] + item.substr(j));
//                }
//                new_res.push_back(item + S[i]);
//            }
//            res = new_res;
//        }
//
//    }
//    return res;
//}

//void reverse(string &s, int left, int right) {
//    while (left < right) {
//        if tmp = s[left];
//        s[left] = s[right];
//        s[right] = tmp;
//        left ++;
//        right --;
//    }
//}
//
//string reverseLeftWords(string s, int n) {
//    reverse(0, s.size()-1);
//    reverse(0, s.size()-n);
//    reverse(s.size()-n+1, n-1);
//    return s;
//
//}












int main() {
//    cout << isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
//    vector<vector<int> > a = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
//    cout << Find(7, a);
   	// Complex c1(10, 6), c2(2, 3), c3;
	// c3 = c1 + c2;
	// c3.display();
	printf("hello world");
    return 0;
}