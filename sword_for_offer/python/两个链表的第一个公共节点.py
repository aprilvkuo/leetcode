# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def FindFirstCommonNode(self, pHead1, pHead2):
        # write code here
        m,n = 0,0
        tmp1,tmp2 = pHead1,pHead2
        while tmp1:
            tmp1 = tmp1.next
            m += 1
        while tmp2:
            tmp2 = tmp2.next
            n += 1
        for i in range(abs(m-n)):
            if m>n:
                pHead1 = pHead1.next
            else:
                pHead2 = pHead2.next
        while pHead1 != pHead2:
            pHead1 = pHead1.next
            pHead2 = pHead2.next
        return pHead1