# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        heap  = []
        if not root :
            return result
        else:
            while root or heap:
                while root:
                    heap.append(root)
                    root = root.left
                top = heap.pop()
                result.append(top.val)
                root = top.right
        return heap() 