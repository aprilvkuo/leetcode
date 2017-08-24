# http://blog.csdn.net/doc_sgl/article/details/11832965
class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        space = [[(0,0) for _ in (len(matrix[0]))] for _ in (len(matrix))]
        mark = 0
        for i in range(space):
            for j in range(space[0]):
                if matrix[i][j] == 1:
                    if i-1 >=0:
                        space[i][j][0] = space[i-1][j][0] + 1
                    else:
                        space[i][j][0] = 1
                    if j-1 >=0:
                        space[i][j][1] = space[i - 1][j][1] + 1
                    else:
                        space[i][j][1] = 1
        for i in range(space):
            for j in range(space[0]):


    def getspace(self,space,i,j):
        for i in len(space[i][j][1]):
