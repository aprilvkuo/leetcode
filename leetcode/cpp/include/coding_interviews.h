/*
 * @Author: your name
 * @Date: 2020-11-15 16:29:52
 * @LastEditTime: 2020-11-16 12:41:05
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /leetcode/include/coding_interviews.h
 */
#ifndef LEETCODE_CODING_INTERVIEWS_H
#define LEETCODE_CODING_INTERVIEWS_H

#include "string"
#include "vector"
#include "map"
#include "set"
using namespace std;

namespace leetcode {

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val (0), next(nullptr){}
    ListNode(int x) : val (x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
/*
剑指 Offer 03. 数组中重复的数字
思路： 哈希表
https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/
*/
int findRepeatNumber(vector<int>& nums);
/*
面试题4. 二维数组中的查找
https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
*/
bool findNumberIn2DArray(vector<vector<int>>& array, int target)

/*
剑指 Offer 06. 从尾到头打印链表
思路：  递归
https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/
*/
vector<int> reversePrint(ListNode* head);

/*
剑指 Offer 07. 重建二叉树
思路：  递归
https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
*/
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int p_begin, int p_end, int i_begin, int i_end);

/*
剑指 Offer 10- I. 斐波那契数列
思路： 动态规划
https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/submissions/
*/
int fib(int n);

/*
剑指 Offer 11. 旋转数组的最小数字
思路：二分法，注意画图分析
https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/submissions/
*/
int minArray(vector<int>& numbers);

/*
剑指 Offer 12. 矩阵中的路径
思路:  回溯法
https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
*/
bool exist(vector<vector<char>>& board, string word);
bool exist(vector<vector<char>>& board, string word, int begin, int x, int y);

/*
剑指 Offer 15. 二进制中1的个数
思路: 位操作
https://leetcode-cn.com/problems/er-jin-zhi-zhong-1de-ge-shu-lcof/submissions/
*/
int hammingWeight(uint32_t n);

/*
剑指 Offer 16. 数值的整数次方
思路:  二进制表示
https://leetcode-cn.com/problems/shu-zhi-de-zheng-shu-ci-fang-lcof/submissions/
*/
double myPow(double x, int n);

/*
剑指 Offer 13. 机器人的运动范围
思路:  可以用深度优先 或者广度优先， 这里最普通的遍历了一遍
https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
*/
int movingCount(int m, int n, int k);
bool moving_result(int m, int n, int k);

/*
剑指 Offer 14- I. 剪绳子
思路： 动态规划
https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
*/
int cuttingRope(int n);

/*
剑指 Offer 18. 删除链表的节点
https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/
*/
ListNode* deleteNode(ListNode* head, int val)

/*
剑指 Offer 19. 正则表达式匹配
思路： 动态规划
https://leetcode-cn.com/problems/jian-sheng-zi-lcof/
*/
bool isMatch(string s, string p)

/*
剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
思路： 双指针
https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
*/
vector<int> exchange(vector<int>& nums);

/*
剑指 Offer 22. 链表中倒数第k个节点
思路： 双指针
https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/
*/
ListNode* getKthFromEnd(ListNode* head, int k);
/*
剑指 Offer 24. 反转链表
https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/
*/
ListNode* reverseList(ListNode* head);
/*
剑指 Offer 25. 合并两个排序的链表
https://leetcode-cn.com/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/submissions/
*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

/*
剑指 Offer 26. 树的子结构
https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/submissions/
*/
bool isSubStructure(TreeNode* A, TreeNode* B);
bool isSubStructure1(TreeNode* A, TreeNode* B);

/*
剑指 Offer 27.二叉树的镜像
https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
*/
TreeNode* mirrorTree(TreeNode* root);

/*
剑指 Offer 28. 对称的二叉树
https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
*/
bool isSymmetric(TreeNode* root);
bool isSymmetric(TreeNode* left, TreeNode* right);



};




/*
剑指 Offer 09. 用两个栈实现队列
https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/submissions/
*/
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        v1.push_back(value);
    }
    
    int deleteHead() {
        if (v2.size() == 0) {
            while (v1.size() != 0) {
                v2.push_back(v1.back());
                v1.pop_back();
            }
        }
        int ret = -1;
        if (v2.size() != 0) {
            ret = v2.back();
            v2.pop_back();
        }
        return ret;
    }
private:
    vector<int> v1;
    vector<int> v2;
};

    
}
#endif