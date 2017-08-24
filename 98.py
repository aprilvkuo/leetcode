# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        else:
            value = None
            stack = []
            while root or stack:
                while root :
                    stack.append(root)
                    root = root.left
                tmp = stack.pop()
                if value!=None and value >= tmp.val:
                    return False
                value = tmp.val
                if tmp.right:
                    root = tmp.right
            return True

"""
循环实现中序遍历

需要注意的是，value != None 是必要的，不能用vlaue 来替代， 那样既可以看成value是否为0，value是否为None。

"""