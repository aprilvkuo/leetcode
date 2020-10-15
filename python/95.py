# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
import copy
class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        # state = [0 for i in range(n+1)]
        # state[0] = 1
        # state[1] = 1
        # result = []
        # for i in range(2,n+1):
        #     for j in range(n):
        #         Node = TreeNode(j+1)
        #         state[i] += state[j]*state[i-j-1]
        # print(state)
        # return state[n]
        if n == 0:
            return []
        data = [i for i in range(1,n+1)]
        result = []
        self.process(None,data,result,0,n)
        return result


    def process(self,node,data,result,cnt,n):

        if len(data) == 0 and cnt == n:
            result.append(node)
            return []

        node_list = []
        for i in range(len(data)):
            if cnt == 0:
                print('result=',len(result))
            tmp,tmp1 = data[i],copy.deepcopy(node)
            node = self.insert(node,tmp)
            if i == len(data)-1:
                node_list.append(node)
            for node in self.process(node, data[:i],result,cnt+1,n):
                self.process(node, data[i+1:],result,cnt+i+1,n)
                node_list.append(node)

            node = tmp1
        return node_list


    def insert(self,Node,data):

        insertNode = TreeNode(data)
        if not Node:
            return insertNode
        tmp = Node

        while tmp:

            if data < tmp.val:
                if not tmp.left:
                    tmp.left = insertNode
                    break
                else:
                    tmp = tmp.left
            else:
                if not tmp.right:
                    tmp.right = insertNode
                    break
                else:
                    tmp = tmp.right

        return Node





a = Solution()
print(len(a.generateTrees(3)))

