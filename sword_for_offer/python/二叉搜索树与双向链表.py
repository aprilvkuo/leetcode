# -*- coding:utf-8 -*-
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def Convert(self, pRootOfTree):
        # write code here
        stack = []
        if pRootOfTree:
            stack.append(pRootOfTree)
            while pRootOfTree.left:
                pRootOfTree = pRootOfTree.left
                stack.append(pRootOfTree)
            root = TreeNode(0)
            tail = root
            while stack:
                node = stack.pop()
                tail.right,node.left = node,tail
                tail = tail.right
                if node.right:
                    node = node.right
                    stack.append(node)
                    while node.left:
                        node = node.left
                        stack.append(node)
            root = root.right
            root.left = None
            return root
        return pRootOfTree
