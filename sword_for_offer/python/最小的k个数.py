# -*- coding:utf-8 -*-
class Solution:
    def GetLeastNumbers_Solution(self, tinput, k):
        # write code here
        if k > len(tinput) or not tinput:
            return []
        begin, end = 0, len(tinput)-1
        mid = self.partition(tinput,begin,end)
        while mid != k-1:
            if mid > k-1:
                end = mid-1
            else:
                begin = mid+1
            mid = self.partition(tinput, begin, end)
        return sorted(tinput[:k])

    def partition(self,numbers,begin,end):
        index,left = numbers[begin],begin
        for i in range(begin,end+1):
            if numbers[i] <= index:
                if i == left:
                    left += 1
                else:
                    numbers[left],numbers[i] = numbers[i],numbers[left]
                    left += 1
        left -= 1
        numbers[left],numbers[begin] = numbers[begin], numbers[left]
        return left