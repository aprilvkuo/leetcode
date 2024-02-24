# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        # write code here
        newHead = None
        root = newHead
        while pHead:
            tmp = pHead.next
            pHead.next = newHead
            newHead = pHead
            pHead = tmp


        return newHead