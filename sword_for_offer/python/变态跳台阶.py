# -*- coding:utf-8 -*-
class Solution:
    def jumpFloorII(self, number):
        return 2 ** (number+1) if number >0 else 0