# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# 中序遍历，线索二叉树
class Solution(object):
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        prenum = None
        node_change = []
        while root:
            if root.left == None:
                if pre != None and pre.val >= root.val:
                    node_change.append(pre,root)
                pre = root
                root = root.right
            else:
                # 中序遍历的前序节点
                tmp = root.left
                while tmp.right and tmp.right!=root:
                    tmp = tmp.right
                if not tmp.right:
                    #找到前序节点
                    tmp.right = root
                    root = root.left
                else:
                    #左子树已经遍历完了
                    if pre != None and pre.val >= root.val:
                        node_change.append(pre,root)
                    pre = root
                    tmp.right = None # 应该可以不设置为None
                    root = root.right
        if len(node_change) != 2:
            del node_change[1]
            del node_change[1]
        node_change[-1].val,node_change[-2].val = node_change[-2].val,node_change[-1].val




'''
参考的：  yeild的用法，next可以传递默认参数
'''
 class Solution:
# @param root, a tree node
# @return a tree node
    def recoverTree(self, root):
        it = self.isValidBST(root)
        a, b = next(it)
        c = next(it, None)
        if c:
            _, c = c
            a.val, c.val = c.val, a.val
        else:
            a.val, b.val = b.val, a.val
        return root

    def isValidBST(self, root):
        pre, cur, stack = None, root, []
        while stack or cur:
            while cur:
                stack.append(cur)
                cur = cur.left
            s = stack.pop()
            if pre and s.val <= pre.val:
                yield pre, s
            pre, cur = s, s.right
    

                
        
