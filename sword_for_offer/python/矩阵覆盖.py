# -*- coding:utf-8 -*-
class Solution:
    def rectCover(self, number):
        # write code here
        a, b = 1, 2
        if number <= 2:
            return number if number >0 else 0
        for i in range(2,number):
            a,b = b,a+b
        return b