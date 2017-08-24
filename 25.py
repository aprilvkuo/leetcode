# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
import copy
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
  
        Head = head
        pre = ListNode(0)
        for i in range(k):
            if not head:
                return Head
            head = head.next
        head = Head
        for i in range(k):
            tmp = head.next
            head.next = pre
            pre = head
            head = tmp
        Head.next = self.reverseKGroup(head,k)
        return pre