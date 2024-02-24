# -*- coding:utf-8 -*-
class Solution:
    def PrintMinNumber(self, numbers):
        # write code here
        if not numbers:
            return ""
        numbers = sorted(map(str, numbers),cmp=cmp1)
        con_sum = ''
        for item in numbers:
            con_sum += item
        return int(con_sum)

def cmp1(a,b):
    print(a+b,b+a)
    return -1 if int(a+b) < int(b+a) else 1



a = Solution()
print a.PrintMinNumber([1,2])