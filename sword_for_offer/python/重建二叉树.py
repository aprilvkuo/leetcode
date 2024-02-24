#!/usr/bin/env python
# encoding: utf-8


"""
@author: aprilvkuo
@license: Apache Licence 
@site: http://aprilvkuo.github.io
@software: PyCharm Community Edition
@file: 重建二叉树.py
@time: 2017/8/16 23:54
"""

# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def reConstructBinaryTree(self, pre, tin):
        # write code here
        if len(pre) == 0:
            return None
        else:
            return self.build(pre, tin, 0, 0, len(pre))

    def build(self, pre, tin, begin1, begin2, size):
        if size <= 0:
            return None
        else:
            Node = TreeNode(pre[begin1])
            flag = begin2
            while flag < begin2 + size and tin[flag] != pre[begin1]:
                flag += 1
            leftlen = flag - begin2
            rightlen = size - leftlen - 1
            Node.left = self.build(pre, tin, begin1 + 1, begin2, leftlen)
            Node.right = self.build(pre, tin, begin1 + leftlen + 1, flag+1, rightlen)
            return Node

a = Solution()
a.reConstructBinaryTree([1,2,4,7,3,5,6,8],[4,7,2,1,5,3,8,6])