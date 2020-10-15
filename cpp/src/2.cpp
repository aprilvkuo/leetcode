/***************************************************************************
 *
 * Copyright (c) 2019 Baidu.com, Inc. All Rights Reserved
 *
 **************************************************************************/
/**
 * @file    : 2.cpp.py
 * @author  : GuoHongjie 
 * @email   : guohongjie@baidu.com)
 * @date    : 2/9/2019, 5:02:16 PM
 *
 **/

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>


/**
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/**
 * Definition for singly-linked list.
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);
        ListNode *head = result;
        int sum_tmp = 0;
        int carry_tmp = 0;
        while (true){

            sum_tmp = carry_tmp;
            if (l1)
                sum_tmp += l1->val;
            if (l2)
                sum_tmp += l2->val;
            if (sum_tmp == 0 && !l1 && !l2)
                return head->next;
            carry_tmp = 0;
            if (sum_tmp > 10){
                carry_tmp = sum_tmp / 10;
                sum_tmp = sum_tmp % 10;
            }
            result->next = new ListNode(sum_tmp);
            result = result->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
    return head->next;
    }
};