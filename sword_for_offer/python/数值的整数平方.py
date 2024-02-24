# -*- coding:utf-8 -*-
class Solution:
    def Power(self, base, exponent):
        # write code here
        data = 1
        per = base
        exponent,tmp = abs(exponent),exponent
        while exponent:
            size = exponent%2
            exponent /= 2
            if size >0:
                data *= (per*size)
            per = per**2
        return data if tmp >=0 else 1.0/data

a= Solution()
print(a.Power(3,5))