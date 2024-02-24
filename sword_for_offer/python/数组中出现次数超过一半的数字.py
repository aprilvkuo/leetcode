#!/usr/bin/env python
# -*- coding:utf-8 -*-



class Solution:
    def MoreThanHalfNum_Solution(self, numbers):
        # write code here
        if not numbers:
            return 0
        else:
            begin,end = 0, len(numbers)-1
            mid = self.parition(numbers, begin, end)
            target = len(numbers)//2-1
            while mid != target:

                if mid < target:
                    begin = mid+1
                else:
                    end = mid-1
                mid = self.parition(numbers, begin, end)
            length, tmp = len(numbers), numbers[target]
            numbers = [item for item in numbers if item != tmp]
            print(numbers,length,len(numbers))
            return tmp if len(numbers)*2 < length else 0


    def parition(self,numbers,begin,end):
        tmp = numbers[begin]
        left = begin
        for i in range(begin,end+1):
            if numbers[i] <= tmp:
                if i == left:
                    left += 1
                else:
                    numbers[left],numbers[i] = numbers[i],numbers[left]
                    left += 1

        numbers[left-1],numbers[begin] = numbers[begin],numbers[left-1]
        return left-1

a = Solution()
print(a.MoreThanHalfNum_Solution([1,2,3,2,2,2,5,4,2]))