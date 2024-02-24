# -*- coding:utf-8 -*-
class Solution:
    def FindGreatestSumOfSubArray(self, array):
        # write code here
        sumup = None
        data = 0
        for item in array:
            data = max(item,data+item)
            sumup = max(sumup,data) if sumup!=None else data
        return sumup

a = Solution()
a.FindGreatestSumOfSubArray([1,-2,3,10,-4,7,2,-5])