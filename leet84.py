# 这道题太强了，看http://www.cnblogs.com/ganganloveu/p/4148303.html
# http://blog.csdn.net/doc_sgl/article/details/11805519

class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        mark = 0
        stack = []
        for i in range(len(heights)):
            if not stack:
                stack.append(heights[i])
            else:
                if stack[-1] <= heights[i]:
                    stack.append(heights[i])
                else:
                    for j in range(len(stack)):
                        if stack[-j-1] > heights[i]:
                            mark = max((j + 1) * stack[-j - 1],mark)
                            stack[-j-1] = heights[i]
                        else:
                            break
                    stack.append(heights[i])
        for i in range(len(stack)):
            mark = max(stack[i]*(len(stack)-i),mark)
        return mark


a = Solution()
print(a.largestRectangleArea([2,1,5,6,2,3]))