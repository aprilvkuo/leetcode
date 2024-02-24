# -*- coding:utf-8 -*-
class Solution:
    def reOrderArray(self, array):
        left = -1
        for i in range(len(array)):
            if array[i]%2 == 1:
                if i == 0 or array[i-1]%2 == 1:
                    left += 1
                else:
                    for j in range(i,0,-1):
                        if array[j-1]%2 == 0:
                            array[j],array[j-1] = array[j-1], array[j]
                        else:
                            break
        return array

a = Solution()
print(a.reOrderArray([2,4,6,1,3,5,7]))
