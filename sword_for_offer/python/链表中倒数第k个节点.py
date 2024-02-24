# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        head_new = head
        for i in range(k):
            head = head.next
            if not head:
                return None
        while head:
            head = head.next
            head_new = head_new.next
        return head_new