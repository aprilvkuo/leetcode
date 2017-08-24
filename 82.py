# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = None
        new = ListNode(1)
        begin = new
        while head:
            if head.next and head.val == head.next.val:
                while head.next and head.val == head.next.val:
                    head = head.next
                pre = head
                head = head.next
            else:
                new.next, pre, head = head, head , head.next
                new = new.next
        new.next = None
        return begin.next



#
# class Solution(object):
#     def deleteDuplicates(self, head):
#         """
#         :type head: ListNode
#         :rtype: ListNode
#         """
#         prehead = ListNode(None)
#         prehead.next = head
#         prev,cur = prehead,head
#         while cur:
#             t = cur.val
#             nxt = cur.next
#             if nxt and nxt.val == t:
#                 cur = nxt.next
#                 while cur and cur.val == t:
#                     cur = cur.next
#             else:
#                 prev.next = cur
#                 prev,cur = cur,cur.next
#         prev.next = None
#         return prehead.next
a = Solution()
tmp = ListNode(1)
tmp1 = ListNode(2)
tmp1.next = ListNode(2)
tmp.next = tmp1
b = (a.deleteDuplicates(tmp))
while b:
    print(b.val)
    b = b.next