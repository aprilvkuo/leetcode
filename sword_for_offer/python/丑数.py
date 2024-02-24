# -*- coding:utf-8 -*-
class Solution:
    def GetUglyNumber_Solution(self, index):
        # write code here
        if not index:
            return 0
        cnt = 1
        stack = [1]
        while cnt < index:
            begin = 0
            while stack[begin]*5 <= stack[-1]:
                begin += 1
            tmp = begin
            a = stack[begin]*5
            while stack[begin]*3 <= stack[-1]:
                begin += 1
            b = stack[begin]*3
            while stack[begin]*2 <= stack[-1]:
                begin += 1
            c = stack[begin] * 2
            stack = stack[tmp:]
            stack.append(min(a,b,c))
            cnt +=1
        return stack[-1]

a = Solution()
print(a.GetUglyNumber_Solution(3))