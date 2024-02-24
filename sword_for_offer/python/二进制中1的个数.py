# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1(self, n):
        # write code here
        if n < 0:
            n += 2**32
        cnt = 0
        while n:
            if n & 1:
                cnt += 1
            n = n >> 1
        return cnt

a = Solution()
print(a.NumberOf1(-1))