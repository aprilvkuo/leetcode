# -*- coding:utf-8 -*-
class Solution:
    def StrToInt(self, s):
        # write code here
        num = 0
        flag = 1
        for i in range(len(s)):
            if i == 0 and (s[i]=='+' or s[i]=='-'):
                flag = 1 if s[i] == '+' else -1
                continue
            if ord(s[i])>ord('9') or ord(s[i])<ord('0'):
                return 0
            else:
                num *= 10
                num += ord(s[i])-ord('0')
        return num*flag

a = Solution()
print a.StrToInt('123')
