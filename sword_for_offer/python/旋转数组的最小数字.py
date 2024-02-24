# -*- coding:utf-8 -*-
class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        begin,end = 0,len(rotateArray)-1
        if len(rotateArray) == 0: return 0
        while begin < end-1:
            mid = (begin+end)//2
            if rotateArray[mid] < rotateArray[end]:
                end = mid
            else:
                begin = mid
        return rotateArray[end]

