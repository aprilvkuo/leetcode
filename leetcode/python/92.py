# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        head = dummy 
        for i in range(m-1):
            head = head.next
        start = head.next
        then = start.next
        for i in range(n-m):
            start.next = then.next
            then.next = head.next
            head.next = then
            then = start.next
        
        return dummy.next
                 
"指针，很有技巧性"        