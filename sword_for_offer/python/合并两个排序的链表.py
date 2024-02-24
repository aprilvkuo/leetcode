# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回合并后列表
    def Merge(self, pHead1, pHead2):
        # write code here
        Head = ListNode(0)
        tail = Head
        while pHead1 and pHead2:
            while pHead1 and pHead2 and pHead1.val <= pHead2.val:
                tail.next = pHead1
                tail = tail.next
                pHead1 = pHead1.next
            while pHead1 and pHead2 and pHead2.val <= pHead1.val:
                tail.next = pHead2
                tail = tail.next
                pHead2 = pHead2.next
        tail.next = pHead1 if pHead1 else pHead2
        return Head.next
