# -*- coding:utf-8 -*-
class Solution:
    def jumpFloor(self, number):
        a, b = 1, 1
        if number <2:
            return b if number == 1 else 0
        for i in range(1,number):
            a,b = b,a+b
        return b